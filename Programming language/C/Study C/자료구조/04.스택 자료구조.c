π main.c π

#include <stdio.h>
#include "stack.h"

print_stack(const Stack* stack)
{
	printf("Stack : ");
	if (IsEmpty(stack) == true)
		printf("Empty");
	else
		for (int i = 0; i < stack->top; ++i)
			printf("%d ", stack->items[i].key);
	printf("\n");
}

element get_element(const int key)
{
	element new_element;
	new_element.key = key;
	return new_element;
}

int main()
{
	Stack my_stack;

	Initialize(&my_stack);
	print_stack(&my_stack);

	Push(&my_stack, get_element(1));
	print_stack(&my_stack);

	Push(&my_stack, get_element(3));
	print_stack(&my_stack);

	Push(&my_stack, get_element(4));
	print_stack(&my_stack);

	Push(&my_stack, get_element(5));
	print_stack(&my_stack);

	Push(&my_stack, get_element(6));
	print_stack(&my_stack);

	Push(&my_stack, get_element(7));
	print_stack(&my_stack);

	for (int i = 0; i < MAX_STACK_SIZE + 1; ++i)
	{
		printf("Pop : %d\n", Pop(&my_stack).key);
		print_stack(&my_stack);
	}
	return 0;
}


π stack.c π

#include <stdio.h>
#include "stack.h"

void Initialize(Stack* stack)  // stackμ μμ¬μλ λͺ¨λ  κ²λ€ μ΄κΈ°ν
{
	stack->top = 0;  // topμ 0μΌλ‘ λκΈ°

	for(int i = 0; i < MAX_STACK_SIZE; ++i)
		stack->items[i].key = -1;
}

bool IsFull(const Stack* stack)  // μ€νμ΄ κ°λ μ°Όμμ μλ¦¬λ ν¨μ
{
	if (stack->top < MAX_STACK_SIZE)
		return true;
	else
		return false;
}

bool IsEmpty(const Stack* stack) // μ€νμ΄ λΉμ΄μ λμ΄μ νμ λͺ»ν¨μ μλ¦¬λ ν¨μ
{
	if (stack->top == 0)
		return true;
	else
		return false;
}

void Push(Stack* stack, element item) // Push
{
	//stack->items[stack->top++].key = item.key; 
	// μ΄λ κ² λ©€λ²λ λ©€λ²μ λ³΅μ¬λ₯Ό μ΄μ© κ°λ₯

	if(IsFull(stack))
		stack->items[stack->top++].key = item.key;
	else
		printf("Stack is full. Cannot add.\n");
}

element Pop(Stack* stack)
{
	if (IsEmpty(stack))
	{
		Initialize(stack);
		printf("Stack is empty. Cannot remove.\n");
	}
	else
	{
		stack->top--;
	}
	return stack->items[stack->top];
}


π stack.h π

#pragma once

#include <stdbool.h>
#include "element.h"

#define MAX_STACK_SIZE 5

typedef struct stack
{
	element items[MAX_STACK_SIZE];
	int top;
}Stack;

void Initialize(Stack* stack);
bool IsFull(const Stack* stack);
bool IsEmpty(const Stack* stack);
void Push(Stack* stack, element item);
element Pop(Stack* stack);


π element.h π

#pragma once

typedef struct
{
	int key;
} element;
