#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <vector>
#include "Account.h"
#include "Transaction.h"

// When deposit is called, adds money to balance
void Account::deposit(float moneyDeposit)
{
	// Add money to blance
	balance += moneyDeposit;

	// Add deposit to transaction
	Transaction transaction("Deposit: ", moneyDeposit);
	history.push_back(transaction);

	// Output all transactions
	for (int i = 0; i < history.size(); i++)
	{
		std::cout << history[i].toString();
	}
}

//Placeholders to be overridden in account/savings
void Account::toString()
{
	//Placeholder
}
void Account::withdraw(float moneyWithdraw)
{
	//Placeholder
}
float Account::getBalance()
{
	return 0;
	//Placeholder
}