๐ Account.cpp ๐

#include "AccountHandler.h"
#include "BankingCommonDecl.h"

int main()
{
	AccountHandler manager;
	int choice;

	while (true)
	{
		manager.ShowMenu();
		cout << "์ ํ: ";
		cin >> choice;

		switch (choice)
		{
		case Make:
			manager.MakeAccount();
			break;
		case DEPOSIT:
			manager.DepositMoney();
			break;
		case WITHDRAW:
			manager.WidthdrawMoney();
			break;
		case INQUIRE:
			manager.ShowAllAccInfo();
			break;
		case EXIT:
			return 0;
		default:
			cout << "Illegal selection.." << endl;
			break;
		}
	}

	return 0;
}


๐ AccountHandler.cpp ๐

#include "BankingCommonDecl.h"
#include "AccountHandler.h"
#include "Account.h"
#include "HighCreditAccout.h"
#include "NormalAccount.h"

AccountHandler::AccountHandler() : accNum(0) {}

void AccountHandler::ShowMenu() const
{
	cout << "-----Menu-----" << '\n';
	cout << "1. ๊ณ์ข๊ฐ์ค\n";
	cout << "2. ์ ๊ธ\n";
	cout << "3. ์ถ ๊ธ\n";
	cout << "4. ๊ณ์ข์ ๋ณด ์ ์ฒด ์ถ๋ ฅ\n";
	cout << "5. ํ๋ก๊ทธ๋จ ์ข๋ฃ\n\n";
}

void AccountHandler::MakeAccount()
{
	int sel;
	cout << "[๊ณ์ข์ข๋ฅ์ ํ]" << endl;
	cout << "1.๋ณดํต์๊ธ๊ณ์ข ";
	cout << "2.์ ์ฉ์ ๋ขฐ๊ณ์ข " << endl;
	cout << "์ ํ:  ";
	cin >> sel;

	if (sel == NORMAL)
		MakeNormalAccout();
	else
		MakeCreditAccout();
}

void AccountHandler::MakeNormalAccout()
{
	int id;
	char name[NAME_LEN];
	int balance;
	int interRate;

	cout << "[๋ณดํต์๊ธ๊ณ์ข ๊ฐ์ค]" << endl;
	cout << "๊ณ์ขID: "; cin >> id;
	cout << "์ด ๋ฆ: "; cin >> name;
	cout << "์๊ธ์ก: "; cin >> balance;
	cout << "์ด์์จ: "; cin >> interRate;
	cout << endl;

	accArr[accNum++] = new NormalAccount(id, balance, name, interRate);
}

void AccountHandler::MakeCreditAccout()
{
	int id;
	char name[NAME_LEN];
	int balance;
	int interRate;
	int creditLevel;

	cout << "[๋ณดํต์๊ธ๊ณ์ข ๊ฐ์ค]" << endl;
	cout << "๊ณ์ขID: "; cin >> id;
	cout << "์ด ๋ฆ: "; cin >> name;
	cout << "์๊ธ์ก: "; cin >> balance;
	cout << "์ด์์จ: "; cin >> interRate;
	cout << "์ ์ฉ๋ฑ๊ธ(1toA, 2toB, 3toC): "; cin >> creditLevel;
	cout << endl;

	switch (creditLevel)
	{
	case 1:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_A);
		break;
	case 2:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_B);
		break;
	case 3:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_C);
		break;
	}
}


void AccountHandler::DepositMoney()
{
	int money, id;

	cout << "[์  ๊ธ]\n";
	cout << "๊ณ์ขID: "; cin >> id;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			cout << "์๊ธ์ก: "; cin >> money;
			accArr[i]->Deposit(money);
			cout << "์๊ธ์๋ฃ" << endl << endl;
			return;
		}
	}

	cout << "์ ํจํ์ง ์๋ ID ์๋๋ค.\n\n";
}

void AccountHandler::WidthdrawMoney()
{
	int id, money;

	cout << "[์ถ  ๊ธ]\n";
	cout << "๊ณ์ขID: "; cin >> id;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			cout << "์ถ๊ธ์ก: "; cin >> money;
			if (accArr[i]->Widthdraw(money) == 0)
				cout << "์์ก๋ถ์กฑ\n";
			else
				cout << "์ถ๊ธ์๋ฃ\n\n";

			return;
		}
	}

	cout << "์ ํจํ์ง ์๋ ID ์๋๋ค.\n\n";
}

void AccountHandler::ShowAllAccInfo() const
{
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowAccInfo();
	}
}

AccountHandler::~AccountHandler()
{
	for (int i = 0; i < accNum; i++)
		delete accArr[i];
}


๐ BankingSystemMain.cpp ๐

#include "AccountHandler.h"
#include "BankingCommonDecl.h"

int main()
{
	AccountHandler manager;
	int choice;

	while (true)
	{
		manager.ShowMenu();
		cout << "์ ํ: ";
		cin >> choice;

		switch (choice)
		{
		case Make:
			manager.MakeAccount();
			break;
		case DEPOSIT:
			manager.DepositMoney();
			break;
		case WITHDRAW:
			manager.WidthdrawMoney();
			break;
		case INQUIRE:
			manager.ShowAllAccInfo();
			break;
		case EXIT:
			return 0;
		default:
			cout << "Illegal selection.." << endl;
			break;
		}
	}

	return 0;
}

-------------------------------------------------------
  
๐ Account.h ๐

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

class Account
{
private:
	int accID;      // ์์ด๋
	int balance;    // ์์ก
	char* cusName;  // ๊ณ ๊ฐ ์ด๋ฆ

public:
	Account(int id, int money, char* name);
	Account(Account& copy);

	int GetAccID() const;
	virtual void Deposit(int money);
	int Widthdraw(int money);
	void ShowAccInfo() const;
	~Account();
};

#endif // !__ACCOUNT_H__


๐ AccountHandler.h ๐

#ifndef _ACCOUNT_HANDLER__
#define _ACCOUNT_HANDLER__
#include "Account.h"

class AccountHandler
{
private:
	Account* accArr[100];
	int accNum;
public:
	AccountHandler();

	void ShowMenu() const;       // ๋ฉ๋ด์ธ๋ ฅ
	void MakeAccount();          // ๊ณ์ข๊ฐ์ค์ ์ํ ํจ์
	void DepositMoney();		     // ์     ๊ธ
	void WidthdrawMoney();		   // ์ถ     ๊ธ
	void ShowAllAccInfo() const; // ์์ก์กฐํ
	~AccountHandler();
protected:
	void MakeNormalAccout();   // ๋ณดํต์๊ธ๊ณ์ข ์์ฑ
	void MakeCreditAccout();   // ์ ์ฉ์ ๋ขฐ๊ณ์ข ์์ฑ
};

#endif // _ACCOUNT_HANDLER__


๐ BankingCommonDecl.h ๐

#ifndef __BANKING_COMMON_H__
#define __BANKING_COMMON_H__
#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20;

enum { Make = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };
enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 };
enum { NORMAL = 1, CREDIT = 2 };

#endif // !__BANKING_COMMON_H__


๐ HighCreditAccout.h ๐

#ifndef __HIGHTCREDIT_ACCOUNT__
#define __HIGHTCREDIT_ACCOUNT__
#include "NormalAccount.h"

class HighCreditAccount : public NormalAccount // ์ ์ฉ์ ๋ขฐ๊ณ์ข
{
private:
	int speicalRate;
public:
	HighCreditAccount(int id, int money, char* name, int interest, int rank)
		: NormalAccount(id, money, name, interest), speicalRate(rank)
	{}

	virtual void Deposit(int money)
	{
		NormalAccount::Deposit(money);   // ์๊ธ๊ณผ ์ด์์ถ๊ฐ
		Account::Deposit((money * (speicalRate / 100.0))); // ํน๋ณ์ด์์ถ๊ฐ
	}
};

#endif // !__HIGHTCREDIT_ACCOUNT__


๐ NormalAccount.h ๐

#ifndef __NORMAL__ACCOUNT_H__
#define __NORMAL__ACCOUNT_H__
#include "Account.h"

class NormalAccount : public Account     // ๋ณดํต์๊ธ๊ณ์ข
{
private:
	int interRate;
public:
	NormalAccount(int id, int money, char* name, int interest)
		: Account(id, money, name), interRate(interest)
	{}

	virtual void Deposit(int money)
	{
		Account::Deposit(money); // ์๊ธ์ถ๊ฐ
		Account::Deposit((money * (interRate / 100.0))); // ์ด์์ถ๊ฐ
	}
};

#endif // !__NORMAL__ACCOUNT_H__
