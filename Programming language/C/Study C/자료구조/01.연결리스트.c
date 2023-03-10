๐๐ ํ์ ๋ชจ ๋ฐ๋ฒ ์จ ๋ถ๋ก ๊ฐ์ ๊ณต๋ถ

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TSIZE 45

struct movie
{
	char title[TSIZE];
	float rating;
	struct movie* next;
};

typedef struct movie* p_movie;

void print_all(p_movie head)
{
	printf("-------------------------------\n");
	printf("Head address = %zd\n", (size_t)head);
	p_movie search = head;
	while (search != NULL)
	{
		printf("%zd \" %s \" %f %zd\n", (size_t)search, search->title, search->rating, (size_t)search->next);
		search = search->next;
	}
}

int main()
{
	p_movie head = NULL;

	p_movie new_node = malloc(sizeof(struct movie));
	if (new_node == NULL)
	{
		printf("ERROR: malloc failed.");
		exit(1);
	}
	strcpy(new_node->title, "Avatar");
	new_node->rating = 9.5f;
	new_node->next = NULL;

	if (head == NULL)
		head = new_node; 

	print_all(head);

	/* Second node */
	new_node = malloc(sizeof(struct movie));
	if (new_node == NULL)
	{
		printf("ERROR: malloc failed.");
		exit(1);
	}
	strcpy(new_node->title, "Aladdin");
	new_node->rating = 8.0f;
	new_node->next = NULL;

	/* Add front */
	p_movie temp = head;
	head = new_node;
	new_node->next = temp;

	print_all(head);

	/* Third node */
	new_node = malloc(sizeof(struct movie));
	if (new_node == NULL)
	{
		printf("ERROR: malloc failed.");
		exit(1);
	}
	strcpy(new_node->title, "Wonder Woman");
	new_node->rating = 5.3f;
	new_node->next = NULL;

	/* Add back */
	// 1. find last node
	p_movie search = head;
	while (search->next != NULL)
	{
		search = search->next;
	}
	// 2. link
	search->next = new_node;

	print_all(head);

	/* Find and delete an item */
	search = head;
	p_movie prev = NULL;

	int count = 0;
	while (search != NULL)
	{
		if (strcmp(search->title, "Aladdin") == 0) break;

		prev = search;
		search = search->next;
		count++;
	}

	if (search == NULL)
	{
		printf("Wrong title\n");
		return;
	}
	if (prev == NULL)                      // Node1 -> Node2 -> Node3 ์ด๋ ๊ฒ ๋์ด์๋ ๊ตฌ์กฐ์์
		head = search->next;           // Node2๋ฅผ ์ญ์ ํ๊ณ  ์ถ๋ค๋ฉด, prev๋ Node1์ ๊ฐ๋ฆฌํค๊ณ 
	else                                   // search๋ Node2๋ฅผ ๊ฐ๋ฆฌํค๊ฒ ํ๋ค.
		prev->next = search->next;     // ๊ทธ๋ฆฌ๊ณ  prev๊ฐ NULL์ด ์๋๋ฏ๋ก(์ ์ธ ํ์ ๋น์๋ NULL)
	free(search);                          // prev->next์ search->next(Node2->next)๋ฅผ ๋ฃ์ด์ค์ผ๋ก์จ
			                       // Node3๋ฅผ ์ฐ๊ฒฐํด์ค๋ค. ๊ทธ๋ฆฌ๊ณ  search(Node2) ๋์  ๋ฉ๋ชจ๋ฆฌ ํด์ 

	print_all(head);
}                                    


--------------------------------------------------------------------------
	
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
	char title[100];
	float rating;
	struct Node* Next;
};

void print_all(struct Node* head)
{
	struct Node* search = head;
	while (search != NULL)
	{
		printf("title: %s, rating: %f, ", search->title, search->rating);
		printf("Next Pointer: %zd\n", (size_t)search->Next);
		search = search->Next;
	}
	printf("---------------------------------\n");
	return;
}

typedef struct Node* NodePtr;

int main()
{
	NodePtr head = NULL;

	/* First Node */
	NodePtr node1 = malloc(sizeof(struct Node));
	if (node1 == NULL)
	{
		printf("ERROR: malloc failed.");
		exit(1);
	}
	strcpy(node1->title, "Avater");
	node1->rating = 10.0f;
	node1->Next = NULL;

	if (head == NULL)
		head = node1;

	print_all(head);

	/* Second Node */
	NodePtr node2 = malloc(sizeof(struct Node));
	if (node2 == NULL)
	{
		printf("ERROR: malloc failed.");
		exit(1);
	}
	strcpy(node2->title, "Harry Potter");
	node2->rating = 9.4f;
	node2->Next = NULL; 

	/* Linked node1 and node2 */
	node1->Next = node2;
	print_all(head);

	/* Third Node */
	NodePtr node3 = malloc(sizeof(struct Node));
	if (node3 == NULL)
	{
		printf("ERROR: malloc failed.");
		exit(1);
	}
	strcpy(node3->title, "๋ฒ์ฃ๋์");
	node3->rating = 8.5f;
	node3->Next = NULL;

	/* Make third Node is head node */
	head = node3;
	node3->Next = node1;
	print_all(head);

	/* Fourth Node */
	NodePtr node4 = malloc(sizeof(struct Node));
	if (node4 == NULL)
	{
		printf("ERROR: malloc failed");
		exit(1);
	}
	strcpy(node4->title, "๊ทนํ์ง์");
	node4->rating = 7.5f;
	node4->Next = NULL;

	/* locate node4 in between node1 and node2 */
	node3->Next = node4;
	node4->Next = node1;
	print_all(head);

	/* delete Avatar(node1) */
	node4->Next = node2;
	print_all(head);

	/* make node2(Harry Poter) is head node*/
	head = node2;
	node2->Next = node3;
	node4->Next = NULL;
	print_all(head);

	return 0;
}
