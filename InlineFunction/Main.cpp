#include <iostream>

// Macro 써보기
//	: 그런데 요즘은 Macro를 지양한다. 
//	( ∵ Macro 중첩 사용 시 문제가 생기기 때문 )
//#define Square(x) ((x) * (x)) 

#define FORCEINLINE __forceinline
FORCEINLINE int Square(int x) { return x * x; }

int main()
{
	int number = Square(10);

	int* p = &number;
	//delete(p);
	//std::cout << p;
	//std::cout << &p;

	return 0;
}