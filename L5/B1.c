#include<stdio.h>
#include<stdlib.h>
#define CAPACITY 30

int top = -1;
int stack[CAPACITY];

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

int binar_invers(int nr)
{
	nr = nr ^ 255;
	baza10_2(nr);
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
		{
			printf("%d ", stack[j]);
			printf("\n");
		}
			
	}
}

int main()
{
	int N, i, nr, nr_nou;
	printf("N=");
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		printf("nr=");
		scanf("%d", &nr);
		//printf("%d\n", binar_invers(nr));
		push(binar_invers(nr));
	}
	afisare();
	return 0;
}