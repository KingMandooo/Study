  π’ κ°μ²΄κ° λμμ°μ°μ λΉλ°: λν΄νΈ λμ μ°μ°μ
  
  - μ μνμ§ μμΌλ©΄ λν΄νΈ λ³΅μ¬ μμ±μκ° μ½μλλ€.
  - λν΄νΈ λ³΅μ¬ μμ±μλ λ©€λ² λ λ©€λ²μ λ³΅μ¬(μμ λ³΅μ¬)λ₯Ό μ§ννλ€.
  - μμ±μ λ΄μμ λμ  ν λΉμ νλ€λ©΄, κ·Έλ¦¬κ³  κΉμ λ³΅μ¬κ° νμνλ€λ©΄ μ§μ  μ μν΄μΌ νλ€.
    
    
  - μ μνμ§ μμΌλ©΄ λν΄νΈ λμ μ°μ°μκ° μ½μλλ€.
  - λν΄νΈ λμ μ°μ°μλ λ©€λ² λ λ©€λ²μ λ³΅μ¬(μμ λ³΅μ¬)λ₯Ό μ§ννλ€.
  - μ°μ°μ λ΄μμ λμ  ν λΉμ νλ€λ©΄, κ·Έλ¦¬κ³  κΉμ λ³΅μ¬κ° νμνλ€λ©΄ μ§μ  μ μν΄μΌ νλ€.
    
                           ππ λν΄νΈ λμ μ°μ°μμ λν΄νΈ λ³΅μ¬ μμ±μλ μ μ¬νλ€.
                                νμ§λ§ λΉμ°ν μ°¨μ΄λ μ‘΄μ¬νλ€. λ°λ‘ λμ νΈμΆμμ μ΄ λ€λ₯΄λ€λ κ²μ΄λ€.

#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)    
	{
		cout << "μμ±μ νΈμΆ" << endl;
	}
	void ShowPosition() const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
	Point(Point& ref) : xpos(ref.xpos), ypos(ref.ypos)
	{
		cout << "λ³΅μ¬μμ±μ νΈμΆ" << endl; 
	}
	Point& operator=(Point& ref)          // β coutλ₯Ό μ¬μ©νμ€μ λΉΌλ©΄ λν΄νΈ λμμ°μ°μλ μ΄λ κ² μ μλμ΄μλ€.
	{
		cout << "λμ μ°μ°μ νΈμΆ" << endl;
		xpos = ref.xpos;
		ypos = ref.ypos;
		return *this;
	}
};                                      

int main()
{
	Point aa(3, 5);           // ππ μ΄λ―Έ μμ± λ° μ΄κΈ°νκ° μ§νλ κ°μ²΄λ λ κ°μ²΄κ°μ λμμ°μ° μμλ λμ μ°μ°μκ° νΈμΆλλ€.
	Point bb(1, 2);
	bb = aa;                  // ππ μ¬κΈ°μ λμμ°μ°μλ μ€λ²λ‘λ©λ λμμ°μ°μμ΄λ€. 

  // Point cc = aa;         <-- ππ μ΄λ°μμΌλ‘ λμ΄μλ€λ©΄ μ¬κΈ°μλ λ³΅μ¬μμ±μλ₯Ό νΈμΆνλ€.
                             //      μλνλ©΄ ccλ μμ±κ³Ό μ΄κΈ°νκ° μ§νλμ§ μμκΈ° λλ¬Έμ΄λ€.
	aa.ShowPosition();
	bb.ShowPosition();
                                  // β 	bb = aa;  μ°λ¦¬λ μ΄λ κ² λμ μ°μ°μ΄ κ°λ₯ν κ²μλ³΄κ³  
	return 0;                       //     "μ΄λΌ? λμΌν μλ£νμ λ κ°μ²΄κ°μ λμμ°μ°μ΄ νμ©λλ€!" λΌκ³  μκ°νλ©΄ νμλ€.
}                                 //      μ΄λ λ¨μν λμμ°μ°μ΄ μλ, λμ μ°μ°μλ₯Ό μ€λ²λ‘λ© ν ν¨μμ νΈμΆμ΄κΈ° λλ¬Έμ΄λ€.
    
/*
  μΆλ ₯κ²°κ³Ό:   μμ±μ νΈμΆ 
              μμ±μ νΈμΆ
              λμ μ°μ°μ νΈμΆ
              [3, 5]
              [3, 5]
*/

-----------------------------------------------------------------------------------
  
π’ λν΄νΈ λμ μ°μ°μμ λ¬Έμ μ 

  --> μ΄ λΆλΆμ λν΄μλ Chapter 05μμ μ΄λ―Έ μΈκΈμ΄ λμλ€.
      κ·Έλ¦¬κ³  λν΄νΈ λμ μ°μ°μλ μ΄μ κ°μ λ¬Έμ λ₯Ό μΌκΈ°ν  κ°λ₯μ±μ΄ μλ€.
      μ΄ λ§μ λν΄νΈ λμ μ°μ°μλ κΉμ λ³΅μ¬λ₯Ό ν  μ μλλ‘ μ μλ₯Ό ν΄μ€μΌνλ€λ κ²μ΄λ€.
      
      
#include <iostream>
using namespace std;

class Person
{
private:
	char* name;
	int age;
public:
	Person(char* myname, int myage)
	{
		name = new char[strlen(myname) + 1];
		strcpy(name, myname);
		age = myage;
	}
	void ShowPersonInfo() const 
	{
		cout << "μ΄λ¦: " << name << endl;
		cout << "λμ΄: " << age <<  endl;
	}
	~Person()
	{
		delete[] name;
		cout << "called destructor!" << endl;
	}
};

int main()
{
	Person man1("Lee dong woo", 29);
	Person man2("Yoon ji yul", 22);
	man2 = man1;

	man1.ShowPersonInfo();
	man2.ShowPersonInfo();

	return 0;                              // ππ μΆλ ₯κ²°κ³Όλ₯Ό λ³΄λ©΄ μλ©Έμκ° ν λ² λ°μ νΈμΆμ΄ μλ κ²μ λ³Ό μ μλ€.
}                                        //       μ΄λ λν΄νΈ λμ μ°μ°μκ° μμ λ³΅μ¬λ‘ ν΅ν΄ λ©€λ² λ λ©€λ²μ λ³΅μ¬λ₯Ό νκΈ° λλ¬Έμ΄λ€.
                                         //       μ¦, κ° κ°μ²΄μ ν¬μΈν° λ©€λ²λ³μμΈ nameμ΄ κ°μ κ³΅κ°μ κ°λ¦¬ν€λ μν©μ΄ λ°μνμ¬
                                         //       "Yoon ji yul"λ₯Ό κ°μ§κ³  μλ λ©λͺ¨λ¦¬κ° λμκ° λ°μνλ μν©μ΄ μΌμ΄λλ€.
/*
  μΆλ ₯κ²°κ³Ό:   μ΄λ¦: Lee dong woo
              λμ΄: 29
              μ΄λ¦: Lee dong woo
              λμ΄: 29
              called destructor!     
*/


                  Person& operator=(Person& ref)           // β μ΄λ₯Ό ν΄κ²°νκΈ° μν΄μ Person ν΄λμ€μ μ΄ μ½λλ₯Ό μΆκ°ν΄μ€μΌνλ€.
                  {
                    delete[] name;  // λ³Έλ nameμ΄ κ°λ¦¬ν€λ λ©λͺ¨λ¦¬ ν΄μ  
                    name = new char[strlen(ref.name) + 1]; // μλ‘μ΄ μλ§λ κΈΈμ΄μ λ©λͺ¨λ¦¬ κ³΅κ° ν λΉ
                    strcpy(name, ref.name);  // λ©λͺ¨λ¦¬ κ³΅κ°μ λ¬Έμμ΄ λ³΅μ¬
                    age = ref.age;
                    return *this;
                  }

-----------------------------------------------------------------------------------
  
π’ μμ κ΅¬μ‘°μμμ λμ μ°μ°μ νΈμΆ

  --> ππ μ λ ν΄λμ€μ λμ μ°μ°μμλ μλ¬΄λ° λͺμλ₯Ό νμ§ μμΌλ©΄, κΈ°μ΄ ν΄λμ€μ λμ μ°μ°μκ° νΈμΆλμ§ μλλ€.

	
#include <iostream>
using namespace std;

class First
{
private:
	int num1, num2;
public:
	First(int n1 = 0, int n2 = 0) : num1(n1), num2(n2)
	{}
	void ShowData() { cout << num1 << ", " << num2 << endl; }

	First& operator=(const First& ref)
	{
		cout << "First& operator=()" << endl;
		num1 = ref.num1;
		num2 = ref.num2;
		return *this;
	}
};

class Second : public First
{
private:
	int num3, num4;
public:
	Second(int n1, int n2, int n3, int n4) : First(n1, n2), num3(n3), num4(n4)
	{}
	void ShowData()
	{
		First::ShowData();
		cout << num3 << ", " << num4 << endl;
	}
};

int main()
{
	Second ssrc(111, 222, 333, 444);
	Second scpy(0, 0, 0, 0);
	scpy = ssrc;                  // scpy.operator=(ssrc); <-- μ¬κΈ°μ Second ν΄λμ€μ λν΄νΈ λμ μ°μ°μκ° νΈμΆλλ€.
	scpy.ShowData();              //                           κ·Έλ¦¬κ³  κ·Έ λν΄νΈ λμ μ°μ°μκ° κΈ°μ΄ ν΄λμ€μ λμ μ°μ°μκΉμ§ νΈμΆν΄μ€λ€.

	return 0;
}

                                          ππ μ λ ν΄λμ€μ λν΄νΈ λμ μ°μ°μλ κΈ°μ΄ ν΄λμ€μ λμ μ°μ°μκΉμ§ νΈμΆνλ€λ μ¬μ€μ μ μ μλ€.
/*                                             μ΄κ±° μ μ΄ν΄ν΄μΌ νλ€.
  μΆλ ₯κ²°κ³Ό:     First& operator=()  
		111, 222
		333, 444
*/
------------------------------------------------
						  
#include <iostream>
using namespace std;

class First
{
private:
	int num1, num2;
public:
	First(int n1 = 0, int n2 = 0) : num1(n1), num2(n2)
	{}
	void ShowData() { cout << num1 << ", " << num2 << endl; }

	First& operator=(const First& ref)
	{
		cout << "First& operator=()" << endl;
		num1 = ref.num1;
		num2 = ref.num2;
		return *this;
	}
};

class Second : public First
{
private:
	int num3, num4;
public:
	Second(int n1, int n2, int n3, int n4) : First(n1, n2), num3(n3), num4(n4)
	{}
	void ShowData()
	{
		First::ShowData();
		cout << num3 << ", " << num4 << endl;
	}

	Second& operator=(const Second& ref)                // ππ μ¦, μ΄λ κ² μ λ ν΄λμ€μ λμ μ°μ°μλ₯Ό μ μν΄μΌ νλ κ²½μ°μλ 
	{                                                   //       κΈ°μ΄ ν΄λμ€μ λμ μ°μ°μλ₯Ό λͺμμ μΌλ‘ νΈμΆν΄μΌ νλ€.
	
		First::operator=(ref);  // ππκΈ°μ΄ ν΄λμ€ λμ μ°μ°μ λͺμμ μΌλ‘ νΈμΆ.  λ§μ½ μ΄κ² μμΌλ©΄,
		cout << "Second& operator=()" << endl;                                // λΉμ°ν Second κ°μ²΄μ num1κ³Ό num2λ μ΄κΈ°ν λμ§ μλλ€.
		num3 = ref.num3;
		num4 = ref.num4;
		return *this;
	}
};

int main()
{
	Second ssrc(111, 222, 333, 444);
	Second scpy(0, 0, 0, 0);
	scpy = ssrc;
	scpy.ShowData();

	return 0;
}

/*                                           
  μΆλ ₯κ²°κ³Ό:     First& operator=()  
		111, 222
		333, 444
*/

------------------------------------------------------------------------------------------------
	
π’ μ΄λμλΌμ΄μ κ° μ±λ₯ ν₯μμ λμμ μ€λ€κ³  νλ κ²μ κΈ°μ΅νλμ?
	
#include <iostream>
using namespace std;

class AAA
{
private:
	int num; 
public:
	AAA(int n = 0) : num(n)      // ππ int num = n   -->   AAAμ μμ±μ νΈμΆ
	{
		cout << "AAA(int n = 0)" << endl;
	}
	AAA(const AAA& ref) : num(ref.num)
	{
		cout << "AAA(const AAA& ref)" << endl;
	}
	AAA& operator=(const AAA& ref)
	{
		num = ref.num;
		cout << "operator=(const AAA& ref)" << endl;
		return *this;
	}
};

class BBB
{
private:
	AAA mem;
public:
	BBB(const AAA& ref) : mem(ref) {}   // ππ AAA mem = ref  -->  AAAμ λ³΅μ¬ μμ±μ νΈμΆ
};

class CCC
{
private:
	AAA mem;                             // AAAλ μ΄λ―Έ μμ± λ° μ΄κΈ°νκ° μ§νλ κ°μ²΄μ΄λ―λ‘ μ¬κΈ°μμ '='μ λμ μ°μ°μλ₯Ό νΈμΆνλ€.
public:
	CCC(const AAA& ref) { mem = ref; }   // ππ AAA mem;      -->  AAAμ μμ±μ νΈμΆ
};                                           //      mem = ref;    -->  AAAμ λμμ°μ°μ νΈμΆ

int main()
{
	AAA obj1(12);
	cout << "********************" << endl;
	BBB obj2(obj1);
	cout << "********************" << endl;
	CCC obj3(obj1);

	return 0;        
}
                                          β μ΄λ λ― μ μ½λμμ λ³΄μλ―μ΄ μ΄λμλΌμ΄μ λ₯Ό μ΄μ©ν΄μ μ΄κΈ°νλ₯Ό μ§ννλ©΄,
                                              ν¨μμ νΈμΆνμλ₯Ό μ€μΌ μ μμ΄μ, κ·Έλ¦¬κ³  μ΄κΈ°νμ κ³Όμ μ λ¨μνμν¬ μ μμ΄μ
					      μ½κ°μ μ±λ₯ν₯μμ κΈ°λν  μ μλ€.
/*                                           
  μΆλ ₯κ²°κ³Ό:     AAA(int n = 0)
		********************
		AAA(const AAA& ref)
		********************
		AAA(int n = 0)
		operator=(const AAA& ref)
*/

------------------------------------------------------------------------------------------------
π  λ¬Έμ  11-1(1)

π λ΄κ° νΌ λ°©μ π

#include <iostream>
#include <cstring>                          
using namespace std;

class Gun
{
private:
	int bullet;
public:
	Gun(int bnum) : bullet(bnum) {}
	int GetBullet() { return bullet; }  // μ΄μ κ°μ Έμ€λ ν¨μ μΆκ°
	void Shot()
	{
		cout << "BBang!" << endl;
		bullet--;
	}
};

class Police      
{
private:
	int handcuffs;
	Gun* pistol;
public:
	Police(int bnum, int bcuff) : handcuffs(bcuff)
	{
		if (bnum > 0)
			pistol = new Gun(bnum);
		else
			pistol = NULL;
	}
	Police(Police& copy)  // λ³΅μ¬ μμ±μ
	{
		handcuffs = copy.handcuffs;
		pistol = new Gun(copy.pistol->GetBullet());
	}
	Police& operator=(Police& ref) // λμ μ°μ°μ
	{
		delete pistol;
		handcuffs = ref.handcuffs;
		pistol = new Gun(ref.pistol->GetBullet());
		return *this;
	}
	void PutHandcuff()
	{
		cout << "SNAP!" << endl;
		handcuffs--;
	}
	void Shot()
	{
		if (pistol == NULL)
			cout << "No Gun!!" << endl;
		else
			pistol->Shot();
	}
	~Police()
	{
		if (pistol != NULL)
			delete pistol;
	}
};

int main()
{
	Police pman1(5, 3);

	//Police pman2 = pman1;

	Police pman2(1, 2);
	pman2 = pman1;

	pman2.Shot();
	pman2.PutHandcuff();

	return 0;
}

----------------------------------------------------------
π λ΅μ§ π

#include <iostream>
#include <cstring>                          
using namespace std;

class Gun
{
private:
	int bullet;
public:
	Gun(int bnum) : bullet(bnum) {}
	Gun(Gun& copy) : bullet(copy.bullet)  // λ΄κ° μΆκ°ν λ³΅μ¬μμ±μ (νΈμΆλλμ§ νμΈμ©)
	{
		cout << "λ³΅μ¬μμ±μ    γγ " << endl;
	}
	void Shot()
	{
		cout << "BBang!" << endl;
		bullet--;
	}
};

class Police
{
private:
	int handcuffs;
	Gun* pistol;
public:
	Police(int bnum, int bcuff) : handcuffs(bcuff)
	{
		if (bnum > 0)
			pistol = new Gun(bnum);
		else
			pistol = NULL;
	}
	Police(Police& copy)  // λ³΅μ¬ μμ±μ
	{
		handcuffs = copy.handcuffs;
		pistol = new Gun(*(copy.pistol)); // Gunμ λ³΅μ¬μμ±μ νΈμΆ
	}

	// pistol = new Gun(*(copy.pistol)); μ΄κ² λ¬΄μ¨ λ»μΌκΉ? 
	// κ·ΈλκΉ λ΄κ° κΆκΈνκ±΄ μ * λ₯Ό λΆμ¬μ£Όλ κ±ΈκΉ?
	// copy.pistolμ pos1.pistolμ΄κ³  pistolμ μ£Όμ κ°μΌνκ³ ,
	// κ·Έλ λ€λ©΄ *(copy.pistol), *(pos1.pistol)μ λ­μ§?
	// copy.pistol(κ°μ²΄μ μ£Όμ)μ΄ κ°λ¦¬ν€λ κ°μ²΄μ΄κ² λ€.
	// pistolμλ μ£Όμκ°μ΄ μ μ₯ λΌ. Gunμ κ°μ²΄μ μ£Όμκ°μ΄ μ μ₯ λΌ.
	// μ΄λ₯Ό κ°λ¦¬ν€λ ννμ *(copy.pistol) μ΄κ±°μΌ.
	// κ·Έλ¦¬κ³  Gunμ λ³΅μ¬μμ±μμμ Gun& copyλ μ°Έμ‘°μμ΄λ―λ‘ κ°μ λ°μμΌ λΌ.
	// λ°λΌμ ν¬μΈν°κ° λΆμ΄μΌ λΌ.
	// int num = 3;
	// int& num2 = num;  μ΄λ κ² κ°μ λ°μμ. μ°Έμ‘°μλ.
	// κ·Έλ λ€λ©΄ μ΄μ  μ΄ν΄ν  μ μμ΄.
	// pistol = new Gun(*(copy.pistol)); μ pistolμ μλ‘μ΄ λ§€λͺ¨λ¦¬λ₯Ό μ°Έμ‘°νλλ‘ ν¨κ³Ό λμμ
	// Gun ν΄λμ€μ λ³΅μ¬μμ±μλ₯Ό νΈμΆνλ κ±°μΌ. κ·Έλ¬λ©΄ Gunμ κ°μ²΄μΈ pistolμ λ©€λ²λ³μ bulletμ΄
	// λ³΅μ¬κ° λκ² μ§.
	
	Police& operator=(Police& ref) // λμ μ°μ°μ
	{
		delete pistol;
		handcuffs = ref.handcuffs;
		pistol = new Gun(*(ref.pistol));  // Gunμ λ³΅μ¬μμ±μ νΈμΆ
		return *this;
	}
	void PutHandcuff()
	{
		cout << "SNAP!" << endl;
		handcuffs--;
	}
	void Shot()
	{
		if (pistol == NULL)
			cout << "No Gun!!" << endl;
		else
			pistol->Shot();
	}
	~Police()
	{
		if (pistol != NULL)
			delete pistol;
	}
};

int main()
{
	Police pman1(5, 3);
	Police pman2 = pman1;
	Police pman3(4, 7);
	pman3 = pman1;

	pman2.Shot();
	pman2.PutHandcuff();

	return 0;
}



π  λ¬Έμ  11-1(2)

#include <iostream>
#include <cstring>
using namespace std;

class Book
{
private:
	char* title;  // μ± μ λͺ©
	char* isbn;   // κ΅­μ νμ€λμλ²νΈ
	int price;    // μ±μ μ κ°
public:
	Book(char* title, char* isbn, int price) : price(price)
	{
		this->title = new char[strlen(title) + 1];
		strcpy(this->title, title);

		this->isbn = new char[strlen(isbn) + 1];
		strcpy(this->isbn, isbn);
	}
	Book(Book& copy) : price(copy.price)
	{
		title = new char[strlen(copy.title) + 1];
		strcpy(title, copy.title);

		isbn = new char[strlen(copy.isbn) + 1];
		strcpy(isbn, copy.isbn);
	}
	Book operator=(Book& ref)
	{
		delete[] title;
		delete[] isbn;
		title = new char[strlen(ref.title) + 1];
		strcpy(title, ref.title);

		isbn = new char[strlen(ref.isbn) + 1];
		strcpy(isbn, ref.isbn);

		price = ref.price;

		return *this;
	}
	void ShowBookInfo()
	{
		cout << "μ λͺ©: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "κ°κ²©: " << price << endl;
	}
	~Book()
	{
		delete[] title;
		delete[] isbn;
	}
};

class EBook : public Book
{
private:
	char* DRMKey;  // λ³΄μκ΄λ ¨ ν€
public:
	EBook(char* title, char* isbn, int price, char* DRMKey) : Book(title, isbn, price)
	{
		this->DRMKey = new char[strlen(DRMKey) + 1];
		strcpy(this->DRMKey, DRMKey);
	}
	EBook(EBook& copy) : Book(copy)
	{
		DRMKey = new char[strlen(copy.DRMKey) + 1];
		strcpy(DRMKey, copy.DRMKey);
	}
	EBook operator=(EBook& ref)
	{
		Book::operator=(ref);
		delete[] DRMKey;
		DRMKey = new char[strlen(ref.DRMKey) + 1];
		strcpy(DRMKey, ref.DRMKey);

		return *this;
	}
	void ShowEBookInfo()
	{
		ShowBookInfo();
		cout << "μΈμ¦ν€: " << DRMKey << endl;
	}
	~EBook()
	{
		delete[] DRMKey;
	}
};

int main()
{
	EBook ebook1("μ’μ C++ ebook", "555-12345-890-1", 10000, "fdx9wi8kiw");
	//EBook ebook2 = ebook1;

	EBook ebook2("λν΄λ μΉ", "335-12345-890-1", 7000, "AA9cwi8sc5w");
	ebook2 = ebook1;  // ebook.operator=(ebook1);

	ebook2.ShowEBookInfo();

	return 0;
}
----------------------------------------------------------------------------------------------------
	
π  λ¬Έμ  11-1(1) λ³΅μ΅
	
#include <iostream>
#include <cstring>                          
using namespace std;

class gun
{
private:
	int bullet;
public:
	gun(int bnum) : bullet(bnum) {}
	void shot()
	{
		cout << "bbang!" << endl;
		bullet--;
	}
};

class police      
{
private:
	int handcuffs;
	gun* pistol;
public:
	police(int bnum, int bcuff) : handcuffs(bcuff)
	{
		if (bnum > 0)
			pistol = new gun(bnum);
		else
			pistol = null;
	}
	// κΉμ μ°Έμ‘°λ₯Ό μν λ³΅μ¬μμ±μ
	police(police& copy) : handcuffs(copy.handcuffs)
	{
		pistol = new gun(*(copy.pistol));
	}
	// κΉμ μ°Έμ‘°λ₯Ό μν λμ μ°μ°μ
	police& operator=(police& ref)
	{
		delete[] pistol;
		pistol = new gun(*(ref.pistol));
		handcuffs = ref.handcuffs;
		return *this;
	}
	void puthandcuff()
	{
		cout << "snap!" << endl;
		handcuffs--;
	}
	void shot()
	{
		if (pistol == null)
			cout << "no gun!!" << endl;
		else
			pistol->shot();
	}
	~police()
	{
		if (pistol != null)
			delete pistol;
	}
};

int main()
{
	police pman1(5, 3);
	police pman2 = pman1;
	police pman3(10, 7);
	pman2 = pman3;

	pman2.shot();
	pman2.puthandcuff();

	return 0;
}



π  λ¬Έμ  11-1(2) λ³΅μ΅	

#include <iostream>
#include <cstring>
using namespace std;

class Book
{
private:
	char* title;  // μ± μ λͺ©
	char* isbn;   // κ΅­μ νμ€λμλ²νΈ
	int price;    // μ±μ μ κ°
public:
	Book(char* title, char* isbn, int price) : price(price)
	{
		this->title = new char[strlen(title) + 1];
		strcpy(this->title, title);

		this->isbn = new char[strlen(isbn) + 1];
		strcpy(this->isbn, isbn);
	}
	Book(Book& copy) : price(copy.price)
	{
		title = new char[strlen(copy.title) + 1];
		strcpy(title, copy.title);

		isbn = new char[strlen(copy.isbn) + 1];
		strcpy(isbn, copy.isbn);
	}
	Book& operator=(Book& ref)
	{
		delete[] title;
		delete[] isbn;

		title = new char[strlen(ref.title) + 1];
		strcpy(title, ref.title);

		isbn = new char[strlen(ref.isbn) + 1];
		strcpy(isbn, ref.isbn);

		price = ref.price;
		return *this;
	}
	void ShowBookInfo()
	{
		cout << "μ λͺ©: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "κ°κ²©: " << price << endl;
	}
	~Book()
	{
		delete[] title;
		delete[] isbn;
	}
};

class EBook : public Book
{
private:
	char* DRMKey;  // λ³΄μκ΄λ ¨ ν€
public:
	EBook(char* title, char* isbn, int price, char* DRMKey) : Book(title, isbn, price)
	{
		this->DRMKey = new char[strlen(DRMKey) + 1];
		strcpy(this->DRMKey, DRMKey);
	}
	EBook(EBook& copy) : Book(copy)
	{
		DRMKey = new char[strlen(copy.DRMKey) + 1];
		strcpy(DRMKey, copy.DRMKey);
	}
	/*
	EBook ν΄λμ€μλ§ λ³΅μ¬μμ±μλ₯Ό λ§λ€μ΄λλ©΄ "Book ν΄λμ€μ κΈ°λ³Έ μμ±μκ° μλ€"λΌλ μ€λ₯κ° λ¬λ€.
	λ¬΄μ¨ λ»μΌκΉ?

	--> κ·Έλ₯ κΈ°μ΄ ν΄λμ€ Bookμ λ©€λ²λ μ΄κΈ°νλ₯Ό ν΄λ¬λΌλ λ».
	*/
	EBook& operator=(EBook& ref)
	{
		Book::operator=(ref);
		delete[] DRMKey;
		DRMKey = new char[strlen(ref.DRMKey) + 1];
		strcpy(DRMKey, ref.DRMKey);
		return *this;
	}
	void ShowEBookInfo()
	{
		ShowBookInfo();
		cout << "μΈμ¦ν€: " << DRMKey << endl;
	}
	~EBook()
	{
		delete[] DRMKey;
	}
};

int main()
{
	EBook ebook1("μ’μ C++ ebook", "555-12345-890-1", 10000, "fdx9wi8kiw");

	EBook ebook2 = ebook1;
	ebook2.ShowEBookInfo();

	EBook ebook3("μ’μ Python ebook", "666-125145-890-1", 12000, "as9wi8kiw");
	ebook3 = ebook1;
	ebook3.ShowEBookInfo();


	return 0;
}
