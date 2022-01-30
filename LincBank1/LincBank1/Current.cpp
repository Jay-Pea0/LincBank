#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <vector>
#include "Account.h"
#include "Current.h"
#include "Transaction.h"



// Current Class


//Constructor sets balance to opening balance
Current::Current(float openingBalance)
{
	std::cout << "Current Account Created" << std::endl;
	balance = openingBalance;
	overdraft = 500;


	Transaction transaction("Initial Deposit: ", openingBalance);
	history.push_back(transaction);
	std::cout << history[0].toString();
}

//Return balance and overdraft for withdrawl calulations
float Current::getBalance()
{
	return (balance + overdraft);
}


// Returns information about the account
void Current::toString()
{
	std::cout <<  "Current Account\nBalance: " + std::to_string(balance) + "\nOverdraft: " + std::to_string(overdraft) + "\nTransaction History: \n";	
	// Output all transactions
	for (int i = 0; i < history.size(); i++)
	{
		std::cout << "\t" << history[i].toString();
	}
}


// Withdraws money from account
void Current::withdraw(float moneyWithdraw) 
{
	// If withdrawing more than balance, balance = 0 and take remaining away from overdraft
	if ((moneyWithdraw > balance) and (moneyWithdraw< (balance+overdraft)))
	{
		overdraft = overdraft - (moneyWithdraw - balance);
		balance = 0;


		// Add Withdrawl to transaction
		Transaction transaction("Withdrawal: ", moneyWithdraw);
		history.push_back(transaction);

		// Output all transactions
		for (int i = 0; i < history.size(); i++)
		{
			std::cout << history[i].toString();
		}

	}
	//If there's enough in balance to withdraw, withdraw from balance
	else if (balance >= moneyWithdraw)
	{
		balance -= moneyWithdraw;


		// Add Withdrawl to transaction
		Transaction transaction("Withdrawl: ", moneyWithdraw);
		history.push_back(transaction);

		// Output all transactions
		for (int i = 0; i < history.size(); i++)
		{
			std::cout << history[i].toString();
		}
	}
	//otherwise, Output errror
	else
	{
		std::cout << "Not enough money in account, please withdraw less" << std::endl;
	}

}