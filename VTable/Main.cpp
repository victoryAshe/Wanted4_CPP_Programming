#include <iostream>

/*
*  VTable 알아보기 위해 추가한 Project.
*/

#pragma pack(1)

class Box {
public:
	
	virtual void size() 
	{ 
		std::cout << "box size: " << sizeof(this) <<"\n"; 
	}
	
	int boxHeight = 0;
};

class SquareBox : public Box {
public:
	virtual void size() override 
	{ 
		std::cout << "square box size: " << sizeof(this) << "\n"; 
	}
};


int main()
{
	Box box;
	SquareBox sBox;

	return 0;
}