
π’ const κ°μ²΄μ const κ°μ²΄μ νΉμ±λ€

   const SoSimple sim(20);   //  ππ "μ΄ κ°μ²΄μ λ°μ΄ν° λ³κ²½μ νμ©νμ§ μκ² λ€!"
   
   const μ μΈμ΄ λΆκ² λλ©΄, μ΄ κ°μ²΄λ₯Ό λμμΌλ‘λ const λ©€λ²ν¨μλ§ νΈμΆμ΄ κ°λ₯νλ€.
     
------------------------------------------------------------------------------------ 
     
#include <iostream>
using namespace std;

class SoSimple
{
private:
	int num;
public:
  int test;
  
	SoSimple(int n) : num(n) {}                    ππ λ©€λ²λ³μμ μ μ₯λ κ°μ μμ νμ§ μλ ν¨μλ κ°κΈμ  constλ‘ μ μΈν΄μ, const κ°μ²΄μλ
                                                      νΈμΆμ΄ κ°λ₯νλλ‘ ν  νμκ° μλ€.
	SoSimple& AddNum(int n)
	{
		num += n;
		return *this;
	}
  
	void ShowData() const
	{
		cout << "num: " << num << endl;
	}
};

int main()
{
	const SoSimple obj(7);
	//obj.AddNum(20);         <-- constκ° μλ ν¨μ νΈμΆ λΆκ°
	obj.ShowData();

  obj.test;
	//obj.test++; <-- μ΄κ±΄ μ€λ₯ λ°μ
  
	return 0;
}

------------------------------------------------------------------------------------     
  
π’ constμ ν¨μ μ€λ²λ‘λ©

      void SoSimpleFunc() { ... }               μ΄ λκ°μ§ ννμ ν¨μλ‘λ μ€λ²λ‘λ©μ΄ κ°λ₯νλ€.
      void SoSimpleFunc() const { ... }         (ππ constμ μ μΈ μ λ¬΄λ ν¨μ μ€λ²λ‘λ©μ μ‘°κ±΄μ ν΄λΉλλ€.)




#include <iostream>
using namespace std;

class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) : num(n) {}
	SoSimple& AddNum(int n)
	{
		num += n;
		return *this;
	}

	void Func() 
	{
		cout << "Func: " << num << endl;
	}

	void Func() const      // Func() μ€λ²λ‘λ©
	{
		cout << "const Func: " << num << endl;
	}
};

void YourFunc(const SoSimple& obj)
{
	obj.Func();
}

int main()
{
	SoSimple obj1(2);
	const SoSimple obj2(7);

	obj1.Func();
	obj2.Func();

	YourFunc(obj1);
	YourFunc(obj2);

	return 0;
}


/*
  μΆλ ₯κ²°κ³Ό: Func: 2
            const Func: 7
            const Func: 2
            const Func: 7
*/
