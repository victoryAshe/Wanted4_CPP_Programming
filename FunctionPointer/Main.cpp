#include <iostream>
#include <functional>

//typedef int (*Adder)(int a, int b);
//using Adder = int (*)(int a, int b);
using Adder = int (*)(int, int); // 변수명 생략 가능. type만 써줘도 됨.
//using Adder = std::function<int(int, int)>;  // using에 functional 사용

// returnType이 int이고, parameter를 안 받는 함수.
//int Function() { return 10; }

int Add(int a, int b)
{
	return a + b;
}

// using/typedef/function 사용
//int Function(int a, int b, Adder adder) 
//{
//	return adder(a,b); 
//}

// functional 직접 사용
int Function(int a, int b, std::function<int(int,int)> adder)
{
	return adder(a, b);
}

class Operator
{
public:
	// 이건 static으로 쓰면 다른 데서 써지긴 함 => Operator::Add(a,b)
	int Add(int a, int b) 
	{
		return a + b;
	}
};


int main()
{
	// Function Pointer 선언.
	//int (*FunctionPointer) ();
	//FunctionPointer = Function;

	// Function Pointer를 사용한 Call back (간접 호출).
	//std::cout << FunctionPointer() << "\n";
	std::cout << Function(10, 20, Add) << "\n";

	return 0;
}