2022. 06. 02.

🟡 표준 입출력 함수

   표준 입력 장치(키보드) --> 표준 입력 (stdin, standard input) 함수 --> C 프로그램 --> 표준 출력 (stdout, standard output) 함수 --> 표준 출력 장치(모니터)
                                  ex) scanf(), gets(), getchar()                           ex) printf(), puts(), putchar()
   
   
   🎈🎈 표준 입력인 키보드와 표준 출력인 모니터를 통틀어서 콘솔(console)이라고도 한다.
        콘솔이란 대개 디스플레이 모니터와 키보드(또는 입력이 가능한 다른 장치)가 조합된 장치를 말한다.
   
🟠 서식화된 입출력 함수
  
    * printf("서식", 출력할 매개변수);
    * scanf("서식", 출력할 매개변수);
   
    ------------------------
    서식              설명
    ------------------------
    %d         -->    정수형(int)
    %c         -->    문자형(char)
    %s         -->    문자열(char*) 또는 문자 배열(char[])
    %x         -->    16진수 정수(int)
    %o         -->    8진수 정수(int)
    %f, %lf    -->    실수형(float, double)
    
    %e         -->    공학 계산용 형식       🎈🎈 double a = 0.00314;  -->  3.14e-3
                                                  double b = 0.000314;  -->  3.14e-4
                                                  double c =  0.0000314;  -->  3.14e-5
                                       
                                             
    %p         -->    포인터 주소       🎈🎈 %p는 변수의 주소를 16진수로 표현할 때 쓰임.
    
-------------------------------------------
    
#include <stdio.h>

int main()
{
	int a;
	float b;
	char ch;
	char s[20];

	printf("정수: ");     
	scanf("%d", &a);
	printf("실수: ");
	scanf("%f", &b);
	printf("문자: ");
	scanf(" %c", &ch);
	printf("문자열: ");
	scanf("%s", s);

	printf("a: %d\n", a);
	printf("b: %f\n", b);
	printf("실수를 공학 계산용 형식으로: %e\n", b);
	printf("c: %c\n", ch);
	printf("s: %s\n", s);
	printf("s의 주소: %p\n", s);
	printf("s의 주소: %X\n", s);

	int i = 3;
	int* p = &i;

	printf("%d\n", &i);
	printf("%d\n", p);
	printf("%p\n", &i);
	printf("%p\n", p);   //   🎈🎈 %p는 변수의 주소를 16진수로 표현할 때 쓰임.

	return 0;
}

-----------------------------------------------------------------------------

🟠 문자열 입출력 함수

  * gets(문자 배열)  :  scanf() 함수는 문자열 중간에 공백 문자(space)를 입력할 수 없지만, gets() 함수는 공백 문자를 입력할 수 있다.
  
  * puts(문자 배열)  :  자동으로 '\n'을 해줌
 

#include <stdio.h>

int main()
{
	char aa[100];

	gets(aa);
	
	puts(aa);
	printf("%s\n", aa);

	scanf("%s", aa);

	puts(aa);
	printf("%s\n", aa);

	return 0;
}

-----------------------------------------------------------------------------

🟠 문자 입출력 함수

     * getch()   : 키보드를 통해 문자 하나를 입력받으며, 입력한 내용을 모니터에 보여주지 않는다.
     
     * getche()  : 키보드를 통해 문자 하나를 입력받으며, 입력한 내용을 모니터에 보여준다.
     
     * getchar() : 사용자가 키보드로 Enter를 누를 때까지 입력한 것을 메모리(버퍼)에 모두 저장해 놓고(Enter도 저장됨) 그중에서 한 문자만 꺼낸다.



     * putchar() : 표준 출력 장치(모니터)에 문자 하나를 출력한다.
     
     * putch()   : putchar()와 기능이 동일

 
    🔷 getch()    🎈🎈(버퍼 사용 X)
          
	-->  키보드를 통해 문자 하나를 입력받으며, 입력한 내용을 모니터에 보여주지 않는다.
	
#include <stdio.h>

int main()
{
	char ch;

	ch = getch();
	putchar(ch);   

	ch = getch();
	putch('\n');       <-- 줄바꿈을 해줌

	ch = getch();
	putchar(ch);

	return 0;
}

---------------------------------------------------------------

#include <stdio.h>
#include <string.h>

int main()
{
	char password[5] = "5678";
	char input[5];

	for (int i = 0; i < 4; i++)
	{
		input[i] = getch();
		putchar('*');
	}

	printf("\n");

	if (strncmp(password, input, 4) == 0)      
		printf("문이 열렸습니다\n");
	else
		printf("비번이 틀렸습니다\n");

	printf("입력한 비밀번호: ");

	for (int i = 0; i < 4; i++)
		putchar(input[i]);

	return 0;
}

       ✅ Q. strcmp() 와 strncmp()의 차이
       
           A.▶ strcmp(str1, str2)
	        첫번째 매개변수 
	        str1 : 비교할 문자열1
		두번재 매개변수
	        str2 : 비교할 문자열2
	   
	     ▶ strncmp (str1, str2, n)
	        첫번째 매개변수 str1 : 비교할 문자열1
	        두번재 매개변수 str2 : 비교할 문자열2
	        세번째 매개변수 n : 비교할 문자열 길이  
						
						출처: https://blockdmask.tistory.com/391 [개발자 지망생:티스토리]
       


       🎈🎈 만약 strncmp() 말고 strcmp()를 사용하고싶다면..  이렇게 --> if (strcmp(password, input) == 0)
	
	   -->    input[4] = '\0';  이렇게 input의 마지막에 널문자를 넣어줘야함.

	     사실 위의 input[4] = '\0'; 이게 왜 필요한지 모르겠다.
	     널문자는 문자열에 자동으로 채워주는 거 아닌가???
	     배열 input은 사용자가 입력을 해주기 때문에 널문자가 자동으로 생기지 않는건가???
	     
 
           

    🔷 getche()    🎈🎈(버퍼 사용 X)    
      
        --> getche() 함수는 putch() 함수를 사용하지 않아도 입력한 내용을 바로 모니터에 출력한다.
	
            getche()의 마지막 'e'는 'echo'를 의미한다.

#include <stdio.h>

int main()
{
	char ch;

	ch = getche();
	putch(ch);
	ch = getche();
	putch(ch);
	ch = getche();
	putch(ch);

	return 0;
}



    🔷 getchar()    🎈🎈(버퍼 사용 O) 
    
    
#include <stdio.h>

int main()
{
	char ch;

	ch = getchar();     
	putchar(ch);

	ch = getchar();
	putchar(ch);

	ch = getchar();
	putchar(ch);

	return 0;
}    
    
    🎈🎈 이 코드를 보면 첫 getchar() 함수를 통해 문자 하나를 입력해주고 Enter를 누르고 또 getchar() 함수에 문자 하나를 입력해주고 
         이런 식으로 3번을 입력 받을거 같지만 그렇지 않다.
	 
	 A 입력 -->  Enter --> A 출력 --> B 입력 --> Enter --> B 출력 --> C 입력 --> Enter --> C 출력    이런 식으로 될거 같지만 그렇지 않다.
	 
	 A 입력 --> Enter 입력 --> A 출력 --> Enter 출력 --> B 입력 --> Enter 입력 --> B 출력 --> 종료    이렇게 된다. 
	 
	 그니까 A 그리고 Enter를 입력하면 
	 입력 버퍼 안에 A와 Enter가 저장된다. ( putchar() 함수는 '\n'를 만나면 종료된다. )
	 그럼 첫 번째 putchar(ch); 에서 'A'가 출력되고
	 그다음 두 번째 getchar() 함수를 실행 시킬 때 입력 버퍼에 값이 남아 있으므로 ( Enter가 남아있다 )
	 putchar(ch); 에서 Enter가 출력된다. 입력 버퍼에 이제 값이 남아있지 않으므로
	 
	 세 번째 getchar() 함수가 실행되고
	 putchar(ch); 함수가 실행되고 '\n'를 만나 종료된다.
	 
	 
	 
	 
	 만약 ABC를 입력하고 싶다면 처음 입력할 때 ABC를 입력해주면 된다.
	 그럼 입력 버퍼에 ABC가 들어가고 
	 A 출력 그다음 입력 버퍼에 BC가 남아있으므로
	 B 출력 그다음 입력 버퍼에 C가 남아있으므로
         C 출력 이렇게 된다.
	 
	 

     🎈🎈 버퍼를 초기화 하는 법

#include <stdio.h>

int main()
{
	char ch;

	ch = getchar();
	putchar(ch);
	putchar('\n');

	while (getchar() != '\n') {}    <-- 이렇게 하면 버퍼를 초기화 시킬 수 있다.

	ch = getchar();
	putchar(ch);
	putchar('\n');

	while (getchar() != '\n') {}

	ch = getchar();
	putchar(ch);

	return 0;
}
	 
   ✅ 헷갈리는 것..!!
   
#include <stdio.h>

int main()
{
	char ch;

	ch = getchar();
	putchar(ch);

	putchar(ch);

	putchar(ch);

	return 0;
}
                                       그렇다면 여기에서 ABC 를 입력을 해준다면 ABC가 출력 돼야하는 것이 아닌가?????
				       왜 AAA가 출력이 될까???
				       
				       그 이유는 더 이상 입력 버퍼를 호출하지 않았기 때문이다.
				       
				       좀 더 정확한 이유가 필요해.

-----------------------------------

#include <stdio.h>

int main()
{
	char a;

	while ((a = getchar()) != '\n')  // a = getchar() 에 () 을 안넣어주면 값이 이상하게 나옴
		putchar(a);

	return 0;
}

    
  🎈🎈  getchar() 함수를 통해 a에 "hello"를 입력해보자.
        getchar() 함수는 문자 하나를 입력해주는 함수다. putchar()은 문자 하나를 출력해주는 함수이다.
    
        그러면 어떻게 "hello"가 출력이 될까? 
        
        그건 바로 "hello"를 입력하면 입력버퍼에 "hello"가 채워지게 된다.
        그럼 putchar() 함수를 통해 'h'가 출력된다.
        그다음 다시 getchar() 함수로 돌아가지만 입력버퍼에 입력한 값이 남아 있으므로 함수를 실행시키지 않고
        다시 아래의 putchar() 함수로 가서 'e'를 출력한다.
        이와 같은 방식으로 나머지 'llo'도 출력한다. 마지막에 있는 '\n'도 출력되며 조건식에 의해 while문이 종료된다.
    
    
    
    
    
    
