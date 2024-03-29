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

    explicit BinaryMinHeap(int maxSize);

    ~BinaryMinHeap();

    int getNodeCount() const;

    int getLeftChildIndex(int nodeIndex) const;

    int getRightChildIndex(int nodeIndex) const;

    int getParent(int nodeIndex) const;

    int insert(int value); //return the index of the inserted value

    int deleteMin(); //return the minValue

    friend std::ostream& operator<<(std::ostream& os, const BinaryMinHeap& obj);

private:
    int const HEAD = 1;
    int const DEFAULT_SIZE = 25;
    int nodeCount = 0;
    int* heapArray;
    int arraySize;

    int getArraySize() const;

    int getNextEmptyIndex() const;

    int percolateUp(int index);

    bool hasParent(int index) const;

    int getMin() const;

    void percolateDown();

    int swapParentChild(int parentIndex, int childIndex);

    int getSmallestChildIndex(int index) const;
};
