#include <iostream>
#include "Player.h"

int main()
{
	// Player instance 생성(Stack Segment)
	Player player1;
	player1.Move(5,2);

	//Heap Segment에서 생성해보기
	Player* player2 = new Player();
	player2->Move(3, 1); 
	// ->: (*player1).Move(3,1); 위 코드는 이 역참조 표현의 축약형이라 할 수 있음. 이 표현은 장황해서 안 쓰임.
	
	// pointer로 instance 생성 시 아래 사항을 필히 지켜야 함.
	delete player2;
	player2 = nullptr;

	std::cin.get();
	return 0;
}