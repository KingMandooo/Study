
ππ μ€μ  λ³΅μ¬ μμ±μμ νΈμΆμ¬λΆλ μ€μνμ§ μλ€.
     ν΄λμ€λ κ·Έ μμ²΄λ‘ μμ±νμ΄ λμ΄μΌ νκΈ° λλ¬Έμ, λΉμ₯ νμν κ²λ§μΌλ‘ μ±μ°μ§ μλλ€. // λλ¦ λ΅μΈ..

---------------------------------------------------

#include <iostream>
#include <cstring>
using namespace std;

void ShowMenu();       // λ©λ΄μΈλ ₯
void MakeAccount();    // κ³μ’κ°μ€μ μν ν¨μ
void DepositMoney();   // μ     κΈ
void WidthdrawMoney(); // μΆ     κΈ
void ShowAllAccInfo(); // μμ‘μ‘°ν

enum { Make = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

class Account
{
private:
	int accID;      // μμ΄λ
	int balance;    // μμ‘
	char* cusName;  // κ³ κ° μ΄λ¦

public:
	Account(int id, int money, char* name) : accID(id), balance(money)
	{
		cusName = new char[strlen(name) + 1];
		strcpy(cusName, name);
	}

	Account(Account& copy) : accID(copy.accID), balance(copy.balance)  // λ³΅μ¬μμ±μ
	{
		cusName = new char[strlen(copy.cusName) + 1];
		strcpy(cusName, copy.cusName);
	}

	int GetAccID() { return accID; }  

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
		cout << "κ³μ’ID: " << accID << endl;
		cout << "μ΄ λ¦: " << cusName << endl;
		cout << "μκΈμ‘: " << balance << endl << endl;
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
		cout << "μ ν: ";
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
	cout << "1. κ³μ’κ°μ€\n";
	cout << "2. μ κΈ\n";
	cout << "3. μΆ κΈ\n";
	cout << "4. κ³μ’μ λ³΄ μ μ²΄ μΆλ ₯\n";
	cout << "5. νλ‘κ·Έλ¨ μ’λ£\n\n";
}

void MakeAccount()
{
	int id, money;
	char name[50];

	cout << "[κ³μ’κ°μ€]\n";
	cout << "κ³μ’ID: ";
	cin >> id;
	cout << "μ΄ λ¦: ";
	cin >> name;
	cout << "μκΈμ‘: ";
	cin >> money;

	accArr[accNum] = new Account(id, money, name); 
	accNum++;
	cout << endl;
}

void DepositMoney()
{
	int money, id;

	cout << "[μ  κΈ]\n";
	cout << "κ³μ’ID: "; cin >> id;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			cout << "μκΈμ‘: "; cin >> money;
			accArr[i]->Deposit(money);
			cout << "μκΈμλ£" << endl << endl;
			return;
		}
	}

	cout << "μ ν¨νμ§ μλ ID μλλ€.\n\n";    
}

void WidthdrawMoney()
{
	int id, money;

	cout << "[μΆ  κΈ]\n";
	cout << "κ³μ’ID: "; cin >> id;
	cout << "μΆκΈμ‘: "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			if (accArr[i]->Widthdraw(money) == 0)
				cout << "μμ‘λΆμ‘±\n";
			else
				cout << "μΆκΈμλ£\n\n";

			return;
		}
	}

	cout << "μ ν¨νμ§ μλ ID μλλ€.\n\n";
}

void ShowAllAccInfo()
{
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowAccInfo();
	}
}
