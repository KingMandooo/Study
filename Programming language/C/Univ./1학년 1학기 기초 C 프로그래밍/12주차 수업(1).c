
πμμ  λ¬Έμ νμ΄π

μμ  24.  λ§μβ­

#include <stdio.h>
#include <string.h>

int main(void)
{
	char ss[100];
	char* aa;
	int len;

	aa = ss;

	printf("λ¬Έμμ΄μ μλ ₯νμΈμ : ");
	scanf("%s", ss);

	len = strlen(ss);

	for (int i = len - 1; i >= 0; i--)  
  {
		printf("%c", *(aa + i));
	}
	
	return 0;
}


π»λ€λ₯Έ λ΅π»

#include <stdio.h>
#include <string.h>

int main(void)
{
	char ss[100];
	char* aa;
	int len;

	aa = ss;

	printf("λ¬Έμμ΄μ μλ ₯νμΈμ : ");
	scanf("%s", ss);

	len = strlen(ss);

	for (int i = 0; i < len; i++)
	{
		printf("%c", *(aa + len - (i + 1)));         <-- μ¬κΈ°λ₯Ό μμ ν΄μ€¬λ€.
	}

	return 0;
}


μμ  25.  λ§μβ­

#include <stdio.h>

int main(void)
{
	int a;
	int b;

	int* p1;
	int* p2;
	int tmp;

	p1 = &a;
	p2 = &b;

	printf("a κ° μλ ₯ : ");
	scanf("%d", &a);
	printf("b κ° μλ ₯ : ");
	scanf("%d", &b);

	tmp = *p1;               tmp = p1 μ΄λ κ² tmpμ p1 κ° ( μ£Όμκ° ) μ λ£μ΄μ£Όλ €κ³  νλλ° μ€λ₯κ° λλ€.  
	*p1 = *p2;
	*p2 = tmp;


	printf("λ°λ κ° aλ %d, bλ %d", *p1, *p2);

	return 0;
}


μμ  26.   λ§μβ­

#include <stdio.h>

int main()
{
	int s[10] = { 1,0,3,2,5,4,7,6,9,8 };
	int tmp;
	int* p;
	p = s;

	for (int i = 0; i < 10; i++)
	{
		for (int j = i + 1; j < 10; j++)
		{
			if (*(p + i) > *(p + j))
			{
				tmp = *(p + i);
				*(p + i) = *(p + j);
				*(p + j) = tmp;
			}
		}
	}

	for (int i = 0; i < 10; i++)
	{
		printf("%2d", *(p + i));
	}

	return 0;
}
