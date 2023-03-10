π’ 'μ€λ μ§λ―Έλμ΄ κΈμ¬κ΄λ¦¬ νμ₯μ± λ¬Έμ 'μ ν΄κ²°μ ν΅ν΄μ νμΈν μμμ μ΄μ 


  "μμμ νλ μ΄μ λ λ¬΄μμΈκ°?"
  
  "μμμ ν΅ν΄ μ°κ΄λ μΌλ ¬μ ν΄λμ€μ λν κ³΅ν΅μ μΈ κ·μ½μ μ μν  μ μμ΅λλ€."
  
  "μμμ ν΅ν΄ μ°κ΄λ μΌλ ¬μ ν΄λμ€ PermanentWorker, TemporaryWorker, SalesWorkerμ κ³΅ν΅μ μΈ κ·μ½μ μ μν  μ μμ΅λλ€."
  
   --> μ¬κΈ°μ μΌλ ¬μ ν΄λμ€ PermanentWorker, TemporaryWorker, SalesWorkerμ μ μ©λ κ³΅ν΅κ·μ½μ Employee ν΄λμ€μ΄λ€.
       μ΄λ‘ μΈν΄, Employee ν΄λμ€λ₯Ό μμνλ λͺ¨λ  ν΄λμ€μ κ°μ²΄λ Employee κ°μ²΄λ‘ λ°λΌλ³Ό μ μκ² λ κ²μ΄λ€.
  
------------------------------------------------------------------------------------------------------------------
  
π’ μμ κ°μν¨μ(Pure Virtual Function)μ μΆμ ν΄λμ€(Abstract Class)
  
  
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
	virtual int GetPay() const     // ππ μ΄λ κ² ν΄λμ€ μ€μμλ κ°μ²΄μμ±μ λͺ©μ μΌλ‘ μ μλμ§ μλ ν΄λμ€λ μ‘΄μ¬νλ€.
	{                              //      λ°λΌμ μ΄λ¬ν κ²½μ°μλ κ°μν¨μλ₯Ό 'μμ κ°μν¨μ'λ‘ μ μΈνμ¬ κ°μ²΄μ μμ±μ λ¬Έλ²μ μΌλ‘ λ§λ κ²μ΄ μ’λ€.
		return 0; 
	}
	virtual void ShowSalaryInfo() const 
	{}
};



class Employee 
{
private:
	char name[100];
public:
	Employee(char* name)
	{  
		strcpy(this->name, name);           //  ππ 'μμ κ°μν¨μ'λ 'ν¨μμ λͺΈμ²΄κ° μ μλμ§ μλ ν¨μ'λ₯Ό μλ―Ένλ€.    
	}                                     //       Employee ν΄λμ€λ μμ κ°μν¨μλ₯Όμ§λ, μμ νμ§ μλ ν΄λμ€κ° λκΈ° λλ¬Έμ
	void ShowYourName() const             //       κ°μ²΄λ₯Ό μμ±νλ € λ€λ©΄ μ»΄νμΌ μλ¬κ° λ°μνλ€..!!
	{
		cout << "name: " << name << endl;
	}
	virtual int GetPay() const = 0;             // μμ κ°μν¨μ
	virtual void ShowSalaryInfo() const = 0;    // μμ κ°μν¨μ
};
          
                    β μμ κ°μν¨μλ₯Ό ν΅ν΄ μ»μ μ΄μ  λ κ°μ§.
                      
                       1. μλͺ»λ κ°μ²΄μ μμ±μ λ§μ μ μλ€.
                      
                       2. Employee ν΄λμ€μ GetPayν¨μμ ShowSalaryInfo ν¨μλ μ λ ν΄λμ€μ 
                          μ μλ ν¨μκ° νΈμΆλκ²λ λλλ° μλ―Έκ° μμμ λΏ,
                          μ€μ λ‘ μ€νμ΄ λλ ν¨μλ μλμλλ°, μ΄λ₯Ό λ³΄λ€ λͺνν λͺμνλ ν¨κ³Όλ μ»κ² λμλ€.
                            
                            
                            
             ππ μ΄λ λ― νλ μ΄μμ λ©€λ²ν¨μλ₯Ό μμ κ°μν¨μλ‘ μ μΈν ν΄λμ€λ₯Ό κ°λ¦¬μΌ 'μΆμ ν΄λμ€(abstract class)'λΌ νλ€.
                  μ΄λ μμ νμ§ μμ, κ·Έλμ κ°μ²΄μμ±μ΄ λΆκ°λ₯ν ν΄λμ€λΌλ μλ―Έλ₯Ό μ§λλ€...
                            
------------------------------------------------------------------------------------------------------------------                            
                            
π  λ¬Έμ  08-1  (λ€μ νμ΄λ³΄κΈ°) 
                            
#include <iostream>
using namespace std;

enum RISK_LEVEL { RISK_A = 30, RISK_B = 20, RISK_C = 10 };

class Employee  // κ³ μ©μΈ
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
	virtual int GetPay() const = 0;
	virtual void ShowSalaryInfo() const = 0;
};

class PermanentWorker : public Employee    // μ κ·μ§
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

class TemporaryWorker : public Employee  // μμμ§
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

class SalesWorker : public PermanentWorker   // μμμ§
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
	int GetPay() const   
	{                                                           
		return PermanentWorker::GetPay() + (int)(salesResult * bonusRatio);
	}
	void ShowSalaryInfo() const     
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};     

class ForeignSalesWorker : public SalesWorker
{
private:                  // ππμ λ§λ‘ ν΄λμ€λ νλμ κ°μ²΄λΌκ³  μκ°νκ³  μ½λλ₯Ό μ§μΌκ² λ€.
	const int riskRate;
public:
	ForeignSalesWorker(char* name, int money, double bonusRatio, int riskRate)
		: SalesWorker(name, money, bonusRatio), riskRate(riskRate) {}

	int GetRiskPay() const  // ππForeignSalesWorkerκ° λ°λ λ¦¬μ€ν¬ λΉμ©
	{
		return (int)(SalesWorker::GetPay() * (riskRate / 100.0));
	}
	int GetPay() const    // ππForeignSalesWorkerκ° λ°λ μ μ²΄ λΉμ©
	{ 
		return SalesWorker::GetPay() + GetRiskPay();
	}
	void ShowSalaryInfo() const  // ππForeignSalesWorkerμ λ΄κΈ μΆλ ₯  
	{
		ShowYourName();
		cout << "salary: " << SalesWorker::GetPay() << endl;
		cout << "risk pay: " << GetRiskPay() << endl;
		cout << "sum: " << GetPay() << endl << endl;
	}
};

class EmployeeHandler
{
private:                             
	Employee* empList[50];            
	int empNum;
public:
	EmployeeHandler() : empNum(0) {}

	void AddEmployee(Employee* emp)                  
	{                                               
		empList[empNum++] = emp;                      
	}                                               
	void ShowAllSalaryInfo() const                  
	{
		for (int i = 0; i < empNum; i++)              
			empList[i]->ShowSalaryInfo();              
	}
	void ShowTotalSalary() const
	{
		int sum = 0;
		for (int i = 0; i < empNum; i++)
			sum += empList[i]->GetPay();
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
	// μ§μκ΄λ¦¬λ₯Ό λͺ©μ μΌλ‘ μ€κ³λ μ»¨νΈλ‘€ ν΄λμ€μ κ°μ²΄μμ±
	EmployeeHandler handler;

	// μ κ·μ§ λ±λ‘
	ForeignSalesWorker* fseller1 = new ForeignSalesWorker("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
	fseller1->AddSalesResult(7000);
	handler.AddEmployee(fseller1);

	ForeignSalesWorker* fseller2 = new ForeignSalesWorker("Yoon", 1000, 0.1, RISK_LEVEL::RISK_B);
	fseller2->AddSalesResult(7000);
	handler.AddEmployee(fseller2);

	ForeignSalesWorker* fseller3 = new ForeignSalesWorker("Lee", 1000, 0.1, RISK_LEVEL::RISK_C);
	fseller3->AddSalesResult(7000);
	handler.AddEmployee(fseller3);

	handler.ShowAllSalaryInfo();
	return 0;
}
                            
