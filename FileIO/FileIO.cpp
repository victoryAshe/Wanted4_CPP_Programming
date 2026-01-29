#include "FileIO.h"

FILE* FileIO::OpenFile(const char* PATH_NAME, const char* MODE)
{
	FILE* file = nullptr;
	fopen_s(&file, PATH_NAME, MODE);
	//fopen_s(&file, "Main.cpp", "rt"); // => cpp 파일도 열 수 있다~! 아무거나 가능.

	// Failed to read file.
	if (file == nullptr)
	{
		std::cout << "Failed to read file.\n";
		__debugbreak();
	}

	return file;
}

void FileIO::CloseFile(FILE* file)
{
	fclose(file);
	file = nullptr;
}

// Read File.
void FileIO::ReadFile()
{
	FILE* file = OpenFile(FILE_NAME, READ_MODE);

	// Read file.
	char data[1024] = {};
	while (true)
	{
		// if file has no more data: break
		if (fgets(data, 1024, file) == nullptr)
		{
			break;
		}

		std::cout << data;
	}
	std::cout << "\n";

	CloseFile(file);
}

// File 크기 가늠해보기.
size_t FileIO::FileSize(FILE*& file)
{
	// File Size를 가늠해보기
	fseek(file, 0, SEEK_END);
	size_t fileSize = ftell(file);

	std::cout << "FileSize: " << fileSize << "\n";

	// ! File Size 가늠해본 뒤에, 다시 처음부터 읽으려면 FP 되돌려야 함.
	//fseek(file, 0, SEEK_SET);
	rewind(file); // 위의 줄과 기능은 같다.

	return fileSize;
}

// Read by block.
void FileIO::ReadByBlock()
{
	FILE* file = OpenFile(FILE_NAME, READ_MODE);
	size_t fileSize = FileSize(file);

	// space to save read data
	//char buffer[1024] = {};
	char* buffer = new char[fileSize + 1];
	size_t readSize = fread(buffer, sizeof(char), fileSize + 1, file);

	std::cout << "readSize: " << readSize << "\n";
	std::cout << buffer;
	delete[] buffer;

	CloseFile(file);
}

// Write File.
void FileIO::WriteFile(const char* message)
{
	FILE* file = OpenFile(FILE_NAME, WRITE_MODE);

	fputs(message, file);

	CloseFile(file);
}
