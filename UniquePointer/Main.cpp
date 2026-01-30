#include <iostream>
#include <memory> // smar_pointer를 사용하려면 추가.  

class Player
{
public:
	Player()
	{
		std::cout << "생성자 호출.\n";
	}
	~Player()
	{
		std::cout << "소멸자 호출.\n";
	}

	// 이렇게 기본 복사 생성자, 대입 연산자를 아예 접근 못하게 할 때.
	// : 명시적으로 삭제해버리는 것이 최근의 방법.
	Player(const Player& other) = delete;
	Player& operator=(const Player& other) = delete;

private:
	
	// private으로 두는 것은 이전의 방식.
	//Player(const Player& other);
	//
	//Player& operator=(const Player& other)
	//{
	//	return *this;
	//}
};

void Function(std::unique_ptr<Player> player)
{
	std::cout << "Player 받음.\n";
}

void FunctionByRef(std::unique_ptr<Player>& player)
{
	std::cout << "Player 받음.\n";

	// 위험한 코드: 지워버리기가 가능하다!
	Player* rawPointer = player.get();
	delete rawPointer;

	// 이 상태에서 unique_ptr이 delete된 걸 인지하지 못하므로
	// unique_ptr을 참조로 넘기는 코드는 최대한 사용하면 안된다.
}

// 이것도 위와 같이 위험하다.
void FunctionByRaw(Player* player)
{
	std::cout << "Player 받음.\n";
}

// 가장 안전한 방법!!
// 이 경우엔 delete 되지 않는다.
// 사용만 가능.
void FunctionByObjRef(Player& player)
{

}

int main()
{
	/*
	{
		// unique_ptr 객체 선언.
		std::unique_ptr<Player> player
			= std::make_unique<Player>();

		// 아래 코드는 복사생성자를 호출하므로 에러가 뜬다.
		//std::unique_ptr<Player> player2 = player;

		// Move만 가능 
		std::unique_ptr<Player> player2 = nullptr;
		player2 = std::move(player);
	}
	*/
	
	std::unique_ptr<Player> player
		= std::make_unique<Player>();

	// 아래 코드는 불가능한 경우.
	//Function(player);

	// 이 코드는 가능: 만들어서 넘기기. 근데 이렇게는 잘 안쓰임!
	//Function(std::make_unique<Player>());

	// 이렇게는 가능(참조로 넘기기 때문에 실제 복사가 일어나지 않으므로)
	// 그런데 get()을 통해 raw pointer를 얻은 뒤, 
	// delete가 가능하기 때문에 위험한 방법!! 
	// => 지양해야 함.
	//FunctionByRef(player);
	
	// 이것도 위험한 방법. 지양할 것.
	FunctionByRaw(player.get());

	// 역참조로 ref넘기기!
	// !! 권장되는 방법: 이 경우는 안전하다!!
	FunctionByObjRef(*player); 

	// Move: 소유권 이전
	std::unique_ptr<Player> player2 = std::move(player);

	return 0;
}