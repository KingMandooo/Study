
๐ ๋ด ์ฝ๋ ๐

#include <iostream>
#include <cstring>
using namespace std;

void ShowMenu();       // ๋ฉ๋ด์ธ๋ ฅ
void MakeAccount();    // ๊ณ์ข๊ฐ์ค์ ์ํ ํจ์
void DepositMoney();   // ์     ๊ธ
void WidthdrawMoney(); // ์ถ     ๊ธ
void ShowAllAccInfo(); // ์์ก์กฐํ

enum { Make = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

class Account
{
private:
	int accID;      // ์์ด๋
	int balance;    // ์์ก
	char* cusName;  // ๊ณ ๊ฐ ์ด๋ฆ

public:
	Account(int id, int money, char* name) : accID(id), balance(money)
	{
		int len = strlen(name) + 1;
		cusName = new char[len];
		strcpy(cusName, name);
	}

	bool DepositMoney(int id)
	{
		if (accID == id)
		{
			int money;

			cout << "์๊ธ์ก: "; cin >> money;
			balance += money;

			cout << "์๊ธ์๋ฃ\n\n";
			return true;
		}

		return false;
	}

	bool Widthdraw(int id)
	{
		int money;

		if (accID == id)
		{
			cout << "์ถ๊ธ์ก: "; cin >> money;

			if (balance < money)
			{
				cout << "์์ก๋ถ์กฑ\n";
				return true;
			}
			else
			{
				balance -= money;

				cout << "์ถ๊ธ์๋ฃ\n\n";
				return true;
			}
		}
		
		return false;
	}

	void ShowAccInfo()
	{
		cout << "๊ณ์ขID: " << accID << endl;
		cout << "์ด ๋ฆ: " << cusName << endl;
		cout << "์๊ธ์ก: " << balance << endl << endl;
	}

	~Account()
	{
		delete[] cusName;
		//delete this;
	}
};

Account* accArr[100];
int accNum = 0;

int main()
{
	int choice;

	while (true)
	{
		ShowMenu();
		cout << "์ ํ: ";
		cin >> choice;

		switch (choice)
		{
		case Make:MakeAccount(); break;
		case DEPOSIT:DepositMoney(); break;
		case WITHDRAW:WidthdrawMoney(); break;
		case INQUIRE:ShowAllAccInfo(); break;
		case EXIT: return 0;
		default: cout << "Illegal selection.." << endl; break;
		}
	}

	return 0;
}

void ShowMenu()
{
	cout << "-----Menu-----" << '\n';
	cout << "1. ๊ณ์ข๊ฐ์ค\n";
	cout << "2. ์ ๊ธ\n";
	cout << "3. ์ถ ๊ธ\n";
	cout << "4. ๊ณ์ข์ ๋ณด ์ ์ฒด ์ถ๋ ฅ\n";
	cout << "5. ํ๋ก๊ทธ๋จ ์ข๋ฃ\n\n";
}

void MakeAccount()
{
	int id, money;
	char name[50];

	cout << "[๊ณ์ข๊ฐ์ค]\n";
	cout << "๊ณ์ขID: ";
	cin >> id;
	cout << "์ด ๋ฆ: ";
	cin >> name;
	cout << "์๊ธ์ก: ";
	cin >> money;

	accArr[accNum] = new Account(id, money, name);  // ๋์ ํ ๋น   (์์ฑํ ๊ณ์ข ๊ฐ์ฒด๋ ํด์ (delete)๋ฅผ ์ ์ํด์ฃผ์ง..??
	accNum++;
	cout << endl;
}

void DepositMoney()
{
	int id;

	cout << "[์  ๊ธ]\n";
	cout << "๊ณ์ขID: "; cin >> id;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->DepositMoney(id))
			return;
	}

	cout << "์ ํจํ์ง ์๋ ID ์๋๋ค.\n\n";    
}

void WidthdrawMoney()
{
	int id;

	cout << "[์ถ  ๊ธ]\n";
	cout << "๊ณ์ขID: "; cin >> id;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->Widthdraw(id))
			return;
	}

	cout << "์ ํจํ์ง ์๋ ID ์๋๋ค.\n\n";
}

void ShowAllAccInfo()
{
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowAccInfo();
	}
}


----------------------------------------------------------------------------------------------------

๐ ์ฑ์ฐํ ์ฝ๋ ๐
	
#include <iostream>
#include <cstring>
using namespace std;

void ShowMenu();       // ๋ฉ๋ด์ธ๋ ฅ
void MakeAccount();    // ๊ณ์ข๊ฐ์ค์ ์ํ ํจ์
void DepositMoney();   // ์     ๊ธ
void WidthdrawMoney(); // ์ถ     ๊ธ
void ShowAllAccInfo(); // ์์ก์กฐํ

enum { Make = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

class Account
{
private:
	int accID;      // ์์ด๋
	int balance;    // ์์ก
	char* cusName;  // ๊ณ ๊ฐ ์ด๋ฆ

public:
	Account(int id, int money, char* name) : accID(id), balance(money)
	{
		int len = strlen(name) + 1;
		cusName = new char[len];
		strcpy(cusName, name);
	}

	int GetAccID() { return accID; }   // ๐๐ ๋๋ ์ด์๊ฐ์ ๋ชปํจ : private ๋ฉค๋ฒ๋ณ์๋ฅผ ํด๋์ค ์์์๋ง ํด๊ฒฐํ๋ ค๊ณ  ํจ.

	void Deposit(int money)
	{
		balance += money;
	}

	int Widthdraw(int money)
	{
		if (balance < money)
			return 0;
		
		balance -= money;
		return money;
	}

	void ShowAccInfo()
	{
		cout << "๊ณ์ขID: " << accID << endl;
		cout << "์ด ๋ฆ: " << cusName << endl;
		cout << "์๊ธ์ก: " << balance << endl << endl;
	}

	~Account()
	{
		delete[] cusName;
	}
};

Account* accArr[100];
int accNum = 0;

int main()
{
	int choice;

	while (true)
	{
		ShowMenu();
		cout << "์ ํ: ";
		cin >> choice;

		switch (choice)
		{
		case Make:MakeAccount(); break;
		case DEPOSIT:DepositMoney(); break;
		case WITHDRAW:WidthdrawMoney(); break;
		case INQUIRE:ShowAllAccInfo(); break;
		case EXIT: return 0;
		default: cout << "Illegal selection.." << endl; break;
		}
	}

	return 0;
}

void ShowMenu()
{
	cout << "-----Menu-----" << '\n';
	cout << "1. ๊ณ์ข๊ฐ์ค\n";
	cout << "2. ์ ๊ธ\n";
	cout << "3. ์ถ ๊ธ\n";
	cout << "4. ๊ณ์ข์ ๋ณด ์ ์ฒด ์ถ๋ ฅ\n";
	cout << "5. ํ๋ก๊ทธ๋จ ์ข๋ฃ\n\n";
}

void MakeAccount()
{
	int id, money;
	char name[50];

	cout << "[๊ณ์ข๊ฐ์ค]\n";
	cout << "๊ณ์ขID: ";
	cin >> id;
	cout << "์ด ๋ฆ: ";
	cin >> name;
	cout << "์๊ธ์ก: ";
	cin >> money;

	accArr[accNum] = new Account(id, money, name);  // ๋์ ํ ๋น
	accNum++;
	cout << endl;
}

void DepositMoney()
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

	cout << "์ ํจํ์ง ์๋ ID ์๋๋ค.\n\n";    // ๋์ด์คํ ๋ฐฉ๋ฒ?!
}

void WidthdrawMoney()
{
	int id, money;

	cout << "[์ถ  ๊ธ]\n";
	cout << "๊ณ์ขID: "; cin >> id;
	cout << "์ถ๊ธ์ก: "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			if(accArr[i]->Widthdraw(money) == 0)
				cout << "์์ก๋ถ์กฑ\n";
			else
				cout << "์ถ๊ธ์๋ฃ\n\n";

			return;
		}
	}

	cout << "์ ํจํ์ง ์๋ ID ์๋๋ค.\n\n";
}

void ShowAllAccInfo()
{
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowAccInfo();
	}
}
