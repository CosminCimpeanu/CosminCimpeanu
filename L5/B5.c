#include<stdio.h>
#include<stdlib.h>
#define CAPACITY 50

int stack1[CAPACITY];
int top1 = -1;
int stack2[CAPACITY];
int top2 = -1;

int baza10_2(int numar)
{
	int b = 2, nr_nou, p, r;
	nr_nou = 0;
	p = 1;
	while (numar != 0)
	{
		r = numar % b;
		nr_nou = nr_nou + r * p;
		p = p * 10;
		numar = numar / b;
	}
	return nr_nou;
}

int numarPrim(int numar)
{
	if (numar < 2)
		return 0;
	if (numar == 2)
		return 1;
	for (int i = 2; i <= numar / 2; i++)
		if (numar % i == 0)
			return 0;
	return 1;
}

void stergePrim()
{
	int i, j;
	for (i = 0; i <= top1; i++)
	{
		if (numarPrim(stack1[i])==1)
		{
			for (j = i; j < top1; j++)
			{
				stack1[j] = stack1[j + 1];
			}
			--i;
			--top1;
		}
	}
}

void push1(int element)
{
	if (isFull1())
		printf("Stiva este plina \n");
	else
	{
		top1++;
		stack1[top1] = element;
	}
}

int isFull1()
{
	if (top1 == CAPACITY - 1)
		return 1;
	else
		return 0;
}

void push2(int element)
{
	if (isFull2())
		printf("Stiva este plina \n");
	else
	{
		top2++;
		stack2[top2] = element;
	}
}

int isFull2()
{
	if (top2 == CAPACITY - 1)
		return 1;
	else
		return 0;
}

int isEmpty1()
{
	if (top1 == -1)
		return 1;
	else
		return 0;
}

void afisare1()
{
	if (isEmpty1())
		printf("Stiva este goala \n");
	else
	{
		int j;
		printf("Elemente stiva baza 10(neprime) : \n");
		for (j = 0; j <= top1; j++)
			printf("%d \n", stack1[j]);
	}
}

int isEmpty2()
{
	if (top2 == -1)
		return 1;
	else
		return 0;
}

void afisare2()
{
	if (isEmpty2())
		printf("Stiva este goala \n");
	else
	{
		int j;
		printf("Elemente stiva baza 2(prime) : \n");
		for (j = 0; j <= top2; j++)
			printf("%d \n", stack2[j]);
	}
}

int main()
{
	int i;
	for (i = 1; i <= 50; i++)
	{
		push1(i);
		if (numarPrim(i)==1)
		{
			push2(baza10_2(i));
		}
	}
	stergePrim();
	afisare1();
	printf("\n");
	afisare2();
	return 0;
}