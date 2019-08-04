#include "BinaryMinHeap.h"
#include <cmath>


BinaryMinHeap::BinaryMinHeap()
{
	initHeap(DEFAULT_SIZE);
}

BinaryMinHeap::BinaryMinHeap(int maxSize)
{
	//Add one since the first index is reserved for INF 
	initHeap(maxSize + 1);
}


void BinaryMinHeap::initHeap(int maxSize)
{
	this->maxSize = maxSize;
	this->heapArray = new int[maxSize];
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
	return 2 * nodeIndex + 1;
}

int BinaryMinHeap::getRightChild(int nodeIndex) const
{
	return 2 * nodeIndex + 2;
}

int BinaryMinHeap::getParent(int nodeIndex) const
{
	return floor((nodeIndex - 1) / 2);
}
