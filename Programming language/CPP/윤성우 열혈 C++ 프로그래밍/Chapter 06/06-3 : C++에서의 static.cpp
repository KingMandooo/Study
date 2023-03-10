    
      ๐ C์ธ์ด์์์ static
           
          - ์ ์ญ๋ณ์์ ์ ์ธ๋ static์ ์๋ฏธ
            
              --> ์ ์ธ๋ ํ์ผ ๋ด์์๋ง ์ฐธ์กฐ๋ฅผ ํ์ฉํ๊ฒ๋ค๋ ์๋ฏธ
              
          - ํจ์ ๋ด์ ์ ์ธ๋ static์ ์๋ฏธ
          
              --> ํ๋ฒ๋ง ์ด๊ธฐํ๋๊ณ  ์ง์ญ๋ณ์์ ๋ฌ๋ฆฌ ํจ์๋ฅผ ๋น ์ ธ๋๊ฐ๋ ์๋ฉธ๋์ง ์๋๋ค.
        
--------------------------------------------------------------------------------------

๐ข static ๋ฉค๋ฒ๋ณ์(ํด๋์ค ๋ณ์)

#include <iostream>
using namespace std;

void Counter()
{
	static int cnt;  // static ๋ณ์๋ ์ ์ญ๋ณ์์ ๋ง์ฐฌ๊ฐ์ง๋ก ์ด๊ธฐํ๋ฅผ ์ํ๋ฉด ์๋์ผ๋ก 0์ผ๋ก ์ด๊ธฐํ.
	cout << "Current cnt: " << ++cnt << endl;
}

int main()
{
	for (int i = 0; i < 10; i++)
		Counter();

	return 0;
}

----------------------------------------------------

#include <iostream>
using namespace std;

int simObjCnt = 0;         // ์ ์ญ๋ณ์ ์ ์ธ
int cmxObjCnt = 0;

class SoSimple
{
public:
	SoSimple()
	{
		simObjCnt++;
		cout << simObjCnt << "๋ฒ์งธ SoSimple ๊ฐ์ฒด" << endl;
	}
};                           // ๐๐ ์ ์ญ๋ณ์ simObjCnt์ cmxObjCnt๋ ๊ฐ์ฒด๋ค์ด ๊ณต์ ํ๋ ๋ณ์๋ค.
                             //       ์ด ๋์ ๋ชจ๋ ์ ์ญ๋ณ์์ด๊ธฐ ๋๋ฌธ์ ์ด๋์๋  ์ ๊ทผ์ด ๊ฐ๋ฅํ๋ฏ๋ก ๋ฌธ์ ๋ฅผ ์ผ์ผํฌ ์๋ ์๋ค.
class SoComplex              //       ๋ฐ๋ผ์ ์ด๋ฅผ ๋ณด์ํ๊ธฐ ์ํด static ํค์๋๋ฅผ ์ฌ์ฉํ๋ค.
{
public:
	SoComplex()
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "๋ฒ์งธ SoComplex ๊ฐ์ฒด" << endl;
	}

	SoComplex(SoComplex& copy)
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "๋ฒ์งธ SoComplex ๊ฐ์ฒด" << endl;
	}
};

int main()
{
	SoSimple sim1;
	SoSimple sim2;

	SoComplex com1;
	SoComplex com2 = com1;
	SoComplex();

	return 0;
}


/*
  ์คํ๊ฒฐ๊ณผ: 1๋ฒ์งธ SoSimple ๊ฐ์ฒด
            2๋ฒ์งธ SoSimple ๊ฐ์ฒด
            1๋ฒ์งธ SoComplex ๊ฐ์ฒด
            2๋ฒ์งธ SoComplex ๊ฐ์ฒด
            3๋ฒ์งธ SoComplex ๊ฐ์ฒด
*/

----------------------------------------------------
  
class SoSimple
{
private:
	static int simObjCnt;
public:
	SoSimple()
	{
		simObjCnt++;
		cout << simObjCnt << "๋ฒ์งธ SoSimple ๊ฐ์ฒด" << endl;
	}
};
int SoSimple::simObjCnt = 0;   
 // ๐๐ static ๋ฉค๋ฒ ๋ณ์๋ ๋ชจ๋  ๊ฐ์ฒด๊ฐ ๊ณต์ ํด์ผ ํ๋ฏ๋ก ํ๋ก๊ทธ๋จ ์ ์ฒด ์์ญ์์ ๋ฉ๋ชจ๋ฆฌ ์ ์ง๊ฐ ๋์ผ ํ๋ค. 
 //      ๋ฐ๋ผ์ ๋ฐ๋์ ์ ์ญ ๋ฒ์์์ ์ ์ ๋ฐ ์ด๊ธฐํ๋ฅผ ํด์ฃผ์ด์ผ ํ๋ค.

int main()
{
   SoSimple sim1;     // ๐๐ sim1, sim2, sim3 ๊ฐ์ฒด๊ฐ static ๋ณ์ simObjCnt๋ฅผ ๊ณต์ ํ๋ ๊ตฌ์กฐ๊ฐ ๋๋ค. 
   SoSimple sim2;     //      ํ์ง๋ง ๊ทธ๋ ๋ค๊ณ  ํด์ ๊ฐ์ฒด ๋ด์ simObjCnt๊ฐ ์กด์ฌํ๋ ๊ฒ์ ์๋๋ค.
   SoSimple sim3;     //      ์ด ๋ณ์๋ ๊ฐ์ฒด ์ธ๋ถ์ ์๋ค. ๋ค๋ง ๊ฐ์ฒด์๊ฒ ๋ฉค๋ฒ๋ณ์์ฒ๋ผ ์ ๊ทผํ  ์ ์๋ ๊ถํ์ ์คฌ์ ๋ฟ์ด๋ค.
}

----------------------------------------------------
  
// static ๋ฉค๋ฒ๋ณ์๋ ๊ฐ์ฒด ๋ด์ ์กด์ฌํ์ง ์๋๋ค๋ ์ฌ์ค์ ๋ช์ฌํ์.  
  
#include <iostream>
using namespace std;

class SoSimple
{
private:
	static int simObjCnt;
public:
	SoSimple()
	{
		simObjCnt++;
		cout << simObjCnt << "๋ฒ์งธ SoSimple ๊ฐ์ฒด" << endl;
	}
};
int SoSimple::simObjCnt = 0;  // static ๋ฉค๋ฒ๋ณ์ ์ด๊ธฐํ

class SoComplex
{
private:
	static int cmxObjCnt;
public:
	SoComplex()
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "๋ฒ์งธ SoComplex ๊ฐ์ฒด" << endl;
	}

	SoComplex(SoComplex& copy)
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "๋ฒ์งธ SoComplex ๊ฐ์ฒด" << endl;
	}
};
int SoComplex::cmxObjCnt = 0;   // static ๋ฉค๋ฒ๋ณ์ ์ด๊ธฐํ

int main()
{
	SoSimple sim1;
	SoSimple sim2;

	SoComplex com1;
	SoComplex com2 = com1;
	SoComplex();

	return 0;
}


/*
  ์คํ๊ฒฐ๊ณผ: 1๋ฒ์งธ SoSimple ๊ฐ์ฒด
            2๋ฒ์งธ SoSimple ๊ฐ์ฒด
            1๋ฒ์งธ SoComplex ๊ฐ์ฒด
            2๋ฒ์งธ SoComplex ๊ฐ์ฒด
            3๋ฒ์งธ SoComplex ๊ฐ์ฒด
*/

----------------------------------------------------
  
#include <iostream>
using namespace std;

class SoSimple
{
public:                // ๐๐ ์ด๋ ๊ฒ static ๋ฉค๋ฒ๋ณ์๋ฅผ public์ผ๋ก ์ ์ธํ๋ฉด ๋น์ฐํ ์ธ๋ถ์์ ์ ๊ทผ์ด ๊ฐ๋ฅํ๋ค.
	static int simObjCnt; 
public:
	SoSimple()
	{
		simObjCnt++;
	}
};
int SoSimple::simObjCnt = 0;

int main()
{
	SoSimple sim1;
	SoSimple sim2;

	cout << sim1.simObjCnt << endl;  // ์ด๋ฐ์์ผ๋ก ์ ๊ทผํ์ง๋ง์ ๋ฉค๋ฒ๋ณ์์ ํท๊ฐ๋ฆฐ๋ค.
	cout << sim2.simObjCnt << endl;
	cout << SoSimple::simObjCnt << endl;   // ๐๐ ์ด๋ ๊ฒ ํด๋์ค์ ์ด๋ฆ์ ์ด์ฉํด์ ์ ๊ทผํด์ผ ์ข๋ค.
  
  โ ์๊ฐ ::(๋ฒ์ ํ์ธ ์ฐ์ฐ์)๊ฐ ์ฐ์ด๋ ๋ฒ์๊ฐ ์ด๋ป๊ฒ ๋๋์ง ๊ถ๊ธํด์ ์ฐพ์๋ดค๋ค. (๊ผญ ํ๋ฒ ๋ด๋ฐ)
    
     --> https://learn.microsoft.com/ko-kr/cpp/cpp/scope-resolution-operator?view=msvc-170

	return 0;
}

--------------------------------------------------------------------------------------
  
๐ข static ๋ฉค๋ฒํจ์

- ์ ์ธ๋ ํด๋์ค์ ๋ชจ๋  ๊ฐ์ฒด๊ฐ ๊ณต์ ํ๋ค.
  
- public์ผ๋ก ์ ์ธ์ด ๋๋ฉด, ํด๋์ค์ ์ด๋ฆ์ ์ด์ฉํด์ ํธ์ถ์ด ๊ฐ๋ฅํ๋ค.
  
- ๊ฐ์ฒด์ ๋ฉค๋ฒ๋ก ์กด์ฌํ๋ ๊ฒ์ด ์๋๋ค.  ๐๐ ์ด๊ฒ ์ค์ํด
  
  
 // โ ์๋ชป๋ ์ฝ๋ 
class SoSimple
{
private:        // public์ผ๋ก ์ ์ธํด๋ ์ค๋ฅ๋ฐ์์ ๋ง์ฐฌ๊ฐ์ง.
	int num1;
	static int num2;
public:
	SoSimple(int n) : num1(n) {}

	static void Adder(int n)
	{
		num1 += n;             // ๐๐ ์ฌ๊ธฐ์ ์ค๋ฅ๋ฐ์
		num2 += n;            
	}                        // --> static ๋ฉค๋ฒํจ์๋ ์ฌ์ค ๊ฐ์ฒด์ ๋ฉค๋ฒ๋ก ์กด์ฌํ๋ ๊ฒ์ด ์๋๋ค. (์๋๋ ์ค๋ฅ๋ฐ์์ด์ )
};                           
                                1. "๊ฐ์ฒด์ ๋ฉค๋ฒ๊ฐ ์๋๋ฐ, ์ด๋ป๊ฒ ๋ฉค๋ฒ๋ณ์์ ์ ๊ทผ์ ํ๊ฒ ๋๊ฐ?"
                                2. "๊ฐ์ฒด์์ฑ ์ด์ ์๋ ํธ์ถ์ด ๊ฐ๋ฅํ๋ค. ๊ทธ๋ฐ๋ฐ ์ด๋ป๊ฒ ๋ฉค๋ฒ๋ณ์์ ์ ๊ทผ์ด ๊ฐ๋ฅํ๊ฒ ๋๊ฐ?"
                                3. "๋ฉค๋ฒ๋ณ์์ ์ ๊ทผ์ ํ๋ค๊ณ  ์น์. ๊ทธ๋ ๋ค๋ฉด ์ด๋ค ๊ฐ์ฒด์ ๋ฉค๋ฒ๋ณ์์ ์ ๊ทผ์ ํด์ผ๊ฒ ๋๊ฐ?"
                
                     ์ด ๋ชจ๋ ๊ฒ ๊ทธ๋ฅ static ๋ฉค๋ฒ๋ ๊ฐ์ฒด์ ๋ฉค๋ฒ๋ก ์กด์ฌํ์ง ์๋๋ค๋ ๊ฒ์ ์ดํดํ๋ฉด ๋ฉ๋์ด ๋๋ค.
  
                     ๐๐ "static ๋ฉค๋ฒํจ์ ๋ด์์๋ static ๋ฉค๋ฒ๋ณ์์ static ๋ฉค๋ฒํจ์๋ง ํธ์ถ์ด ๊ฐ๋ฅํ๋ค."
                                  
--------------------------------------------------------------------------------------
  
๐ข const static ๋ฉค๋ฒ

  --> const static ๋ฉค๋ฒ๋ณ์๋, ํด๋์ค๊ฐ ์ ์๋  ๋ ์ง์ ๋ ๊ฐ์ด ์ ์ง๋๋ ์์์ด๊ธฐ ๋๋ฌธ์, 
      ์๋์ ์์ ์ฒ๋ผ ์ด๊ธฐํ๊ฐ ๊ฐ๋ฅํ๋ค.
	      
      โ์ const static ๋ฉค๋ฒ๋ณ์๋ class ๋ด๋ถ์์ ์ด๊ธฐํ๊ฐ ๊ฐ๋ฅํ๊ฑธ๊น..
	      
        --> ์ผ๋ฐ static ๋ฉค๋ฒ๋ณ์๋ ๊ฐ์ด ๋ณ๊ฒฝ์ด ๊ฐ๋ฅํ๊ธฐ์ ์ ์ญ๋ณ์์ ๊ฐ์ ๋๋์ด๋ผ ๋ฐ์์ ์ด๊ธฐํ๋ฅผ ํด์ฃผ๊ณ ,
            const static์ ํด๋์ค๊ฐ ์ ์๋  ๋ ๊ณ์ํด์ ๊ทธ ๊ฐ์ ์ ์งํ๊ธฐ ๋๋ฌธ์ class ์์์ ์ด๊ธฐํ๊ฐ ๊ฐ๋ฅํ๊ฑธ๊น??

		    
		    
#include <iostream>
using namespace std;

class CountryArea
{
public:
	const static int RUSSIA = 1707540;
	const static  int CANADA = 998467;
	const static int CHINA = 957290;
	const static int SOUTH_KOREA = 9922;
};

int main()
{
	cout << "๋ฌ์์: " << CountryArea::RUSSIA << endl;
	cout << "์บ๋๋ค: " << CountryArea::CANADA << endl;
	cout << "์ค๊ตญ: " << CountryArea::CHINA << endl;
	cout << "ํ๊ตญ: " << CountryArea::SOUTH_KOREA << endl;

	return 0;
}

--------------------------------------------------------------------------------------
   
๐ข ํค์๋ mutable     (*mutable ๋ป: ๋ณํ๊ธฐ ์ฌ์ด)
  
   --> ๐๐ const ํจ์ ๋ด์์์ ๊ฐ์ ๋ณ๊ฒฝ์ ์์ธ์ ์ผ๋ก ํ์ฉํ๋ค.
  
  
#include <iostream>
using namespace std;

class SoSimple
{
private:
	int num1;
	mutable int num2;
public:
	SoSimple(int n1, int n2) : num1(n1), num2(n2) {}

	void ShowSimpleData() const
	{
		cout << num1 << ", " << num2 << endl;
	}

	void CopyToNum2() const  // ์ด ํจ์ ๋ด์์ num1์ ๋ณ๊ฒฝํ๋ ์ผ์ด ๋ฐ์ํ์ง ์๋๋ค. 
	{
		num2 = num1;    // ๐๐ ์ด๋ ๊ฒ num2๋ฅผ ๋ณ๊ฒฝ๊ฐ๋ฅ.
	}
};                  

int main()
{
	SoSimple sm(1, 2);
	sm.ShowSimpleData();
	sm.CopyToNum2();
	sm.ShowSimpleData();

	return 0;
}
