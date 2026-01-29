#include "Player.h"
#include <iostream>
#include "FileIO.h"

Player::Player()
	:Player(0, 0, 0.0f)
{
}

Player::Player(int id, int score, float attack)
	:id(id), score(score), attack(attack)
{
}

Player::~Player()
{

}

// Serialize (Write file)
void Player::Serialize(const char* path)
{
	FILE* file = FileIO::OpenFile(path, WRITE_MODE);

	//// Make data to save
	//char outputData[256] = {};
	//sprintf_s(
	//	outputData,
	//	256,
	//	"id=%d score=%d attack=%f",
	//	id, score, attack
	//);
	//
	//// Data Á¤¸®
	//size_t length = strlen(outputData);
	//memset(outputData + length, 0, 256 - length);
	//
	//// Write data => file.
	//size_t writtenSize
	//	= fwrite(outputData, sizeof(char), 256, file);
	//

	size_t writtenSize
		= fprintf_s(
			file,
			"id=%d score=%d attack=%f",
			id, score, attack
		);

	FileIO::CloseFile(file);
}

void Player::Deserialize(const char* path)
{
	FILE* file = FileIO::OpenFile(path, READ_MODE);

	size_t readSize = fscanf_s(
		file,
		"id=%d score=%d attack=%d",
		&id, &score, &attack
	);

	FileIO::CloseFile(file);
}
