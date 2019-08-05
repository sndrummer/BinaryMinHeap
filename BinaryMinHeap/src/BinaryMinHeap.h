#pragma once
#include <ostream>

/**
 * Binary Min Heap
 * Heap where the parent key is less than or equal to the two child keys are called min - heaps.
 * Binary Heaps are good ways of implementing priority queues
 */

class BinaryMinHeap
{
public:
	BinaryMinHeap();
	BinaryMinHeap(int maxSize);
	~BinaryMinHeap();
	int getNodeCount() const;
	int getLeftChild(int nodeIndex) const;
	int getRightChild(int nodeIndex) const;
	int getParent(int nodeIndex) const;

	int insert(int value); //return it's final index


	friend std::ostream& operator<<(std::ostream& os, const BinaryMinHeap& obj);

private:
	int static const DEFAULT_SIZE = 25;
	int nodeCount = 0;
	int* heapArray;
	int arraySize;
	void initHeap(int maxSize);
	int getArraySize() const;
	int getNextEmptyIndex() const;
};
