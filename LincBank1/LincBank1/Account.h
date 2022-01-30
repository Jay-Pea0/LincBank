#pragma once
#include "Transaction.h"


class Account
{
protected:
	float balance;
	std::vector<Transaction> history;
public:
	void deposit(float moneyDeposit);
	virtual float getBalance();
	virtual void toString();
	virtual void withdraw(float moneyWithdraw);
	

};

