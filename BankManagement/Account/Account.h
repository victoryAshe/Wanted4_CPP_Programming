#pragma once
class Account
{
public:

	Account() = default;
	Account(int inID, const char* inName);
	~Account();

private:
	// °èÁÂ ¹øÈ£
	int id;

	// °í°´ ÀÌ¸§
	char* name = nullptr;

	// °í°´ÀÇ ÀÜ¾×
	int balance = 0;
};

