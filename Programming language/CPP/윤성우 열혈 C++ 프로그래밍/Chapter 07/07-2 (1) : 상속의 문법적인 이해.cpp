#include <iostream>
using namespace std;

class AA
{
private:
	int a;
public:
	AA() // ๐๐์์ฑ์์์ ๋ฉค๋ฒ๋ณ์๋ฅผ ์ด๊ธฐํํ์ง ์์ผ๋ฉด ์ด๊ธฐํํ๋ผ๊ณ  ์ปดํ์ผ๋ฌ๊ฐ ๊ฒฝ๊ณ ๋ฅผ ๋ณด๋
	{
		cout << "AA ์์ฑ์" << endl;
	}
	AA(int a) : a(a)
	{
		cout << "AA() ์์ฑ์" << endl;
	}
	~AA()
	{
		cout << "AA ์๋ฉธ์" << endl;
	}
};

class BB : public AA
{
public:
	BB()
	{
		cout << "BB ์์ฑ์" << endl;
	}
	BB(int a) : AA(a)
	{
		cout << "BB() ์์ฑ์" << endl;
	}
	~BB()
	{
		cout << "BB ์๋ฉธ์" << endl;
	}
};

int main()
{
	BB bb1(3);
	BB bb2;       

	return 0;
}


/*
  ์คํ๊ฒฐ๊ณผ: AA() ์์ฑ์           // ๊ฐ์ฒด bb1์ด ์์ฑ๋๋ฉด์ ์์๋ฐ์ AA์ ์์ฑ์ ํธ์ถ
            BB() ์์ฑ์           // ๊ทธ๋ฆฌ๊ณ  BB์ ์์ฑ์ ํธ์ถ
            AA ์์ฑ์             // ๊ฐ์ฒด bb2๊ฐ ์์ฑ๋๋ฉด์ ์์๋ฐ์ AA์ ์์ฑ์ ํธ์ถ
            BB ์์ฑ์             // ๊ทธ๋ฆฌ๊ณ  BB์ ์์ฑ์ ํธ์ถ
            BB ์๋ฉธ์             // ์คํํ์์ผ๋ก ์์๊ธฐ ๋๋ฌธ์ LIFO ์์ผ๋ก bb2 ์๋ฉธ์ ํธ์ถ
            AA ์๋ฉธ์             // bb2 ์์ ์ ์ฅ๋์ด์๋ ํด๋์ค AA์ ๋ฉค๋ฒ๋ ์๋ฉธ
            BB ์๋ฉธ์             // bb1 ์๋ฉธ์ ํธ์ถ
            AA ์๋ฉธ์             // bb1 ์์ ์ ์ฅ๋์ด์๋ ํด๋์ค AA์ ๋ฉค๋ฒ ์๋ฉธ
*/
---------------------------------------------------------------------------

// (์ปดํ์ผ๋ฌ ์ค์๋ชจ๋ ๊บผ์ง ์ํ)
 
#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:
	int age;        // ํด๋์ค์ ์ธ๋ถ์์๋ prviate ๋ฉค๋ฒ์ ์ ๊ทผ์ด ๋ถ๊ฐ๋ฅํ๋ค. ๋ฐ๋ผ์ UnivStudent์ ๋ฉค๋ฒํจ์ ๋ด์์๋ Person์ ๋ฉค๋ฒ๋ณ์์ ์ง์  ์ ๊ทผ์ด ๋ถ๊ฐ๋ฅํ๋ค. 
	char name[50];
public:
	Person(int myage, char* myname) : age(myage)
	{
		strcpy(name, myname);
	}
	void WhatYourName() const
	{
		cout << "My name is " << name << endl;
	}
	void HowOldAreYou() const
	{
		cout << "I'm " << age << " years old" << endl;
	}
};

class UnivStudent : public Person
{
private:
	char major[50];
public:
	UnivStudent(char* myname, int myage, char* mymajor) : Person(myage, myname) // ๐๐ ๋ถ๋ชจ ํด๋์ค์ ์์ฑ์๋ฅผ ํธ์ถํด์ ๋ถ๋ชจ ํด๋์ค์ ๋ฉค๋ฒ๋ฅผ ์ด๊ธฐํ !!
	{
		strcpy(major, mymajor);
	}
	void WhoAreYou() const
	{
		WhatYourName();
		HowOldAreYou();
		cout << "my major is " << major << endl << endl;
	}
};

int main()
{
	UnivStudent ustd1("Lee", 22, "Computer eng.");
	ustd1.WhoAreYou();

	UnivStudent ustd2("Yoon", 21, "Electronic eng.");
	ustd2.WhoAreYou();
}
                                             // ๐๐ ์์ ํด๋์ค์ ์์ฑ์๋ ๋ถ๋ชจ ํด๋์ค์ ๋ฉค๋ฒ๊น์ง ์ด๊ธฐํํด์ผ ํ  ์๋ฌด๊ฐ ์๋ค.
                                                      
/*                                           // ๐๐ ์์ ํด๋์ค์ ์์ฑ์๋, ๋ถ๋ชจ ํด๋์ค์ ์์ฑ์๋ฅผ ํธ์ถํด์ ๋ถ๋ชจ ํด๋์ค์ ๋ฉค๋ฒ๋ฅผ ์ด๊ธฐํํ๋ ๊ฒ์ด ์ข๋ค.
  ์ถ๋ ฅ๊ฒฐ๊ณผ: My name is Lee
            I'm 22 years old
            my major is Computer eng.

            My name is Yoon
            I'm 21 years old
            my major is Electronic eng.
*/
---------------------------------------------------------------------------
  
     Person    <-->    UnivStudent
      
์์ ํด๋์ค             ํ์ ํด๋์ค
๊ธฐ์ด(base) ํด๋์ค       ์ ๋(derived) ํด๋์ค
์ํผ(super) ํด๋์ค      ์๋ธ(sub) ํด๋์ค
๋ถ๋ชจ ํด๋์ค             ์์ ํด๋์ค
     
  
  
  
  
    ๐๐ ์ด ์ฑ์์๋ '๊ธฐ์ด ํด๋์ค'์ '์ ๋ ํด๋์ค'๋ผ๋ C++์์ ๊ฐ์ฅ ์ผ๋ฐ์ ์ผ๋ก ์ฌ์ฉ๋๋ ํํ์ ์ฐ๊ฒ ๋ค๊ณ  ํ๋ค.
  
  
---------------------------------------------------------------------------
  
#include <iostream>
#include <cstring>
using namespace std;

class Secret
{                               // โ ๋ด๊ฐ ์ง๋ณธ ์ฝ๋. ๊ทธ๋ฐ๋ฐ ์ฝ๋๋ฅผ ์ง๋ณด๋ค๋ณด๋ฉด ์์ฐ์ค๋  ์ ๋ํด๋์ค์ ์์ฑ์์์ ๊ธฐ์ดํด๋์ค์ ์์ฑ์๋ฅผ ํตํด 
private:                        //     ๊ธฐ์ด ํด๋์ค์ private ๋ฉค๋ฒ๋ณ์๋ฅผ ์ด๊ธฐํํ๋ ค๋ ๋ฐฉํฅ์ผ๋ก ๋์๊ฐ๊ฒ ๋๋ค.
	int num1;
	int num2;
public:
	Secret(int num1, int num2) : num1(num1), num2(num2)
	{

	}
	int Sum()
	{
		return num1 + num2;
	}
};

class Yahoo : public Secret
{
private:
	int sum;
public:
	Yahoo(int num1, int num2) : Secret(num1, num2)
	{
		sum = Sum();
		cout << "Secret ํด๋์ค์ ๋ฉค๋ฒ๋ค์ ํฉ: " << sum << endl;
	}
};

int main()
{
	Yahoo yy(5, 3);  // 8 ์ถ๋ ฅ
}
---------------------------------------------------------------------------
  
 ๐๐ ์ฝ๋ ๋ถ์ํด๋ณด๊ธฐ !!!!!
  
#include <iostream>
using namespace std;

class SoBase
{
private:
	int baseNum;
public:
	SoBase() : baseNum(20)
	{
		cout << "SoBase()" << endl;
	}
	SoBase(int n) : baseNum(n)
	{
		cout << "SoBase(int n)" << endl;
	}
	void ShowBaseDate()
	{
		cout << baseNum << endl;
	}
};

class SoDerived : public SoBase
{
private:
	int derivNum;
public:
	SoDerived() : derivNum(30)
	{
		cout << "SoDerived()" << endl;
	}
	SoDerived(int n) : derivNum(n)
	{
		cout << "SoDerived()" << endl;
	}
	SoDerived(int n1, int n2) : SoBase(n1), derivNum(n2)
	{
		cout << "SoDerived(int n1, int n2)" << endl;
	}
	void ShowDerivData()
	{
		ShowBaseDate();
		cout << derivNum << endl;
	}
};

int main()
{
	cout << "case1... " << endl;
	SoDerived dr1;
	dr1.ShowDerivData();
	cout << "-----------------------" << endl;
	cout << "case2... " << endl;
	SoDerived dr2(12);
	dr2.ShowDerivData();
	cout << "-----------------------" << endl;
	cout << "case3... " << endl;
	SoDerived dr3(23, 24);
	dr3.ShowDerivData();

	return 0;
}
  

                
        ๐๐ ํต์ฌ! // ๐๐ ์ ๋ ํด๋์ค์ ๊ฐ์ฒด์์ฑ ๊ณผ์ ์์ ๊ธฐ์ด ํด๋์ค์ ์์ฑ์๋ 100% ํธ์ถ๋๋ค.. !!
                    //      ์ ๋ ํด๋์ค์ ์์ฑ์์์ ๊ธฐ์ด ํด๋์ค์ ์์ฑ์ ํธ์ถ์ ๋ช์ํ์ง ์์ผ๋ฉด, ๊ธฐ์ด ํด๋์ค์ void ์์ฑ์๊ฐ ํธ์ถ๋๋ค.. !!
  

/*                                          
  ์ถ๋ ฅ๊ฒฐ๊ณผ:     case1...
                SoBase()
                SoDerived()
                20
                30
                -----------------------
                case2...
                SoBase()
                SoDerived()
                20
                12
                -----------------------
                case3...
                SoBase(int n)
                SoDerived(int n1, int n2)
                23
                24
        
*/
          
          
          
          โ ๊ธฐ์ด ํด๋์ค์ ์์ฑ์์ ์ ๋ ํด๋์ค์ ์์ฑ์๊ฐ ๋ชจ๋ ํธ์ถ๋๋ค๋ ์ฌ์ค์,
              
             "ํด๋์ค์ ๋ฉค๋ฒ๋ ํด๋น ํด๋์ค์ ์์ฑ์๋ฅผ ํตํด์ ์ด๊ธฐํํด์ผ ํ๋ค." ๋ผ๋ ๊ธฐ๋ณธ ์์น์ ์ง์ผ์ผ ํจ์ ์ ์๊ฐ ์๋ค.. !!
          
          
          
          
