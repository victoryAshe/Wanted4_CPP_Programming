#include "Player.h"
#include <iostream>

// ====생성자: 기본값 설정/자원 할당.====
Player::Player()
{
}

Player::Player(const char* inName)
	:x(0), y(0), speed(0)
{
	std::cout << "생성자가 호출되었습니다.\n";

	// 동적 할당 및 문자열 복사.
	// null문자 포함한 길이는 +1 해야함.strlen이 null문자 제외한 길이를 반환하기 때문.
	size_t length = strlen(inName) + 1; 
	name = new char[length];

	// 복사 처리
	strcpy_s(name, length, inName);
}

// ====소멸자: 자원 해제. ====
// ==> UE에서는 자원 해제를 엔진에서 해줘서 할 필요 없음 그러나 신경쓰긴 해야함
Player::~Player()
{
	std::cout << "소멸자가 호출되었습니다.\n";

	// null check
	if (name)
	{
		delete[] name;
		name = nullptr;
	}
}


// Player:: <== Player class 안에 있는.
// :: ==> 범위 지정 연산자.
// 선언만 class 내부에 하고, 구현은 외부에 하는 방법.
void Player::Move(int inX, int inY)
{
	x = inX;
	y = inY;
}