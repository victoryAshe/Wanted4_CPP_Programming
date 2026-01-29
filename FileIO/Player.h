#pragma once

//// File 변수 기반 pseudo code 의사 코드.
//enum class VariableType
//{
//	Int,
//	Float,
//	Enum,
//	String,
//	Unknown
//};
//
//template<typename T, VariableType Type>
//class Variable
//{
//public:
//	T GetValue();
//	int GetIntValue();
//	float GetFloatValue(); //...
//
//private:
//	char* name nullptr;
//	VariableType type = VariableType::Unknown;
//	VariableType type = Type;
//	void* data = nullptr;
//};


class Player
{
public:
	Player();
	Player(int id, int score, float attack);
	~Player();

	// Serialize to file
	void Serialize(const char* path);

	// Deserialize from file
	void Deserialize(const char* path);

private:
	// Variable idVariable;
	int id = 0;
	int score = 0;
	float attack = 0.0f;
};

