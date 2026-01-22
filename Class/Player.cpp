#include "Player.h"

// ====생성자: 기본값 설정/자원 할당.====
Player::Player()
{
}

// ====소멸자: 자원 해제. ====
// ==> UE에서는 자원 해제를 엔진에서 해줘서 할 필요 없음
Player::~Player()
{
}


// Player:: <== Player class 안에 있는.
// :: ==> 범위 지정 연산자.
// 선언만 class 내부에 하고, 구현은 외부에 하는 방법.
void Player::Move(int inX, int inY)
{
	x = inX;
	y = inY;
}