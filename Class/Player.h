#pragma once // => 중복 include 방지 구문 (compiler 구문).

// 클래스 추가.
class Player {
	// 접근 한정자/접근 제한자.
	// class 내부 속성을 어디까지 노출시킬지 결정.
	// public/protected /private
	// 공개  /상속계층까지/스스로만.

public:
	// =======공개 함수(Method) => Message라고 부름(OOP에서 이렇게 부름)=======

	// ====생성자.====
	// Parameter를 받지 않는 생성자 = 기본 생성자. => 생성자를 아예 안 만들면 Compiler가 하나 만들어줌
	// 만약 Parameter를 받는 생성자를 하나라도 만들면 기본 생성자 안 만들어줌.
	//Player() = default; // 아무 작동을 지시하지 않는다면 default라고 쓸 수 있음!! 이게 {}만 쓰는 것보다 깔끔해보인다.
	Player();

	// ====소멸자.====
	~Player();

	// ====Setter: Set함수====
	//inline void SetX(const int inX) { if (inX < 0) return;  x = inX; }
	//inline void SetY(const int inY) { if (inY < 0) return;  y = inY; }
	//inline void SetSpeed(const int inSpeed) { if (inSpeed < 0) return;  speed = inSpeed; }


	// ====class 조작 함수.====
	void Move(int inX, int inY);

	// ====Getter: Get함수====
	//inline int GetX() const { return x; }

private:


	int x = 0;
	int y = 0;
	int speed = 0;
};