#include <iostream>
#include "Entity.h"

void TestFunction(Entity entity)
{
	std::cout << "TestFunction.\n";
}

int main()
{
	Entity entity(10, 20);
	Entity entity2(entity);
	Entity entity3 = entity2;

	TestFunction(entity3);

	return 0;
}