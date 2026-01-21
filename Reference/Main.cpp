#include <iostream>

// Call-By-Value.
//	: 값만 복사해서 호출.
//void Increment(int val) { ++val; }

// Call-By-Reference
//	: 참조에 의한 호출.
//	  참조=주소 => 주소의 값을 복사.
//void Increment(int* value) { ++(*value); }
void Increment(int& val) { ++val; }

// Reference를 반환하는 함수 => Reference 선언에 사용하기
int& IncreaseNumber(int& val) { return ++val; }

void Swap(int& a, int& b)
{
	int temp = a;
	a = b; b = temp;
}

void Swap(int* const a, int* const b)
{
	int temp = *a;
	*a = *b; *b = temp;
}

int main()
{
	//int a = 5;
	//int& ref = a;	// L-Value Reference.
	//ref = 10;

	int number = 10;
	//Increment(number);
	//Increment(&number);
	Increment(number);

	
	int& refNumber = IncreaseNumber(number);
	std::cout << "number: " << number << "\n";
	std::cout << "refNubmer: " << refNumber << "\n";

	std::cin.get();

	return 0;

}