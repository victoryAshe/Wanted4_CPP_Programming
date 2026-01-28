#include <iostream>

// 함수 Template.
template<typename T>
void Swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

//void Swap(int& a, int& b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}

// 함수 overloading
//void Swap(float& a, float& b)
//{
//	float temp = a;
//	a = b;
//	b = temp;
//}

// Class Template 실습을 위해 추가
template<typename T>
class Data
{
public:
	Data(T newData): data(newData) {}
	void SetData(T newData) { data = newData; }
	T GetData() const { return data; }
private:
	T data;
};

int main()
{
	int a = 10;
	int b = 20;
	//Swap(a, b);
	Swap<int>(a, b);

	float floatA = 10.0f;
	float floatB = 2.0f;
	//Swap(floatA, floatB);
	Swap<float>(floatA, floatB);

	// Class Template 실습을 위해 추가.
	Data<int> data1 = Data<int>(0);
	Data<float>data2 = Data<float>(3.1415F);

	data1.SetData(100);

	std::cout << data1.GetData() << "\n";
	std::cout << data2.GetData() << "\n";

	return 0;
}