#pragma once
#include <iostream>
static const char* FILE_NAME = "Test.txt";
static const char* READ_MODE = "rt"; //rt: read-text mode.
static const char* WRITE_MODE = "wt"; //wt: write-text mode.


// C-Style IO 실습.
class FileIO
{
public:
	// File*: void*
	// file을 다룰 수 있도록 하는 pointer로, file 그 자체는 아님.
	static FILE* OpenFile(const char* PATH, const char* MODE);

	static void CloseFile(FILE* file);

	static void ReadFile();

	static void ReadByBlock();
	
	static void WriteFile(const char* message);

private:
	static size_t FileSize(FILE*& file);
};

