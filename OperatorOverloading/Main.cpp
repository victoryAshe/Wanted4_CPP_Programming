#include <iostream>

class Point 
{
public:
	Point(int x = 0, int y = 0) :x(x), y(y) {}

	// 덧셈.
	//Point Add(const Point& other)
	//{
	//	return Point(x + other.x, y + other.y);
	//}

	friend Point Add(const Point& left, const Point& right)
	{
		return Point(left.x + right.x, left.y + right.y);
	}

	// 연산자 오버로딩: 멤버함수
	//Point operator+(const Point& other)
	//{
	//	return Point(x + other.x, y + other.y);
	//}

	// 연산자 오버로딩: 비-멤버함수 (friend 필요)
	friend Point operator+(const Point& left, const Point& right)
	{
		return Point(left.x + right.x, left.y + right.y);
	}

	int operator[](int index)
	{
		return array[index];
	}

	int GetValueWithIndex(int index)
	{
		return array[index];
	}

	friend std::ostream& operator<< (std::ostream& os, const Point& point)
	{
		return os << "(" << point.x << ", " << point.y << ")";
	}



public:
	int x = 0;
	int y = 0;
	int array[100] = {};
};

//Point Add(const Point& left, const Point& right)
//{
//	return Point(left.x + right.x, left.y + right.y);
//}

//std::istream&
//std::ostream& operator<< (std::ostream& os, const Point& point)
//{
//	return os << "(" << point.x << ", " << point.y << ")";
//}


// 대입 연산자 overloading 실습용 class
class MyClass
{
public:
	MyClass(int value)
	{
		data = new int(value);
	}

	MyClass& operator= (const MyClass& other)
	{
		if (this != &other)
		{
			delete data;
			data = new int(*other.data);
		}

		return *this;
	}

private:
	int* data;
};

// 배열 접근 연산자 overloading 실습용 class.
class MyArray 
{
public:
	int& operator[](int index)
	{
		return data[index];
	}

private:
	int data[10];
};

int main()
{
	Point p1(1, 1);
	Point p2(5, 5);

	//Point p3(p1.x + p2.x, p1.y + p2.y);
	//Point P3 = p1.Add(p2);
	//Point p3 = Add(p1, p2);
	Point p3 = p1 + p2;
	
	std::cout << p3 << "\n";
	std::cout.operator<<(10).operator<<(20); // 출력 결과: 1020


	return 0;
}