// FunctionPointer.
/*
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
	Operator oper;
	//std::cout << FunctionPointer() << "\n";
	std::cout << Function(10, 20, Add) << "\n";

	return 0;
}
*/


// Functor과 Lambda 실습.
#include <vector>
#include <iostream>
#include <algorithm>
class Greater
{
public:
	// 호출 연산자 overloading.
	bool operator()(int a, int b)
	{
		return a > b;
	}

private:
	// 아래에 기능을 추가하면 상태도 추가로 관리 가능.
};

int main()
{
	std::vector<int> array = {1,2,3,4,5,6,7,8,9,10};

	// Functor instance.
	//Greater greater;

	// sort using functor.
	//std::sort(array.begin(), array.end(), greater);

	// sort using lambda.
	std::sort(
		array.begin(),
		array.end(),
		[](int a, int b)->bool
		{
			return a > b;
		}
	);

	// sort result 출력.
	for (const auto item : array)
	{
		std::cout << item << " ";
	}
	std::cout << "\n";


	// lambda 선언: 무조건 auto로 해야 함!
	auto greater = [](int a, int b)->bool
		{
			return a > b;
		};

	int num1 = 10, num2 = 5;
	bool result = greater(num1, num2);

	// Example. Using lambda_capture
	//auto test = []() {};
	int sum = 0;
	std::for_each(
		array.begin(),
		array.end(),
		[&sum](int item){ sum += item; }
	);
	std::cout << "Sum = " << sum <<"\n";
}