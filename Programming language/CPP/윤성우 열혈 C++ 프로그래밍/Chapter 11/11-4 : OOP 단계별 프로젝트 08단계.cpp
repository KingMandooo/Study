π Account.h π

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

class Account
{
private:
	int accID;     
	int balance;   
	char* cusName;  

public:
	Account(int id, int money, char* name);
	Account(Account& copy);
	Account& operator=(const Account& ref);  // λμμ°μ°μ μ€λ²λ‘λ©

	int GetAccID() const;
	virtual void Deposit(int money);
	int Widthdraw(int money);
	void ShowAccInfo() const;
	~Account();
};

#endif // !__ACCOUNT_H__


π Account.cpp π

#include <iostream>
#include "Account.h"
using namespace std;

Account::Account(int id, int money, char* name) : accID(id), balance(money)
{
	cusName = new char[strlen(name) + 1];
	strcpy(cusName, name);
}

Account::Account(Account& copy) : accID(copy.accID), balance(copy.balance)
{
	cusName = new char[strlen(copy.cusName) + 1];
	strcpy(cusName, copy.cusName);
}

Account& Account::operator=(const Account& ref)   // λμμ°μ°μ μ€λ²λ‘λ©
{
	accID = ref.accID;
	balance = ref.balance;

	delete[] cusName;
	cusName = new char[strlen(ref.cusName) + 1];
	strcpy(cusName, ref.cusName);
	return *this;
}

int Account::GetAccID() const { return accID; }

void Account::Deposit(int money)   
{
	balance += money;
}

int Account::Widthdraw(int money)  
{
	if (balance < money)
		return 0;

	balance -= money;
	return money;
}

void Account::ShowAccInfo() const
{
	cout << "κ³μ’ID: " << accID << endl;
	cout << "μ΄ λ¦: " << cusName << endl;
	cout << "μκΈμ‘: " << balance << endl << endl;
}

Account::~Account()
{
	delete[] cusName;
}


π AccountHandler.h π

#ifndef _ACCOUNT_HANDLER__
#define _ACCOUNT_HANDLER__
#include "Account.h"
#include "AccountArray.h"

class AccountHandler
{
private:
	BoundCheckAccountPtrArray accArr;   // λ³κ²½λ λΆλΆ
	int accNum;
public:
	AccountHandler();

	void ShowMenu() const;     
	void MakeAccount();          
	void DepositMoney();		     
	void WidthdrawMoney();		 
	void ShowAllAccInfo() const; 
	~AccountHandler();
protected:
	void MakeNormalAccout();   
	void MakeCreditAccout();  
};

#endif // _ACCOUNT_HANDLER__


π AccountArray.h π

#ifndef __ACCOUN_ARRAY_H__
#define __ACCOUN_ARRAY_H__

#include "Account.h"
typedef Account* ACCOUNT_PTR;

class BoundCheckAccountPtrArray
{
private:
	ACCOUNT_PTR* arr;
	int arrlen;
	BoundCheckAccountPtrArray(const BoundCheckAccountPtrArray& arr) {}
	BoundCheckAccountPtrArray& operator=(const BoundCheckAccountPtrArray& arr) {}

public:
	BoundCheckAccountPtrArray(int len = 100);
	ACCOUNT_PTR& operator[] (int idx);
	ACCOUNT_PTR operator[] (int idx) const;
	int GetArrLen() const;
	~BoundCheckAccountPtrArray();
};
#endif


π AccountArray.cpp π

#include "BankingCommonDecl.h"
#include "AccountArray.h"

BoundCheckAccountPtrArray::BoundCheckAccountPtrArray(int len) : arrlen(len)
{
	arr = new ACCOUNT_PTR[len];
}

ACCOUNT_PTR& BoundCheckAccountPtrArray::operator[](int idx)
{
	if (idx < 0 || idx >= arrlen)
	{
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return arr[idx];
}

ACCOUNT_PTR BoundCheckAccountPtrArray::operator[](int idx) const
{
	if (idx < 0 || idx >= arrlen)
	{
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return arr[idx];
}

int BoundCheckAccountPtrArray::GetArrLen() const
{
	return arrlen;
}

BoundCheckAccountPtrArray::~BoundCheckAccountPtrArray()
{
	delete[] arr;
}
