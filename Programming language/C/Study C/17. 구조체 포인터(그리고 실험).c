      
                          ๐ ์ฐ์  ๊ตฌ์กฐ์ฒด ํฌ์ธํฐ๋ฅผ ์ ๋ฆฌํ๊ธฐ ์ ์ ์ฃผ์์ ๋ณด๋ฉด์ ๋ด๊ฐ ํท๊ฐ๋ ธ๋ ๋ถ๋ถ์ ๋ด๋ณด์.

#include <stdio.h>
#include <string.h>

struct books
{
	char name[30];
	char author[30];
	int borrowed;
};

int main()
{
	//struct books Boo;
	//printf("%p\n", Boo.name);           Boo.name์ ๋ฐฐ์ด์ด๊ธฐ ๋๋ฌธ์ ๊ทธ ์์ฒด๊ฐ ํฌ์ธํฐ ์์
	//printf("%p\n", &Boo.name);      
	//printf("%p\n", Boo.author);         ์์ ๋์ผ
	//printf("%p\n", &Boo.author);
	//printf("%d\n", Boo.borrowed);       Boo.borrowed๋ ์ ์๊ฐ์ด๊ธฐ ๋๋ฌธ์ ์ฃผ์ ๊ฐ์ด ๋ฐ๋ก ์์
	//printf("%d\n", &Boo.borrowed);

	struct books Books[3] = { 0 };
	
	for (int i = 0; i < 3; i++)
	{
		printf("์ฑ ๋ฑ๋ก: ์ ๋ชฉ, ์ ์ ์๋ ฅ : ");
		scanf("%s %s", Books[i].name, Books[i].author);  //	scanf("%s %s", &Books[i].name, &Books[i].author); ์ด๊ฒ๋ ์๋๋๋ ์ด์ ๋? name๊ณผ author ์์ฒด๊ฐ ํฌ์ธํฐ ์์์
		Books[i].borrowed = 0;
	}

	printf("---------------------------------------------\n");

	for (int i = 0; i < 3; i++)
	{
		printf("์ฑ ์ ๋ชฉ : %s\n", Books[i].name);
		printf("์ฑ ์ ์ : %s\n", Books[i].author);
		
		if (Books[i].borrowed == 0)
		{
			printf("๋์ถ์ฌ๋ถ : ๊ฐ๋ฅ\n");
		}
		else
		{
			printf("๋์ถ์ฌ๋ถ : ๋ถ๊ฐ๋ฅ\n");
		}
		printf("---------------------------------------------\n");
	}

	return 0;
}

--------------------------------------------------------------------------------------
   
             ๊ตฌ์กฐ์ฒด ํฌ์ธํฐ๋ค.
   
  
#include <stdio.h>

struct test
{
	int a, b;
};

int main()
{
	struct test st;
	struct test* ptr;   // struct test ๋ int,double,char๊ณผ ๊ฐ์ ์๋ฃํ์ด๋ผ๊ณ  ์๊ฐํ๋ฉด ๋๋ค. (ในใ์ด๋ ๊ฒ ์๊ฐํ๋ฉด ์ฝ๋ค)

	ptr = &st;

	(*ptr).a = 1;
  ptr->a = 5;        // ์์ ๋์ผ
  
	(*ptr).b = 2;
	ptr->b = 3;        // ์์ ๋์ผ

	printf("%d\n%d\n", (*ptr).a, (*ptr).b);

	return 0;
}

-------------------------------------์ค-------(๊ฒ์ฆ๋)-------ํ-----------------------------------
* ์คํ 1.

#include <stdio.h>

struct test1
{
	int a, b;
};

int letsdoit(struct test1* pt)
{
	pt->a = 50;
	pt->b = 33;
	return (*pt).a + (*pt).b;
}

int main()
{
	struct test1 t1;

	printf("%d", letsdoit(&t1));
	return 0;
}




------------------------------------------------------------------------
* ์คํ 2.
	
#include <stdio.h>

struct test1
{
	int a, b;

	struct test2
	{
		int c, d;
	};
};


int main()
{
	struct test1 t1;
	struct test2 t2;

	t1.a = 5;
	t1.b = 2;
	t1.c = 3;
	t1.d = 4;

	//t2.a = 5;      ๋น์ฐํ 
	//t2.b = 2;
	t2.c = 50;
	t2.d = 30;

	printf("%d\n", t1.a);
	printf("%d\n", t1.b);
	printf("%d\n", t1.c);
	printf("%d\n", t1.d);
	printf("%d\n", t2.c);
	printf("%d\n", t2.d);

	return 0;
}

------------------------------------------------
* ์คํ 3.
	
#include <stdio.h>

struct test
{
	int a;
	int b;
	int* p;
};

int main()
{
	struct test t1;
	int i = 100;

	t1.a = 500;
	t1.b = 400;
	t1.p = &i;
	*t1.p = 5;

	printf("%d %d %d\n", t1.a, t1.b, *t1.p);




	struct test* tp;
	tp = &t1;

	tp->a = 5;  //(*tp).a = 5;
	tp->b = 3;
	//*tp->p = i; // *(*tp).p = i;   ์ด๋ฌ๋ฉด ์๋์ง *p์๋ ์ฐ์ ์ ์ผ๋ก ๊ฐ์ ์ฐธ์กฐํ๋ ์ฃผ์ ๊ฐ์ด ๋ค์ด๊ฐ์ผํ๋ ๋ฐ ๊ฐ ๋ถํฐ ๋ฃ์ด๋ฒ๋ฆฌ๋ฉด ๋น์ฐํ ์๋์ง
	tp->p = &i;

	printf("%d\n", t1.a);
	printf("%d\n", t1.b);
	printf("%d\n", *t1.p);
	printf("%d\n", (*tp).a);
	printf("%d\n", (*tp).b);
	printf("%d\n", *(*tp).p);

	return 0;
}

 -------------------------------------------------
* ์คํ 4.
	 
#include <stdio.h>

int add(int* p);

struct test
{
	int a;
};

int main()
{
	struct test t;
	struct test* tp;

	t.a = 100;

	printf("%d\n", add(&t.a));

	tp = &t;

	//tp->a = 5; //(*tp).a = 5;       tp.a == &t.a ๊ฐ ์๋๊ฐ??    -->   tp๋ &t๊ฐ ๋ง์ ์ ์๊ฒ ์ง๋ง, tp.a ๋ &t.a๊ฐ ๋  ์ ์๋ค. tp๋ ๊ตฌ์กฐ์ฒด ๋ณ์๊ฐ ์๋๊ธฐ ๋๋ฌธ์ด๋ค.
	                                                                   ๋ฐ๋ผ์ ๊ตฌ์กฐ์ฒด ๋ณ์๋ฅผ ๊ฐ๋ฆฌํค๋ &(*tp).a๊ฐ ๋ง๋ ํํ์ด๋ค.  ใก3ใก;

	printf("%d\n", add(&tp->a));  // ์ tp.a ๋ ์๋๊ณ , &(*tp).a๋ ๋ ๊น (ํน์ &tp->a)
 
	return 0;                        --> ๊ทธ ์ด์ ๋ tp๋ ์ ๋๋ก ๊ตฌ์กฐ์ฒด ๋ณ์๊ฐ ์๋๋ผ ๊ทธ์  ํฌ์ธํฐ์ ๋ถ๊ณผํ๊ธฐ ๋๋ฌธ์ด๋ค.
}                                            .a์ ์ผ์ชฝ์๋ ๊ตฌ์กฐ์ฒด ํ์์ด ์์ผํ๋ค.

int add(int* p)
{
	return ++*p;
}

---------------------------------------------------------
* ์คํ 5.
	
#include <stdio.h>
#include <string.h>

void information(struct Test* growing);

struct Test
{
	int age;
	double tall;
	char name[30];
};

int main()
{
	struct Test itsMe;

	itsMe.age = 3;
	itsMe.tall = 50.52;
	strcpy(itsMe.name, "์ด๋ฆฐ ์ ํ์ฑ");

	printf("๋์ด : %d\nํค : %.2lf\n์ด๋ฆ : %s\n", itsMe.age, itsMe.tall, itsMe.name);

	information(&itsMe);
	printf("\n๊ทธ๋ ๊ฒ 20๋ ํ..\n\n");

	printf("๋์ด : %d\nํค : %.1lf\n์ด๋ฆ : %s\n", itsMe.age, itsMe.tall, itsMe.name);

	return 0;
}

void information(struct Test* growing)
{
	growing->age = 23;
	growing->tall = 171.3;
	strcpy(growing->name, "์ฑ์ธ ์ ํ์ฑ");
}

----------------------------------------------------------------------



