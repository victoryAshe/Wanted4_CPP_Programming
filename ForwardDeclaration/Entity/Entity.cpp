#include "Entity.h"
#include "../Vector.h"
#include <iostream>

Entity::Entity(int x, int y)
{
	position = new Vector();
	position->x = x;
	position->y = y;
}

Entity::Entity(const Entity& other)
{
	std::cout << "copy constructor called.\n";

	// Shallow copy 얕은 복사: 기본 복사 생성자가 해주는 일!

	// 이렇게 복사하면 나중에 댕글링 포인터 문제 발생
	// Dangling: 주인을 잃어버림.
	// => 이미 삭제된 memory 주소에 접근.
	position = other.position;

	/*
	// Deep copy 깊은 복사.
	// 공간 확보
	position = new Vector();

	// 값 복사.
	position->x = other.position->x;
	position->y = other.position->y;
	*/
}

Entity::~Entity()
{
	if (position)
	{
		delete position;
		position = nullptr;
	}
}