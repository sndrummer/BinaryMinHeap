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


int BinaryMinHeap::getLeftChild(int nodeIndex) const
{
	return 2 * nodeIndex;
}

int BinaryMinHeap::getRightChild(int nodeIndex) const
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
	LOG_DBG("Value inserted at " + std::to_string(index));

	//Step 2 heapify 
	nodeCount++;
	return 0;
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
