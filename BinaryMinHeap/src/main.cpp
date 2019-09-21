
#include "BinaryMinHeap.h"
#include <iostream>


void testHeap()
{
    auto* minHeap = new BinaryMinHeap();

    minHeap->insert(10);
    minHeap->insert(9);
    minHeap->insert(8);
    minHeap->insert(7);
    minHeap->insert(6);
    minHeap->insert(5);
    minHeap->insert(4);
    minHeap->insert(3);
    minHeap->insert(2);
    minHeap->insert(1);


    std::cout << *minHeap << std::endl;
    minHeap->deleteMin();
    std::cout << *minHeap << std::endl;
    minHeap->deleteMin();
    std::cout << *minHeap << std::endl;
    minHeap->deleteMin();
    std::cout << *minHeap << std::endl;
    minHeap->deleteMin();
    std::cout << *minHeap << std::endl;
    minHeap->deleteMin();
    std::cout << *minHeap << std::endl;
    minHeap->deleteMin();
    std::cout << *minHeap << std::endl;
    minHeap->deleteMin();
    std::cout << *minHeap << std::endl;
    minHeap->deleteMin();
    std::cout << *minHeap << std::endl;
    minHeap->deleteMin();
    std::cout << *minHeap << std::endl;
    minHeap->deleteMin();
    std::cout << *minHeap << std::endl;

    std::cout << *minHeap << std::endl;

    delete minHeap;
}

int main(int argc, char* argv[])
{
    testHeap();
    return 0;
}
