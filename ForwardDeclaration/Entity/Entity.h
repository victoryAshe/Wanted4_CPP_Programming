#pragma once

namespace Wanted
{}

// Forward Declaration
class Vector;
class Entity{
public: 
	Entity() = default;
	Entity(int x, int y);

	// 복사생성자(Copy Constructor).
	Entity(const Entity& other);

	~Entity();

private: 
	Vector* position = nullptr;
};