#include <iostream>

class Entity
{
	// Visibility: 접근한정자/제한자
public:
	// 원래는 아래와 같이 해서 접근해야 함. => 이게 정답
	int GetX() const { return x; }

	// friend: 외부 함수지만 이 class의 내부 정보에 접근할 수 있게 해주는 것.
	// 멤버(내부) 함수가 아닌 외부 함수에 권한만 주는 것임을 기억할 것.
	// entity.ShowEntity(entity)이렇게 호출하려고 하면 오류남
	// 그냥 편의상 이렇게 작성만 하는 것!!
	friend void ShowEntity(Entity& entity)
	{
		std::cout << entity.x << "," << entity.y << "\n";
	}

	friend void Add(Entity& entity1, Entity& entity2);

	// x,y가 private이지만 전혀 문제없다. 
	// 접근한정자의 private은 같은 class끼리는 접근이 되기때문.
	void Add(Entity& other)
	{
		x + other.x;
		y + other.y;
	}

private:
	int x = 0;
	int y = 0;
};


void Add(Entity& entity1, Entity& entity2)
{
	entity1.x + entity2.x;
	entity1.y + entity2.y;
}

int main()
{
	Entity entity;
	ShowEntity(entity);

	return 0;
}