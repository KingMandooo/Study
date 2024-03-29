2022. 03. 31.

🟡 산술 연산자

🟢 기본 산술 연산자

 =  :  대입 연산자   ,  a=3       > 정수 3을 a에 대입한다.
 +  :  더하기       ,  a=5+3     >  정수 5와 3을 더한 값을 a에 대입한다.
 -  :  빼기         ,  a=5-3     >   정수 5에서 3을 뺀 값을 a에 대입한다.
 *  :  곱하기       ,  a=5*3     >   정수 5와 3을 곱한 값을 a에 대입한다.
 /  :  나누기       ,  a=5/3     >   정수 5를 3으로 나눈 값을 a에 대입한다.
 %  :  나머지 값    ,  a=5%3     >   정수 5를 3으로 나눈 뒤 나머지 값을 a에 대입한다.
 
 🟢 연산자 우선순위와 강제 형 변환
 
 #include <stdio.h>

int main(void)
{
	int a = 2, b = 3, c = 4;
	int result1, mok, namugi;
	float result2;

	result1 = a + b - c;
	printf("%d + %d - %d = %d \n", a, b, c, result1);

	result1 = a + b * c;
	printf("%d + %d * %d = %d \n", a, b, c, result1);

	result2 = a * b / (float) c;                             <--- 강제 형 변환으로 변수 c를 실수형으로 잠깐 변환하여 '정수/실수=실수'러 계산하게 만들었다.
	printf("%d * %d / %d = %f \n", a, b, c, result2);

	mok = c / b;
	printf("%d / %d 의 몫은 %d \n", c, b, mok);

	namugi = c % b;
	printf("%d %% %d 의 나머지는 %d \n", c, b, namugi);   //C의 printf() 함수에서는 "퍼센트 기호 (%)"가, 포맷 출력을 위해 특수한 의미로 사용되므로, 
}                                                        퍼센트 기호 자체를 출력하기 위해서는 퍼센트 기호를 "2개 중복"해 주어야 제대로 출력된다.

 
🟠 간단한 연산자 우선순위

--> 그냥 수학이랑 똑같다.

🟠 데이터 형식의 강제 형 변환

--> 상수 앞에 '(형식 이름)' 을 넣어서 형식을 강제로 바꿔준다.
    
    int a = 2, b = 3, c = 4;
    result2 = a * b / (float) c;    <-- 이렇게 그러면 출력이 1.500000 이렇게 된다.
    printf("%d * %d / %d = %f \n", a, b, c, result2);  
 
    result2 = a * b / c;  <-- 만약 바꿔주지 않으면 1로 출력된다.


🟠 대입 연산자와 증감 연산자

대입 연산자.                                   
   +=  :  a+=3   -->   a=a+3
   -=  :  a-=3   -->   a=a-3
   *=  :  a*=3   -->   a=a*3
   /=  :  a/=3   -->   a=a/3
   %=  :  a%=3   -->   a=a%3
   
증감 연산자.
   ++  :  a++ 또는 ++a   -->   a=a+1 또는 a+=1 과 동일
   --  :  a--또는 --a   -->   a=a-1 또는 a-=1 과 동일
  
✅ a++ 과 ++a 의 차이점은?

  #include <stdio.h>

int main(void)
{
	int a = 10, b;

	b = a++;                             <--  b에 a가 대입됐다.  따라서 b는 10이다.   그 다음  a에 1이 더해져 a의 값은 11이 된다.
	printf("%d\n", b);

	b = ++a;                             <--  b에 a가 대입됐고, 따라서 b는 12이다.   왜냐하면  b에 a에 1이 더해진 후에 대입됐기 때문이다.
	printf("%d\n", b);
}
                                    출력값:  10
				             12

--------------------------------------------------

#include <stdio.h>

int main(void)
{
	int a = 10, b;

	b = a++;                     <--  b에 a가 대입된다. 그 후에 a에 1이 더해진다. 따라서 a는 11이 된다. 하지만 b에는 11이 되기 전인 10인 a가 대입 되어 10으로 출력된다.
	printf("%d\n", b);                   

	b = a + 1;                   <--  b에 11인 a에 1이 더해진 12가 대입되어 b의 값이 12로 출력된다.  하지만 a의 값은 여전히 11이다.
	printf("%d\n", b);                여기서 차이를 알겠는가?  a++ 는 a=a+1이므로 a라는 변수에 값이 정해지지만 이건 아니다. 일회성이다.

	b = ++a;                      <-- 11인 a에 1이 더해져서 b의 값은 12가 된다.
	printf("%d\n", b);
}


                                    출력값: 10
				            12
					    12


----------------------------------------------------------


🟡 관계 연산자

-->  관계 연산자(또는 비교연산자)는 어떤 것이 큰지, 작은지, 같은지를 비교하는 것으로 그 결과는 참(true)나 거짓(false)이 된다.
     일반적으로 참은 1, 거짓은 0으로 표시한다.

  ==   :   같다   >>   두 값이 동일하면 참이다.
  !=   :   같지않다  >>  두 값이 다르면 참이다.
  >    :   크다   >>  왼쪽이 크면 참이다.
  <    :   작다   >>  왼쪽이 작으면 참이다.
  >=   :   크거나 같다  >>  왼쪽이 크거나 같으면 참이다.
  <=   :   작거나 같다  >>  왼쪽이 작거나 같으면 참이다.

      

    ✅  = 과 == 는 완전히 다르다!!
    
    -->  == 는 관계 연산자로서 값이 같은지 여부를 확인하는 것이고, = 는 대입 연산자로서 오른쪽의 값을 왼쪽에 대입하라는 의미이다.



#include <stdio.h>

int main(void)
{
	int a = 100, b = 200;
	printf("%d = %d 은 %d 이다.", a, b, a = b);
}
	 
	 
 출력결과:  200 = 200 은 200 이다. 
	 
 왜 이렇게 출력될까???????????????
	 
 그건 바로 오른쪽 값을 왼쪽에 대입하기 때문에 오른쪽에 있는 a=b가 출력보다 먼저 작동 되었기 때문이다.
	 
 따라서 a=b가 먼저 작동돼서 a,b의 값은 둘다 200을 가진 상태로 출력이 된다.


----------------------------------------------------------

🟡 논리 연산자

&&  :  ~ 이고     ,     그리고(AND)     -->   둘 다 참이어야 참이다.
||  :  ~ 이거나   ,      또는(OR)       -->   둘 중 하나만 참이어도 참이다.
!   :  ~ 아니다   ,      부정(NOT)      -->   참이면 거짓, 거짓이면 참이다.

     책 p.131 꼭 보기!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  -->  0을 제외한 모든 수는 참을 의미한다..!
     
     

 	int a = 0, int b = 0;
	printf("%d", a && b);             -->  0 으로 출력.  / 둘 다 거짓(0)이라면 결과는 거짓(0)이 된다.
	
	int a = 0, int b = 30;
	printf("%d", a && b);             -->  0 으로 출력.

	int a = 3, int b = 30; 
	printf("%d", a && b);             -->  1 로 출력.



----------------------------------------------------------

 🟡 비트 연산자
 
 🟠 비트 논리곱(&) 연산자
 
 🟠 비트 논리합(|) 연산자
 
 🟠 비트 배타적 논리합(^) 연산자
 
 🟠 비트 부정(~) 연산자

 🟠 비트 왼쪽 시프트(<<) 연산자
 
 🟠 비트 오른쪽 시프트(>>) 연산자
 
 🟠 연산자 우선순위
   --> 책 p.142 확인


----------------------------------------------------------------------------------------------------------------------------------------------------------------

📌예제 문제풀이📌

예제 08.  애매함❗❓

#include <stdio.h>

int main()
{
	float a, b;

	printf("첫 번째 계산할 값을 입력하세요 ==> ");
	scanf("%f", &a);

	printf("두 번째 계산할 값을 입력하세요 ==> ");
	scanf("%f", &b);

	printf("%.2f + %.2f = %.2f\n", a, b, a + b);
	printf("%.2f - %.2f = %.2f\n", a, b, a - b);
	printf("%.2f * %.2f = %.2f\n", a, b, a * b);
	printf("%.2f / %.2f = %.2f\n", a, b, a / b);

	float result;                                     
	result = (int)a % (int)b;                             <-- 강제 형 변환하는 것이 아직 익숙하지 않다.
	printf("%d %% %d = %d", (int)a, (int)b, (int)result);
}

217~219번 줄에서
1.	int result;
	result = (int)a % (int)b;
	printf("%d %% %d = %d", (int)a, (int)b, result);          <--- 이렇게 하거나


2.      printf("%d %% %d = %d", (int)a, (int)b, (int)a % (int)b);  <--- 이렇게 하는 것이 맥락적으로 더 괜찮은거 같다.




예제 09. 맞음⭕

#include <stdio.h>

int main()
{
	int money;
	int changes;
	printf("## 교환할 돈은 ? ");
	scanf("%d", &money);

	changes = money / 500;  
	printf("오백원짜리 ==> %d 개\n", changes);

	money = money - (changes * 500);

	changes = money / 100;
	printf("백원짜리   ==> %d 개\n", changes);

	money = money - (changes * 100);

	changes = money / 50;
	printf("오십원짜리 ==> %d 개\n", changes);

	money = money - (changes * 50);

	changes = money / 10;
	printf("십원짜리   ==> %d 개\n", changes);

	money = money - (changes * 10);

	printf("바꾸지 못한 잔돈 ==> %d 원", money);
}

🔻다른 답🔻

#include <stdio.h>

int main()
{
	int money, c500, c100, c50, c10;

	printf(" ## 교환할 돈은 ? ");
	scanf("%d", &money);

	c500 = money / 500;
	money = money % 500;            <--- 나머지를 통해서 잔돈을 구하는 생각은 하지 못했다.

	c100 = money / 100;
	money = money % 100;

	c50 = money / 50;
	money = money % 50;

	c10 = money / 10;
	money = money % 10;

	printf("\n오백원 짜리 ==> %d 개 \n", c500);
	printf("백원 짜리   ==> %d 개 \n", c100);
	printf("오십원 짜리 ==> %d 개 \n", c50);
	printf("십원 짜리   ==> %d 개 \n", c10);
	printf("바꾸지 못한 잔돈   ==> %d 원 \n", money);
}

그니까 나는 가지고 있는 3500원에서 3000원짜리 빵을 사먹는다고 했을 때, 3500원에서 3000원을 빼서 잔돈 500원을 구할 생각은 했지만, 
3500원에서 1000원을 나눠서 나머지 값인 500원을 구해서 잔돈을 알아낼 생각은 못한 것이다.




예제 10. 맞음⭕

#include <stdio.h>

int main(void)
{
	int years;

	printf("년도를 입력하세요. : ");
	scanf("%d", &years);

	if ((years % 4 == 0 && years % 100 != 0) || years % 400 == 0)
	{
		printf("%d 년은 윤년입니다.\n", years);
	}
	else
		printf("윤년이 아닙니다.\n");
}


