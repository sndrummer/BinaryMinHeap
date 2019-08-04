#pragma once

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

private:
	void initHeap(int maxSize);
	int static const DEFAULT_SIZE = 25;
	int nodeCount = 0;
	int maxSize;
	int* heapArray;
};

