#include <iostream>

// MACRO 안에서 어떤 항목 앞에 #을 붙이면
// 무조건으로 문자열로 변환함!
#define NAME(x) #x

#define PURE = 0

// 순수 가상 함수를 가지는 class.
class NameInterface
{
public:
	// Pure virtual void 순수 가상 함수: 선언만 둔다.
	//virtual const char* GetName() const PURE;
	virtual const char* GetName() const = 0;
};

class Entity: public NameInterface
{
public:
	//const char* GetName() const { return NAME("Entity"); }
	//const char* GetName() const { return NAME(10); }

	virtual const char* GetName() const { return NAME(Entity); }
};

class Player : public NameInterface
{
public:
	Player(const char* name)
	{
		// 내부의 name 설정.
		// 크기
		size_t length = strlen(name) + 1;
		// 할당
		this->name = new char[length];
		// 문자열 값 복사
		strcpy_s(this->name, length, name);
	}

	~Player()
	{
		if (name)
		{
			delete[] name;
			name = nullptr;
		}
	}

	virtual const char* GetName() const override { return name; }

private:
	char* name = nullptr;
};


int main()
{
	Entity* entity = new Entity();
	std::cout << entity->GetName() << "\n";

	Player* player = new Player("Ashe");
	//Entity* player = new Player("Ashe");
	std::cout << player->GetName() << "\n";

	Entity* entities[250] = {};
	entities[0] = entity;
	//entities[1] = player; // up-casting 되었으므로 가능

	delete player;
	delete entity;

	return 0;
}