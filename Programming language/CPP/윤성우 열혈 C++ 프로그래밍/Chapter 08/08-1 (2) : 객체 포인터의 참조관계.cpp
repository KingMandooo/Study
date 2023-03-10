๐ข '์ค๋ ์ง๋ฏธ๋์ด ๊ธ์ฌ๊ด๋ฆฌ ํ์ฅ์ฑ ๋ฌธ์ '์ 1์ฐจ์  ํด๊ฒฐ๊ณผ ํจ์ ์ค๋ฒ๋ผ์ด๋ฉ

#include <iostream>
using namespace std;

class Employee
{
private:
	char name[100];
public:
	Employee(char* name)
	{
		strcpy(this->name, name);
	}
	void ShowYourName() const
	{
		cout << "name: " << name << endl;
	}
};

class PermanentWorker : public Employee   
{
private:
	int salary;
public:
	PermanentWorker(char* name, int money) : Employee(name), salary(money)
	{}
	int GetPay() const
	{
		return salary;
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class EmployeeHandler   
{
private:
	Employee* empList[50];            // ๐๐ ํต์ฌ! : Employee ๊ฐ์ฒด์ ์ฃผ์ ๊ฐ์ ์ ์ฅํ๋ ๋ฐฉ์, 
	int empNum;                       //              Employee ํด๋์ค๋ฅผ ์์ํ๋ ํด๋์ค์ ๊ฐ์ฒด๋ ์ด ๋ฐฐ์ด์ ์ ์ฅ๊ฐ๋ฅ
public:
	EmployeeHandler() : empNum(0) {}

	void AddEmployee(Employee* emp)
	{
		empList[empNum++] = emp;                 // ๐๐ empList์ Employee ๊ฐ์ฒด ์ฃผ์๊ฐ ์ ์ฅ
	}
	void ShowAllSalaryInfo() const
	{
		//for (int i = 0; i < empNum; i++)        <-- ์ฃผ์์ ํ๋ฉด ์ค๋ฅ ๋ฐ์!
		//	empList[i]->ShowSalaryInfo();
	}
	void ShowTotalSalary() const
	{
		int sum = 0;
		//for (int i = 0; i < empNum; i++)        <-- ์ฃผ์์ ํ๋ฉด ์ค๋ฅ ๋ฐ์!
		//	sum += empList[i]->GetPay();
		cout << "salary sum: " << sum << endl;
	}
	~EmployeeHandler()
	{
		for (int i = 0; i < empNum; i++)
			delete empList[i];
	}
};

int main()
{
	EmployeeHandler handler;

	handler.AddEmployee(new PermanentWorker("KIM", 1000));
	handler.AddEmployee(new PermanentWorker("LEE", 1500));
	handler.AddEmployee(new PermanentWorker("JUN", 2000));

	handler.ShowAllSalaryInfo();

	handler.ShowTotalSalary();

	return 0;
}

/*
  ์ถ๋ ฅ๊ฒฐ๊ณผ: salary sum: 0
*/

---------------------------------------------------------------------------------------------
  
๐ข ์ค๋ฒ๋ผ์ด๋ฉ

๐๐   ์ฐธ๊ณ  :  Override์ ์ฌ์ ์  ์๋ฏธ๋ v.์ฐ์ ํ๋ค, ์ค๋จ์ํค๋ค ๋ฑ์ด๋ค. 
  
        ์๋ฐ์์ ์ค๋ฒ๋ผ์ด๋ฉ์ ๋ถ๋ชจํด๋์ค๋ก๋ถํฐ ์์๋ฐ์ ๋ฉ์๋๋ฅผ ์ฌ์ ์ํ๋ ๊ฒ์ ๋งํ๋ค. 
        ์ค๋ฒ๋ผ์ด๋ฉ๋ ๋ฉ์๋๋ ๋ถ๋ชจ ํด๋์ค์ ์๋ ๋ฉ์๋๋ณด๋ค ์ฐ์ ๋๊ธฐ ๋๋ฌธ์ ์์ ๊ฐ์ฒด์์ ๋ฉ์๋ ํธ์ถ ์ ์ค๋ฒ๋ผ์ด๋ฉ ๋ ๋ฉ์๋๊ฐ ํธ์ถ๋๋ค.
        (C++๋ ๋ง์ฐฌ๊ฐ์ง)
  
  
#include <iostream>
using namespace std;

class Employee  // ๊ณ ์ฉ์ธ
{
private:
	char name[100];
public:
	Employee(char* name)
	{
		strcpy(this->name, name);
	}
	void ShowYourName() const
	{
		cout << "name: " << name << endl;
	}
};

class PermanentWorker : public Employee    // ์ ๊ท์ง
{
private:
	int salary;
public:
	PermanentWorker(char* name, int money) : Employee(name), salary(money)
	{}
	int GetPay() const
	{
		return salary;
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class TemporaryWorker : public Employee  // ์์์ง
{
private:
	int workTime;
	int payPerHour;
public:
	TemporaryWorker(char* name, int pay) : Employee(name), workTime(0), payPerHour(pay)
	{}
	void AddWorkTime(int time)
	{
		workTime += time;
	}
	int GetPay() const
	{
		return workTime * payPerHour;
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}  
};

class SalesWorker : public PermanentWorker   // ์์์ง
{
private:
	int salesResult;
	double bonusRatio;
public:
	SalesWorker(char* name, int money, double bonusRatio)
		: PermanentWorker(name, money), salesResult(0), bonusRatio(bonusRatio) {}
	void AddSalesResult(int value)
	{
		salesResult += value;
	}
	int GetPay() const    // ๐๐ ํจ์ ์ค๋ฒ๋ผ์ด๋ฉ               โ ๊ธฐ์ด ํด๋์ค์ธ PermanentWorker์ ์๋ GetPay()์ ShowSalaryInfo()๋ฅผ 
	{                                                           // ์ ๋ ํด๋์ค์ธ SalesWorker์๋ ์ถ๊ฐํ์ฌ ํจ์๋ฅผ ์ค๋ฒ๋ฉ์์ผ์ฃผ์๋ค.
		return PermanentWorker::GetPay() + (int)(salesResult * bonusRatio);
	} 
	void ShowSalaryInfo() const     // ๐๐ ํจ์ ์ค๋ฒ๋ผ์ด๋ฉ  
	{
		ShowYourName();                                  
		cout << "salary: " << GetPay() << endl << endl;
	}
};     // โ Q. ๊ธฐ์ด ํด๋์ค์ธ PermanentWorker์ ์ ๋ ํด๋์ค์ธ SalesWorker์ ShowSalaryInfo()๋ ์์ ํ ๋์ผํ๋ฐ ์ ๊ตณ์ด ์ค๋ฒ๋ผ์ด๋ฉ์ ํด์คฌ์๊น?

class EmployeeHandler      
{
private:                             // โ A. ๊ทธ๊ฑด ๋ฐ๋ก ShowSalaryInfo()์  GetPay() ํจ์๋ ๊ฐ ํด๋์ค๋ง๋ค ์๋ก ๋ค๋ฅด๊ธฐ ๋๋ฌธ์
	Employee* empList[50];             //        ShowSalaryInfo()๋ฅผ ์ค๋ฒ๋ผ์ด๋ฉํด์ค์ผ ๊ฐ ํด๋์ค์  GetPay()๋ฅผ ๋ถ๋ฌ์ค๊ธฐ ๋๋ฌธ์ด๋ค.
	int empNum;                                        
public:
	EmployeeHandler() : empNum(0) {}

	void AddEmployee(Employee* emp)                   // ๐๐ ๊ธฐ์ด ํด๋์ค์ ๋์ผํ ์ด๋ฆ์ ํจ์๋ฅผ ์ ๋ ํด๋์ค์์ ์ ์ํ๋ค๊ณ  ํด์
	{                                                 //      ๋ฌด์กฐ๊ฑด ํจ์ ์ค๋ฒ๋ผ์ด๋ฉ์ด ๋๋ ๊ฒ์ ์๋๋ค.
		empList[empNum++] = emp;                        //      ๋งค๊ฐ๋ณ์์ ์๋ฃํ ๋ฐ ๊ฐ์๊ฐ ๋ค๋ฅด๋ฉด, ์ด๋ ํจ์ ์ค๋ฒ๋ก๋ฉ์ด ๋์ด,
	}                                                 //      ์ ๋ฌ๋๋ ์ธ์์ ๋ฐ๋ผ์ ํธ์ถ๋๋ ํจ์๊ฐ ๊ฒฐ์ ๋๋ค.
	void ShowAllSalaryInfo() const                    //      ์ฆ, ํจ์ ์ค๋ฒ๋ก๋ฉ์ ์์์ ๊ด๊ณ์์๋ ๊ตฌ์ฑ์ด ๋  ์ ์๋ค.
	{
		//for (int i = 0; i < empNum; i++)              // ํ์ง๋ง ์ด๋ฆ์ด ๊ฒน์น๋ ํจ์๊ฐ ์กด์ฌํ๋ ์ด์, ๊ธฐ์ด class์ ํจ์๋ฅผ ํธ์ถํ  ๋์๋ class์ ์ด๋ฆ์ ๋ช์ํด์ค์ผํจ.
		//	empList[i]->ShowSalaryInfo();               // AA:Hello() ์ด๋ฐ์์ผ๋ก.  08-1(1)์ ๋์์์.
	}
	void ShowTotalSalary() const
	{
		int sum = 0;
		//for (int i = 0; i < empNum; i++)
		//	sum += empList[i]->GetPay();
		cout << "salary sum: " << sum << endl;
	}
	~EmployeeHandler()
	{
		for (int i = 0; i < empNum; i++)
			delete empList[i];
	}
};

int main()
{
	// ์ง์๊ด๋ฆฌ๋ฅผ ๋ชฉ์ ์ผ๋ก ์ค๊ณ๋ ์ปจํธ๋กค ํด๋์ค์ ๊ฐ์ฒด์์ฑ
	EmployeeHandler handler;

	// ์ ๊ท์ง ๋ฑ๋ก
	handler.AddEmployee(new PermanentWorker("KIM", 1000));
	handler.AddEmployee(new PermanentWorker("LEE", 1500));

	// ์์์ง ๋ฑ๋ก
	TemporaryWorker* alba = new TemporaryWorker("Jung", 700);
	alba->AddWorkTime(5);
	handler.AddEmployee(alba);

	// ์์์ง ๋ฑ๋ก
	SalesWorker* seller = new SalesWorker("Hong", 1000, 0.1);
	seller->AddSalesResult(7000);
	handler.AddEmployee(seller);
	
	// ์ด๋ฒ ๋ฌ์ ์ง๋ถํด์ผ ํ  ๊ธ์ฌ์ ์ ๋ณด
	handler.ShowAllSalaryInfo();

	// ์ด๋ฒ ๋ฌ์ ์ง๋ถํด์ผ ํ  ๊ธ์ฌ์ ์ดํฉ
	handler.ShowTotalSalary();

	return 0;
}



/*
  ์ถ๋ ฅ๊ฒฐ๊ณผ: salary sum: 0   <-- ๐๐ ์์ง ์ด๊ฒ ์ ์์ ์์ง ์ฝ๋๊ฐ ์์ฑ์ด ์๋จ. 08-2์์ ๊ณ์...
*/  
