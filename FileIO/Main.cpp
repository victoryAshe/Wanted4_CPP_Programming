#include <iostream>
#include "FileIO.h"
#include "Player.h"
#include <vector>


int main()
{
	// STL 잠시 짚고 넘어가기.
	// Emplace_back은 R-value를 더 잘 지원하던 함수. (Move::이동 시맨틱 지원)
	// 최신 compiler에서는 push_back도 해당 내용을 지원하지만, 위 함수를 쓰는 것이 좋다.
	std::vector<int> array;
	array.push_back(10);
	array.emplace_back(10);

	//FileIO* fileIO = new FileIO();
	//
	//fileIO->ReadFile();
	//
	//fileIO->ReadByBlock();
	//
	//fileIO->WriteFile("String written from program.");

	// File Serialize: 객체를 File에 쓰기.
	//Player player(3, 200, 30.0f);
	//player.Serialize("PlayerData.txt");

	// File Deserialize.
	//Player player;
	//player.Deserialize("PlayerData.txt");

	// 문자열 입출력.
	int score = 100;
	float pi = 3.141592f;

	// buffer에 해당 값을 입력
	char formatString[256] = {};
	sprintf_s(
		formatString,
		256,
		"score=%d pi=%f\n",
		score,
		pi
	);

	// buffer에서 해당 값을 읽기
	int intValue = 0;
	float floatValue = 0.0f;
	sscanf_s(
		formatString,
		"score=%d pi=%f\n",
		&intValue,
		&floatValue
	);

	// buffer의 값을 출력
	puts(formatString);
	std::cout << intValue << ", " << floatValue << "\n";

	
	return 0;
}