#include "BinaryMinHeap.h"
#include <cmath>
#include <sstream>
#include "Logger.h"

#define NEG_INF INT_MIN

BinaryMinHeap::BinaryMinHeap()
{
	initHeap(DEFAULT_SIZE);
}

BinaryMinHeap::BinaryMinHeap(int maxSize)
{
	initHeap(maxSize);
}

void BinaryMinHeap::initHeap(int maxSize)
{
	LOG_DBG("Heap created");
	// Add one since the first index is reserved for INF
	int size = maxSize + 1;
	this->heapArray = new int[size];
	heapArray[0] = NEG_INF;
	this->arraySize = size;
}

BinaryMinHeap::~BinaryMinHeap()
{
	delete heapArray;
}

int BinaryMinHeap::getNodeCount() const
{
	return nodeCount;
}


int BinaryMinHeap::getLeftChildIndex(int nodeIndex) const
{
	return 2 * nodeIndex;
}

int BinaryMinHeap::getRightChildIndex(int nodeIndex) const
{
	return 2 * nodeIndex + 1;
}

int BinaryMinHeap::getParent(int nodeIndex) const
{
	return int(floor((nodeIndex) / 2));
}

int BinaryMinHeap::getArraySize() const
{
	return arraySize;
}

/**
 * Return the index that the node is inserted at
 */
int BinaryMinHeap::insert(int value)
{
	//Step 1 is place at the end of the array
	if (getNextEmptyIndex() >= getArraySize())
	{
		LOG_ERR("Tried to insert more than max size of the heap!");
		return -1;
	}
	int index = getNextEmptyIndex();
	heapArray[index] = value;
	LOG_DBG("Value " + std::to_string(value) + " inserted at " + std::to_string(index));

	//Step 2 percolate up
	index = percolateUp(index);

	nodeCount++;
	return index;
}


int BinaryMinHeap::deleteMin()
{
	//1. swap the smallest and the last position
	int min = getMin();
	heapArray[1] = heapArray[nodeCount];

	//Delete the last element
	heapArray[nodeCount] = NULL;
	nodeCount--;

	//2. percolate down

	return min;
}


void BinaryMinHeap::percolateDown()
{
	int curIndex = 0;
	while (curIndex < nodeCount)
	{
		int leftChild = getLeftChildIndex(curIndex);
		int rightChild = getRightChildIndex(curIndex);

		int parentVal = heapArray[curIndex];

		int leftChildVal = heapArray[leftChild];
		int rightChildVal = heapArray[rightChild];

		if (leftChildVal < parentVal)
		{
			curIndex = swapParentChild(curIndex, leftChild);
		}
		else if (rightChildVal < parentVal)
		{
			curIndex = swapParentChild(curIndex, rightChild);
		}
		else { return; }
	}
}


int BinaryMinHeap::swapParentChild(int parentIndex, int childIndex)
{
	int parentVal = heapArray[parentIndex];
	heapArray[parentIndex] = childIndex;
	heapArray[childIndex] = parentVal;

	return childIndex;
}

int BinaryMinHeap::getMin() const
{
	return heapArray[1];
}

int BinaryMinHeap::percolateUp(int index)
{
	int curIndex = index;

	int finalIndex = index;

	while (hasParent(curIndex))
	{
		int parentIndex = getParent(curIndex);

		int childVal = heapArray[curIndex];
		int parentVal = heapArray[parentIndex];

		if (childVal < parentVal)
		{
			heapArray[parentIndex] = childVal;
			heapArray[curIndex] = parentVal;

			finalIndex = curIndex;
			curIndex = parentIndex; //go up
			continue;
		}
		break;
	}

	return finalIndex;
}


bool BinaryMinHeap::hasParent(int index)
{
	return getParent(index) > 0;
}

int BinaryMinHeap::getNextEmptyIndex() const
{
	return nodeCount + 1;
}


std::ostream& operator<<(std::ostream& os, const BinaryMinHeap& obj)
{
	int* heapArray = obj.heapArray;
	std::stringstream ss;
	ss << "[ ";
	for (int i = 0; i < obj.getNextEmptyIndex(); ++i)
	{
		ss << heapArray[i] << " ";
	}
	ss << "]";

	return os
		<< "Heap:"
		<< "\n\tnodeCount: " << obj.nodeCount
		<< "\n\theapArray: " << ss.str()
		<< "\n\tarraySize: " << obj.arraySize;
}
