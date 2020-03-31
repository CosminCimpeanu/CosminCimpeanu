#include<stdio.h>
#include<stdlib.h>
#define CAPACITY 8

int stack[CAPACITY];
int arr[8];
int top = -1;

int baza10_2(int numar) 
{
	int b = 2, nr_nou, p, r;
	nr_nou= 0;
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

void push(int element)
{
	if (isFull())
		printf("Stiva este plina \n");
	else
	{
		top++;
		stack[top] = element;
	}
}

int isFull()
{
	if (top == CAPACITY - 1)
		return 1;
	else 
		return 0;
}



int pop()
{
	if (isEmpty())
		return 0;
	else
		return stack[top--];
}

int isEmpty()
{
	if (top == -1)
		return 1;
	else
		return 0;
}

void afisare()
{
	if (isEmpty())
		printf("Stiva este goala \n");
	else
	{
		int j;
		printf("Elemente stiva : \n");
		for (j = 0; j <= top; j++)
			printf("%d \n", stack[j]);
	}
}

int main()
{
	int nr, baza2, i,k=0;
	printf("Introduceti un numar:");
	scanf("%d", &nr);
	if (nr <= 255)
	{
		baza2 = baza10_2(nr);
	}
	else printf("Numar gresit!");
	for (i = 0; i < 8; i++)
	{
		arr[i] = baza2 % 10;
		push(arr[i]);
		baza2 = baza2 / 10;
	}
	
	afisare();

	for (i = 0; i < 8; i++)
	{
		if (pop() == 1) k++;
	}

	//printf("%d\n", k);
	for (i = 0; i < 8; i++)
	{
		if (k > 0) printf("1");
		else printf("0");
		k--;
	}
	return 0;
}