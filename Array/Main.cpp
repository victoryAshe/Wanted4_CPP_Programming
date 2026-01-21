#include <iostream>
#include <cstring>

void PrintArray(int* array, int length)
{
	for (int ix = 0; ix < length; ix++) std::cout << array[ix] << "\n";
}

int main()
{
	// 배열 선언
	int array[10];
	memset(array, 0, sizeof(int) * 10);

	int* arrayPointer = array;
	arrayPointer[1] = 20;
	*(arrayPointer + 1) = 20;
	PrintArray(array, 10);

	// =====================================================
	int example[5];
	int length = sizeof(example) / sizeof(example[0]);
	int* ptr = example;
	*(ptr + 2) = 20;
	*(int*)((char*)ptr + (4 * 2)) = 20;


	// =====================================================
	// 배열의 동적 할당
	int* dynamicArray = new int[10];
	for (int i = 0; i < 10; i++) dynamicArray[i] = i + 1;
	//해제
	delete[] dynamicArray;

	// =====================================================
	std::cin.get();

	return 0;
}