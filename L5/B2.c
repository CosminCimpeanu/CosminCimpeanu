#include<stdio.h>
#include<stdlib.h>

#define CAPACITY 35

int stack[CAPACITY];
int top = -1;

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
	int C,N,i,nr,numar_afisare;
	printf("C=");
	scanf("%d", &C);
	printf("N=");
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		printf("Nr=");
		scanf("%d", &nr);
		numar_afisare = nr;
		nr = baza10_2(nr);
		//printf("%d %d\n", numar_afisare, nr);
		if (((nr >> C) & 1) == 1) push(numar_afisare);
	}
	afisare();
	return 0;
}
