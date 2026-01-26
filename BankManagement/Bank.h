#pragma once

#include "Account/Account.h"
const int MAX_ACCOUNT_SIZE = 100;

class Bank
{
public:
	Bank() = default;
	~Bank() = default;

public:
	void RunBank();
	void QuitBank();

private:
	// 계좌 개설
	void CreateAccount();

	// 입금
	void Deposit();

	// 출금
	void Withdraw();

	// 전체 고객 잔액 조회
	void Inquire();

private:
	Account accounts[MAX_ACCOUNT_SIZE];
	bool isQuit = false;
};

