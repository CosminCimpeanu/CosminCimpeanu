#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 7

int isFull(int* top)
{
	if (*top == MAX)
		return 1;
	return 0;
}

void push(int* x, int* top, int* stack)
{
	if (isFull(top))
	{
		printf("Eroare! Stiva este plina!\n");
		return;
	}
	stack[++(*top)] = *x;
}
void pop(int* top, int* stack)
{
	if (*top == -1)
	{
		printf("Eroare!\n");
	}
	(*top)--;
}
int peek(int* top, int* stack)
{
	return stack[*top];
}
int isEmpty(int* top)
{
	if (*top == -1)
		return 1;
	return 0;
}
void print(int* top, int* stack)
{
	int* i = (int*)malloc(sizeof(int));
	printf("Stiva:\n");
	for (*i = 0; *i <= *top; (*i)++)
	{
		printf("%d\n", stack[*i]);
	}
	printf("\n");
}
int main()
{
	int* x = (int*)malloc(sizeof(int));
	int* i = (int*)malloc(sizeof(int));
	int* stack = (int*)malloc(sizeof(int) * MAX);
	int* top = (int*)malloc(sizeof(int));
	*top = -1;
	printf("Introducetin cele 7 numnere: \n");
	for (*i = 0; *i < 7; (*i)++)
	{
		printf("Numarul %d = ", *i + 1);
		scanf("%d", x);
		push(x, top, stack);
	}
	int *opt=(int*)malloc(sizeof(int));
	do
	{
		printf("1.Peek \n");
		printf("2.Top \n"); //varf
		printf("3.Print \n");
		printf("Opt=");
		scanf("%d", opt);
		switch(*opt)
		{
			case 1:
				pop(top, stack);
				break;
			case 2:
				printf("%d \n",peek(top, stack));
				break;
			case 3:
				print(top, stack);
				break;
			case 0:
				exit(0);
			default:printf("opt gresita! \n");
				break;
		}
	} while (opt != 0);
	return 0;
}