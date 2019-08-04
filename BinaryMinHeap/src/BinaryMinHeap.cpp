#include "BinaryMinHeap.h"
#include <cmath>
#include "Logger.h"

#ifdef _DEBUG
#define LOG_DBG(x) (Logger::log_debug(x))

#else
#define LOG_DBG(x)
#endif

#define LOG_ERR(x) (Logger::log_error(x))
#define LOG_INFO(x) (Logger::log_info(x))

BinaryMinHeap::BinaryMinHeap()
{
	LOG_DBG("Hello World");
	this->arraySize = DEFAULT_SIZE;
	this->heapArray = new int[DEFAULT_SIZE];
}

BinaryMinHeap::BinaryMinHeap(int maxSize)
{
	//Add one since the first index is reserved for INF 
	this->arraySize = maxSize + 1;
	this->heapArray = new int[maxSize + 1];
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

int BinaryMinHeap::insert(int value)
{
	//Step 1 is place at the end of the array
	heapArray[getNextEmptyIndex()] = value;
	//Step 2 heapify 

	return 0;
}


int BinaryMinHeap::getNextEmptyIndex() const
{
	return nodeCount + 1;
}
