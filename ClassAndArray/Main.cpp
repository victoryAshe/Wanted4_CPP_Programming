#include <iostream>

// class.
class Entity
{
public:
	Entity()
	{
		std::cout << "Constructor called.\n";
	}

	~Entity() = default;

	// 함수 끝에 const 지정 시,
	// 함수 본문에서 객체 내부의 값을 변경할 수 없음.
	// const는 적극 권장되는 문법이므로, 많이 써볼 것.
	void ShowName() const
	{
		std::cout << "Entity.\n";
	}

	const Entity* GetSelf() const
	{
		// this는 자기 자신을 가리키는 pointer.
		return this;
	}
};

// C-style에서 아래처럼 실행됨
void ShowName(Entity* entity)
{
	std::cout << "Entity.\n";
}

void SafeDelete(Entity**& entity)
{
	delete entity;
	entity = nullptr;
}


int main()
{
	//// === 면접문제 소개 ===
	//// ShowName이 잘 호출되는 것을 볼 수 있음. =>why?
	//Entity* entity = nullptr;
	//entity->ShowName();
	//// ShowName(entity); // Compiler가 C-style로 문법을 바꾸면서 이와 같이 실행됨
	//// ShowName에서 Entity 내 다른 변수를 호출/제어하는 것이라면 오류가 나겠으나,
	//// 함수 내에서 정해둔 문자열을 출력하는 것이므로 문제 없이 실행된다.
	//// ===================
	//
	//const int count = 5;
	//Entity entities[count];
	//
	//// Range-Based Loop ( foreach )
	//// 아래와 같이 const를 붙이면 &로 불러와도 값이 바뀌지 않는다.
	//// 이 상태에서 객체의 함수를 불러오려면 함수에도 끝에도 const 지정해야함.
	//for (const Entity& entity : entities)
	//{
	//	entity.ShowName();
	//}

	const int count = 5;
	Entity* entities[count] = {};
	//memset(entities, 0, sizeof(Entity*) * count);
	
	for (int ix = 0; ix < count; ++ix)
	{
		entities[ix] = new Entity();
	}
	
	//for (Entity* entity : entities)
	//{
	//	//SafeDelete(entity);
	//	delete entity;
	//	entity = nullptr;
	//}

	// 아래 두 출력값은 같다.
	Entity* entity = new Entity();
	std::cout << entity << "\n";
	std::cout << entity->GetSelf() << "\n";
	
	delete entity;

	return 0;
}