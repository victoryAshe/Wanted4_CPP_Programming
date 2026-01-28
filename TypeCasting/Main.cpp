#include <iostream>

class A {
public:  void Test() {};
};
class B: public A {};
class C {};

void PrintString(char* string)
{
	std::cout << string << "\n";
}

int main()
{
	// const_cast: const char* => char*
	const char* name = "Ashe";
	PrintString(const_cast<char*>(name));

	// C-style
	int number = 10;
	float floatNumber1 = (float)number;

	// static_cast: int => float
	float floatNumber2 = static_cast<float>(number);

	// static_cast: A => B (down-casting: 위험! 하면 안됨.)
	A* a = new A();
	B* b1 = static_cast<B*>(a);

	// reinterpret_cast: A => B, A => C (static_cast보다 더 위험. 이렇게는 안 쓰인다.)
	B* b2 = static_cast<B*>(a);
	C* c = reinterpret_cast<C*>(a);

	// dynamic_cast: vTable을 사용하므로, 변환하려는 대상에 virtual 함수가 있어야 사용 가능.
	// => runtime-type check에서 해당 개체는 실제로 A. 
	// => down-cast로 확인되어 형변환 통과 안됨!
	// => b3 is nullptr.
	// => 만약 A* a = new B()로 생성했으면 up-cast => down-cast이므로 가능!
	//B* b3 = dynamic_cast<B*>(a);

	const type_info& aInfo = typeid(a);
	const type_info& bInfo = typeid(b1);
	if (aInfo == bInfo)
	{
		std::cout << "Same";
	}
	std::cout << aInfo.name() << " \n" << aInfo.raw_name();


	delete a;
	return 0;
}