π’ λ€νμ±(Polymorphism)
  
  
  "λ€νμ±(polymorphism)'μ΄λ 'λμ§μ΄μ'μ μλ―Ένλ€.
  
  "λͺ¨μ΅μ κ°μλ° ννλ λ€λ₯΄λ€."
  
  "λ¬Έμ₯μ κ°μλ° κ²°κ³Όλ λ€λ₯΄λ€."

  
#include <iostream>
using namespace std;

class First
{
public:
	virtual void SimpleFunc() { cout << "First" << endl; }
};

class Second : public First
{
public:
	virtual void SimpleFunc() { cout << "Second" << endl; }
};

int main()
{
	First* ptr = new First();
	ptr->SimpleFunc();          // First μΆλ ₯
	delete ptr;

	ptr = new Second();
	ptr->SimpleFunc();          // Second μΆλ ₯
	delete ptr;

	return 0;
}

           ππ ptrμ λμΌν ν¬μΈν° λ³μμ΄λ€. κ·ΈλΌμλ λΆκ΅¬νκ³  μ€νκ²°κ³Όλ λ€λ₯΄λ€. 
                ν¬μΈν° λ³μ ptrμ΄ μ°Έμ‘°νλ κ°μ²΄μ μλ£νμ΄ λ€λ₯΄κΈ° λλ¬Έμ΄λ€.
                μ΄κ²μ΄ λ°λ‘ C++μμμ 'λ€νμ±'μ μμ΄λ€.
       
       
       
       
