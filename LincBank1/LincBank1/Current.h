#pragma once
#include "Account.h"
#include "Transaction.h"


class Current : public Account
{
public:
	float overdraft;

	Current(float openingBalance);

	void toString() override;
	void withdraw(float moneyWithdraw) override;
	float getBalance() override;
};
