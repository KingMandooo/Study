#include <iostream>
using namespace std;

class AA
{
public:
	void AAShow()
	{
		cout << "AA Show()" << endl;
	}
};

class BB : public AA
{
public:
	void BBShow()
	{
		cout << "BB Show()" << endl;
	}
};

class CC : public BB
{
public:
	void CCShow()
	{
		cout << "CC Show()" << endl;
	}
};

int main()
{
	CC* cc = new CC();                        // ππ ν¬μΈν° νμ ν΄λΉνλ ν΄λμ€μ μ μλ λ©€λ²μλ§ μ κ·Όμ΄ κ°λ₯νλ€. 
	BB* bb = cc;                              //       "C++ μ»΄νμΌλ¬λ ν¬μΈν°λ₯Ό μ΄μ©ν μ°μ°μ κ°λ₯μ± μ¬λΆλ₯Ό νλ¨ν  λ, ν¬μΈν°μ μλ£νμ κΈ°μ€μΌλ‘
	AA* aa = bb;                              //        νλ¨νμ§, μ€μ  κ°λ¦¬ν€λ κ°μ²΄μ μλ£νμ κΈ°μ€μΌλ‘ νλ¨νμ§ μλλ€."

	aa->AAShow();
	//aa->BBShow();    β μ€λ₯λ°μ    <-- AAνμλ§ μ κ·Ό κ°λ₯.
	//aa->CCShow();    β μ€λ₯λ°μ

	bb->AAShow();
	bb->BBShow();
	//bb->CCShow();    β μ€λ₯λ°μ    <-- BBνμλ§ μ κ·Ό κ°λ₯.

	cc->AAShow();
	cc->BBShow();
	cc->CCShow();
}

-----------------------------------------------------------------------------------
  
π’ ν¨μμ μ€λ²λΌμ΄λ©κ³Ό ν¬μΈν° ν

--> ν¨μκ° μ€λ²λΌμ΄λ©μ΄ λμ΄λ, ν¬μΈν° νμ λ°λΌ μμ μκ² μν΄μλ ν¨μλ₯Ό νΈμΆνλ€.

#include <iostream>
using namespace std;

class AA
{
public:
	void Show()
	{
		cout << "AA Show()" << endl;
	}
};

class BB : public AA
{
public:
	void Show()   // ν¨μ μ€λ²λΌμ΄λ©
	{
		cout << "BB Show()" << endl;
	}
};

class CC : public BB
{
public:
	void Show()   // ν¨μ μ€λ²λΌμ΄λ©
	{
		cout << "CC Show()" << endl;
	}
};

int main()
{
	CC* cc = new CC();
	BB* bb = cc;    
	AA* aa = bb;    

	aa->Show();        // aaλ AAν ν¬μΈν°μ΄λ, μ΄ ν¬μΈν°κ° κ°λ¦¬ν€λ κ°μ²΄λ₯Ό λμμΌλ‘ AA ν΄λμ€μ μ μλ Show()λ₯Ό νΈμΆν΄μΌκ² λ€
  
	bb->Show();        // bbλ BBν ν¬μΈν°μ΄λ, μ΄ ν¬μΈν°κ° κ°λ¦¬ν€λ κ°μ²΄μλ AAμ Show()μ BBμ Show()κ° μ€λ²λΌμ΄λ© κ΄κ³λ‘ μ‘΄μ¬νλκ΅°! 
                     // κ·ΈλΌ μ€λ²λΌμ΄λ©μν BBμ Show()λ₯Ό νΈμΆν΄μΌκ² λ€.
	cc->Show();         
}


/*
  μΆλ ₯κ²°κ³Ό:   AA Show()
              BB Show()
              CC Show()
*/

-----------------------------------------------------------------------------------
  
π’ κ°μν¨μ(Virtual Function)

#include <iostream>
using namespace std;

class AA
{
public:
	virtual void Show()
	{
		cout << "AA Show()" << endl;
	}
};

class BB : public AA                   // ππ ν¨μκ° κ°μν¨μλ‘ μ μΈλλ©΄, ν΄λΉ ν¨μνΈμΆ μ, ν¬μΈν°μ μλ£νμ κΈ°λ°μΌλ‘ νΈμΆλμμ κ²°μ νμ§ μκ³ ,
{                                      //       ν¬μΈν° λ³μκ° μ€μ λ‘ κ°λ¦¬ν€λ κ°μ²΄λ₯Ό μ°Έμ‘°νμ¬ νΈμΆμ λμμ κ²°μ νλ€.
public:
	virtual void Show()
	{
		cout << "BB Show()" << endl;
	}
};

class CC : public BB
{
public:
	virtual void Show()
	{
		cout << "CC Show()" << endl;
	}
};

int main()
{
	CC* cc = new CC();
	BB* bb = cc;     // ν΄λμ€ CCλ₯Ό κ°λ¦¬ν΄
	AA* aa = bb;     // ν΄λμ€ CCλ₯Ό κ°λ¦¬ν΄ μλνλ©΄ bbκ° CCλ₯Ό κ°λ¦¬ν€λκΉ

	aa->Show();
	bb->Show();
	cc->Show();
}


/*
  μΆλ ₯κ²°κ³Ό:   CC Show()
              CC Show()
              CC Show()
*/

-----------------------------------------------------------------------------------
  
π’ 'μ€λ μ§λ―Έλμ΄ κΈμ¬κ΄λ¦¬ νμ₯μ λ¬Έμ 'μ μμ ν ν΄κ²°

#include <iostream>
using namespace std;

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
	virtual int GetPay() const              // ππ κ°μν¨μ μΆκ°!!
	{
		return 0;
	}
	virtual void ShowSalaryInfo() const     // ππ κ°μν¨μ μΆκ°!!
	{}
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

class EmployeeHandler
{
private:                             
	Employee* empList[50];            
	int empNum;
public:
	EmployeeHandler() : empNum(0) {}

	void AddEmployee(Employee* emp)                  
	{                                               
		empList[empNum++] = emp;                       //  ππ empList[0]  ->   PermanentWorker κ°μ²΄ κ°λ¦¬ν΄    
	}                                                //  ππ empList[1]  ->   PermanentWorker κ°μ²΄ κ°λ¦¬ν΄    
	void ShowAllSalaryInfo() const                   //  ππ empList[2]  ->   TemporaryWorker κ°μ²΄ κ°λ¦¬ν΄    
	{                                                //  ππ empList[3]  ->   SalesWorker κ°μ²΄ κ°λ¦¬ν΄    
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
	handler.AddEmployee(new PermanentWorker("KIM", 1000));
	handler.AddEmployee(new PermanentWorker("LEE", 1500));

	// μμμ§ λ±λ‘
	TemporaryWorker* alba = new TemporaryWorker("Jung", 700);
	alba->AddWorkTime(5);
	handler.AddEmployee(alba);

	// μμμ§ λ±λ‘
	SalesWorker* seller = new SalesWorker("Hong", 1000, 0.1);
	seller->AddSalesResult(7000);
	handler.AddEmployee(seller);

	// μ΄λ² λ¬μ μ§λΆν΄μΌ ν  κΈμ¬μ μ λ³΄
	handler.ShowAllSalaryInfo();

	// μ΄λ² λ¬μ μ§λΆν΄μΌ ν  κΈμ¬μ μ΄ν©
	handler.ShowTotalSalary();

	return 0;
}



/*
  μ€νκ²°κ³Ό:    name: KIM
               salary: 1000

               name: LEE
               salary: 1500

               name: Jung
               salary: 3500

               name: Hong
               salary: 1700
   
               salary sum: 7700
*/
