// debug_new.cpp
// compile by using: cl /EHsc /W4 /D_DEBUG /MDd debug_new.cpp
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>
#include "BinaryMinHeap.h"
#include <iostream>
//
#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define DBG_NEW new
#endif

void testHeap()
{
	BinaryMinHeap* minHeap = DBG_NEW BinaryMinHeap();

	delete minHeap;
}

int main(int argc, char* argv[])
{
	BinaryMinHeap* minHeap = DBG_NEW BinaryMinHeap();
	delete minHeap;


	_CrtDumpMemoryLeaks();
	return 0;
}
