// debug_new.cpp
// compile by using: cl /EHsc /W4 /D_DEBUG /MDd debug_new.cpp
#include "BinaryMinHeap.h"
#include <cstdlib>
#include <iostream>
//

void testHeap()
{
    BinaryMinHeap* minHeap = new BinaryMinHeap();

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

int main()
{
    testHeap();
    return 0;
}
