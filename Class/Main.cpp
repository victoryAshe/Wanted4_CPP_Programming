#include <iostream>
#include "Player.h"

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define DBG_NEW new
#endif

int main()
{
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);

	// Stack Segment: Player instance 생성
	Player player1;
	player1.Move(5,2);

	//Heap Segment에서 생성해보기
	Player* player2 = new Player("Ashe");
	player2->Move(3, 1); 
	// ->: (*player1).Move(3,1); 위 코드는 이 역참조 표현의 축약형이라 할 수 있음. 이 표현은 장황해서 안 쓰임.
	
	// pointer로 instance 생성 시 아래 사항을 필히 지켜야 함.
	delete player2;
	player2 = nullptr;

	std::cin.get();
	return 0;
}