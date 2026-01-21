#include <iostream>

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define DBG_NEW new
#endif

void DeletePointer(void* (&ptr))
{
	if (ptr != nullptr)
	{
		delete ptr;
		ptr = nullptr;
	}
}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// TODO: Memory Leak 의도적으로 발생시키기
	int* p = DBG_NEW int;

	// 동적 할당
	//char* buffer = new char[10];

	void* pointer = new int;
	DeletePointer(pointer);

	delete(pointer);

	if (pointer != nullptr)
	{
		std::cout << "Pointer is not null.\n";
	}
	else
	{
		std::cout << "Pointer is null.\n";
	}

	std::cin.get();
	return 0;
}