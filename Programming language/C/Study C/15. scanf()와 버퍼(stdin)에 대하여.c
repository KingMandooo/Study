
도움된 사이트: https://modoocode.com/32

* 수많은 버퍼 중에 우리가 흔히 사용하는 버퍼는 키보드의 입력을 처리하는 버퍼인 입력버퍼, 혹은 stdin(입력 스트림)이다.

------------------------------------------------------------
  
 * scanf()함수를 사용하여 숫자를 입력받을 때 일어나는 일
  
#include <stdio.h>

int main()
{
	int num;
	scanf("%d", &num);
	printf("%d", num);

	return 0;
}  
       
           scanf() 함수는 ' ', '\n', '\t'를 만날 때 까지 버퍼로부터 데이터를 얻어온다.
           즉, 이 세 가지 중 하나를 만나게 되면 '여기서 입력이 끝나는구나'하고 입력을 종료한다는 뜻이다.
        
           특히 %d 계열의 것, 즉 수를 입력받는 형식은 수가 아닌 데이터가 와도 입력을 종료해버린다.
           따라서 위의 scanf()함수에서 'A'를 입력을한다면 num에는 아무런 값도 들어가지 않게된다.
             
           뿐만 아니라 수 데이터를 입력받는 형식의 경우엔 처음부터 공백문자가 나타나면
           수가 나타날 때 까지 입력을 계속 받게 된다.
           (따라서 처음 입력을 받을 때 아무리 enter를 쳐도 수를 입력받을 때 까지 입력을 종료하지 않는다.)
             
	scanf("%d", &num);  <-- 여기에서 'A'를 입력한다면
	printf("%d", num);  <-- -858993460 이와 같은 쓰레기 값이 출력된다.
               
                이유는 위에서도 말했듯이 수를 입력받는 형식은 수가 아닌 데이터가 오기된다면 입력을
                종료해버리기때문에, num에는 어떠한 값도 들어가있지 않기 때문이다.
             
    --------------    --------------    --------------    --------------                
✅ 결론적으로 %s 나 %d 그리고 다른 모든 수 데이터를 입력 받는 형식은 
    버퍼에 남아 있는 공백 문자에 신경쓰지 않고 사용할 수 있다.
    --------------    --------------    --------------    --------------         
             
             다시 돌아서와서 그렇다면 num에 5를 입력을해줬다고 가정해보자.
             그렇다면 printf()함수는 5를 정상적으로 출력할 것이다.
             
             하지만 num이 출력되고 나서 버퍼 안에는 '\n'가 남게된다.
             이러한 상황이 어떠한 문제를 불러일으킬까?

  --  이 코드를 한 번 봐보자 --      
             
#include <stdio.h>
int main() {
  int num;
  char c;

  printf("숫자를 입력하세요 : ");
  scanf("%d", &num);

  printf("문자를 입력하세요 : ");
  scanf("%c", &c);
  return 0;
}                             이 코드를 봤을 땐 겉으로는 아무런 문제가 없어 보인다.
                              그렇다면 실행시켰을 땐 어떻게 될까?
             
*출력결과 
          숫자를 입력하세요 : 5
          문자를 입력하세요 :

                문자를 입력하지도 못하고 프로그램이 종료가 된다. 
                도대체 왜 그런걸까?
                  
                그 이유는 버퍼에는 '\n' 개행문자가 남아있고
                %c는 개행문자를 하나의 문자로 인식하기 때문에 무시하지 못하고
                읽어오기 때문이다.
                (생각보다 이유가 간단하다.)
                  
                  
    그렇다면 우리가 이러한 문제를 어떻게 해결할 수 있을까?????????????????
                  
    우선 scanf()함수를 사용할 땐 버퍼를 비워주는 방법이 있다.
                  
#include <stdio.h>
                  
int main() 
{
    int num;
    char c;

    printf("숫자를 입력하세요 : ");
    scanf("%d", &num);
    printf("%d\n", num);

    c = getchar();                      // 버퍼를 비워주기
    printf("버퍼에 남아있는 : %c\n", c);

    printf("문자를 입력하세요 : ");
    scanf("%c", &c);
    printf("%c\n", c);
                  
    return 0;
}                 
                  
    ------------ 분석해보기 -------------
      
#include <stdio.h>
int main() 
{
	int num, i;
	char c;

	printf("숫자를 입력하세요 : ");
	scanf("%d", &num);
	printf("num : %d\n", num);

	getchar();

	printf("문자를 입력하세요 : ");
	scanf("%c", &c);

	printf("입력한 문자 : %c", c);
	return 0;
}
                  
                  첫 번째 scanf()함수에 123abc를 입력했다고 가정하자
                  그랬을때의 출력 결과이다.

숫자를 입력하세요 : 123abc
num : 123
문자를 입력하세요 : 입력한 문자 : b
C:\Users\asus\OneDrive\바탕 화면\공부\study_Cprogramming\x64\Debug\study.exe(프로세스 9820개)이(가) 종료되었습니다(코드: 0개).
이 창을 닫으려면 아무 키나 누르세요...

                  
                 어째서 이러한 결과가 나오는걸까??  한 번 분석해보자.
  
  
  
  
  
  
  분석:  123abc를 입력을 하게 되면 우선 수를 입력받는 형식이기에 a가 숫자가 아님을 인지하고 123까지
         읽은 후 stdin에서 그만 읽어 온다.
         
         그다음 getchar() 함수를 통해 문자 하나를 버퍼에서 지워준다.
         현재까지 버퍼에 남아있는 값은 'b' 'c' '\n' 가 된다.
        
         그다음 입력을 받을 땐 이미 버퍼에 값이 있으므로 입력을 받지 않고
         문자하나만 출력하기에 b가 출력되는 것이다.
         
    
   ❗❗ 결국엔 되도록이면 scanf() 함수에서 %c 를 사용하는 것은 권장되지 않는다.
                  
