μ€λͺ μΆμ²:  https://youadokjon.tistory.com/1

π \r π --> μΊλ¦¬μ§ λ¦¬ν΄ (Carriage Return), μ€μ λμμ μμ μμΉλ‘ λλμκ°λ μ μ΄λ¬Έμ

\r :  10μ§μ -> 13
      16μ§μ -> 0x0D
        λ¬Έμ -> CR

\r (μΊλ¦¬μ§ λ¦¬ν΄) μ νμ¬ μ€(ν)μμ μ²« λΆλΆμΌλ‘ μ΄λνλ κ²μ΄λ€.
μ»€μκ° μ΄λλ§ ν  λΏμ΄μ§ μ΄μ μ μΆλ ₯νλ λ¬Έμλ€μ μ§μ°μ§λ μλλ€.



#include <stdio.h>

int main(void)

{

  printf("Berrrrrrrrrr\rHappy!");   -->  'Happy! rrrrr'λ‘ μΆλ ₯

}

μ΄ μ½λκ°  'Happy! rrrrr'λ‘ μΆλ ₯λλ μ΄μ κ° λ­κΉ??

κ·Έ μ΄μ λ Happy! rrrr μ¬μ΄μ κ³΅λ°±μ μ»€μκ° μμΉνκΈ° λλ¬Έμ΄λ€.


λ€λ₯Έ μλ‘,


#include <stdio.h>

int main(void)

{

	printf("aaaaa");     --> ' ddd 'λ‘ μΆλ ₯
	printf("\r ddd");

}

μ΄ μ½λκ° ' ddda'λ‘ μΆλ ₯λμ§ μκ³ , ' ddd 'μΆλ ₯λλ μ΄μ κ° λ­κΉ??
κ°μ μ΄μ λ‘ μ»€μκ° λ§μ§λ§ aμμ μμΉνκΈ° λλ¬Έμ΄λ€.


νμ§λ§!!


#include <stdio.h>

int main(void)

{
	printf("Berrrrrrrrrr\rHappy!\n");   -->  'Hapyy!rrrrrr' λ‘ μΆλ ₯
}


μ΄ μ½λλ μ 'Hapyy!rrrrrr'λ‘ μΆλ ₯μ΄ λ κΉ??

κ·Έκ±΄ λ°λ‘ λ§μ§λ§μ \n μ μ΄λ¬Έμ λλ¬Έμ΄λ€.

"Berrrrrrrrrr\rHappy!" μ¬κΈ°κΉμ§λ 'Hapyy! rrrrr' μ΄μ²λΌ νμ¬ μ»€μμ μμΉκ° !μ rμ μ¬μ΄μ μμΉνλ€.

νμ§λ§ \nμ΄ "Berrrrrrrrrr\rHappy!\n" λ±μ₯ν¨μ λ°λΌ μ»€μμ μμΉκ° μλλ‘ μ΄λνμ¬
(!μ rμ¬μ΄μ μλ μ»€μκ° μλλ‘ μ΄λνμ¬)

'Hapyy!rrrrrr' λ‘ μΆλ ₯λλ κ²μ΄λ€.

λ€λ₯Έ μλ‘,

#include <stdio.h>

int main(void)

{

	printf("aaaaa");        --> 'dddaa'λ‘ μΆλ ₯
	printf("\rddd\n");   

	return 0;

}

μ΄ μ½λ λν λ§μ°¬κ°μ§μ΄λ€.

  printf("aaaaa");     
	printf("\rddd");    μ¬κΈ°κΉμ§λ λΆλͺν 'ddd a'λ‘ μΆλ ₯μ΄ λ  κ²μ΄λ€.
  
  νμ§λ§

  printf("aaaaa");        
	printf("\rddd\n");   \nμ΄ λΆμμΌλ‘μ¨ μ»€μκ° μλλ‘ μ΄λνκΈ° λλ¬Έμ
                       'dddaa'λ‘ μΆλ ₯μ΄ λλ κ²μ΄λ€.
  



π \b π : λ°± μ€νμ΄μ€ (backspace)

λ°± μ€νμ΄μ€λΌκ³  νμ§λ§ μ°λ¦¬κ° νμ μ¬μ©νλ κ·Έ λ°± μ€νμ΄μ€μλ λ€λ₯΄λ€.

μ°λ¦¬κ° νμμ μ¬μ©νλ backspaceλ κΈμλ₯Ό μ§μκ³Ό λμμ λ€λ‘ μμ§μ΄μ§λ§,

\bλ μ»€μλ§μ νμΉΈ λ€λ‘ μμ§μΈλ€.


#include <stdio.h>

int main(void)

{

	printf("abcdef\b");   -->  'abcde' λ‘ μΆλ ₯

	return 0;

}

μ΄ μ½λμ μ½λμ μ€ν κ²°κ³Όλ§ λ΄€μ λλ μ°λ¦¬κ° μ°λ λ°±μ€νμ΄μ€μ λ­κ° λ€λ₯Έμ§ μ§μνκΈ° μ΄λ ΅λ€.

νμ§λ§ νμ¬ abcdefμμ fλ μ§μμ§ κ²μ΄ μλλΌ, κ·Έ μμ μ»€μκ° μμΉνκ³  μλ κ²μ΄λ€.



#include <stdio.h>

int main(void)

{

	printf("abcdef\b\b");  -->  'abcd f' λ‘ μΆλ ₯

	return 0;

}

μ΄ μ½λμ μ€νκ²°κ³Όλ 'abcd f' μ΄λ€. κ·Έ μ΄μ λ μ»€μκ° λ€λ‘ λ λ² μ΄λνκΈ° λλ¬Έμ

μ»€μκ° 'e'μλ¦¬μ μμΉνκ³  μκΈ° λλ¬Έμ΄λ€.




#include <stdio.h>

int main(void)

{

	printf("abc\bd\b\b \n");   
	printf("fe\bh\b\b \n");  
	return 0;

}




μ΄ μ½λλ μ΄λ»κ² μΆλ ₯ λ κΉ?

ππ μΆλ ₯ κ²°κ³Ό:  a d
                   h

μ΄ μ½λκ° μ μ΄λ κ² μΆλ ₯λλμ§λ μμ μ€λͺμ λ³΄λ©΄ μΆ©λΆν μ μΈκ° κ°λ₯νλ€.

νμ§λ§ μ‘°κΈ ν·κ°λ¦¬λ λΆλΆμ κ³΅λ°±λΆλΆμ΄λ€. κ·Έκ²λ§ μ£Όμνλ©΄ λ  λ―νλ€.





#include <stdio.h>

int main(void)

{

	printf("abc\bd\b\bf\n");   -->  'afd' λ‘ μΆλ ₯
	printf("fe\bh\b\bc\n");  -->  'ch' λ‘ μΆλ ₯
	return 0;

}

μ΄ μ½λλ μμ μ½λμ κ³΅λ°± λΆλΆμ κ°κ° fμ cλ₯Ό λ£μ΄μ£Όμλ€.
μ΄κ±Έ λ³΄λ©΄ λ μ΄ν΄κ° νμ€ν λ  κ²μ΄λ€.




printf("ABC\b\bDEF");    -->  'ADEF'λ‘ μΆλ ₯  // μ»€μμ μμΉκ° 'B'μμ μμΌλ―λ‘ Bμμμ DEFκ° μλ ₯λκΈ° λλ¬Έ.



 \r κ³Ό \bλ μΈμ€νΈ(insert) λͺ¨λλ₯Ό μ μ΄ν΄νκ³  μλ€λ©΄ μΆ©λΆν μ νμ©κ°λ₯ν  κ²μ΄λ€.






