
            ππ μμμ μ¬νμ©μ λͺ©μ μΌλ‘λ§ μ‘΄μ¬νλ λ¬Έλ²μ  μμκ° μλλ€!!
             
------------------------------------------------------------------------
             
#include <iostream>
using namespace std;

class PermanentWorker    // μ§μλ€ μ΄λ¦κ³Ό μκΈ μλ €μ£Όλ ν΄λμ€
{
private:
	char name[100];
	int salary;
public:
	PermanentWorker(const char* name, int money) : salary(money)
	{
		strcpy(this->name, name);
	}
	int GetPay() const
	{
		return salary;
	}
	void ShowSalaryInfo() const
	{
		cout << "name: " << name << endl;
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class EmployeeHandler    // κ³ μ©μλ€ μ λ³΄ λ€μ΄κ° μλ ν΄λμ€
{                                           
private: 
	PermanentWorker* empList[50];                //ππ EmployeeHandler ν΄λμ€μ κ°μ΄ κΈ°λ₯μ μ²λ¦¬λ₯Ό μ€μ λ‘ λ΄λΉνλ ν΄λμ€λ₯Ό κ°λ¦¬μΌ
	int empNum;                                  //     'μ»¨νΈλ‘€(control) ν΄λμ€' λλ 'νΈλ€λ¬(handler) ν΄λμ€'λΌ νλ€.
public:
	EmployeeHandler() : empNum(0) {}

	void AddEmployee(PermanentWorker* emp)
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
	EmployeeHandler handler;

	handler.AddEmployee(new PermanentWorker("KIM", 1000));
	handler.AddEmployee(new PermanentWorker("LEE", 1500));
	handler.AddEmployee(new PermanentWorker("JUN", 2000));

	handler.ShowAllSalaryInfo();

	handler.ShowTotalSalary();

	return 0;
}
                                    
                           ππ μμ μ½λλ νμ₯μ±μ μμ΄μ μ’μ μ μλ₯Ό μ€ μ μλ μνμ΄λ€. μ’μ μ μλ₯Ό λ°μΌλ €λ©΄, SalesMan ν΄λμ€μ
                                Temporary ν΄λμ€μ μΆκ°λ‘ μΈν λ³κ²½μ μ΅μνν  μ μμ΄μΌ νλ€.
