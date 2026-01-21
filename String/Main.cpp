#include <iostream>
#include <string>

class Player
{
	//CPP는 함수를 위에 놓고 변수를 아래에. C#과 JAVA는 반대로.
	//public/protected/private
	// =>접근 한정자/ 접근제한자.
	// 접근 가능한 범위를 설정.
public:
	// Constructor 생성자.
	// 객체 생성 시 호출되는 특별한 함수.
	// Return type이 없고, Class 이름과 동일해야만 함.
	Player(const char* inName)
	{
		// 문자열 복사.
		// 1. 저장 공간 확보.
		// => 확보할 공간의 크기를 알아야 함.
		size_t length = strlen(inName) + 1; // null문자 갯수까지 크기 확보
		name = new char[length];

		// 2. 문자열 복사.
		strcpy_s(name, length, inName); //=>memcpy()로 만들어졌음.
	}

	// 소멸자.
	// 객체가 해제될 때 실행.
	~Player()
	{
		if (name != nullptr)
		{
			delete[] name;
			name = nullptr;
		}
	}

private:
	// 문자열 저장 변수.
	char* name = nullptr;

};

int main()
{

	// 문자열: 불변성을 가짐. (기본적으로 변경이 안됨!)
	// => 바꾸려면 기존에 있던 것을 폐기하고 새로 넣을 것으로 교체함.
	auto testString = "Ashe"; // => const char*
	//std::cout << testString << "\n";

	// 문자 배열도 가능
	char buffer[5] = { 'A','s','h', 'e', '\0'};
	//std::cout << buffer << "\n";

	// 객체 기반으로 문자열 사용.
	Player player("Ashe");

	return 0;
}