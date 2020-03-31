#include<stdio.h>
#include<stdlib.h>
#define CAPACITY 16

int stack2[CAPACITY];
int stack10[CAPACITY];
int arr2[16];
int arr10[16];
int top2 = -1;
int top10 = -1;

//verificam daca vectorul pe care il introducem este palindrom
int palindrom(int arr[], int lg) 
{
	int aux, ogl, i;
	for (i = 1; i <= lg; i++)
	{
		aux = arr[i];
		ogl = 0;
		while (aux != 0)
		{
			ogl = ogl * 10 + aux / 10;
			aux = aux / 10;
		}
		if (ogl == arr[i]) return 1;
		else return 0;
	}
}

//transformam
int  baza10_2(int numar)
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

int pop2()
{
	if (isEmpty2())
		return 0;
	else
		return stack2[top2--];
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
		printf("Stack elements : \n");
		for (j = 0; j <= top2; j++)
			printf("%d \n", stack2[j]);
	}
}

int stiva2(int numar)
{
	//val pentru a vedea cate elemente are vectorul pe care il testam in palindrom
	int baza2, i, k = 0, val;
	baza2 = baza10_2(numar);
	for (i = 0; i < 16; i++)
	{
		arr2[i] = baza2 % 10;
		push2(arr2[i]);
		baza2 = baza2 / 10;
	}
	i = 16;
	while ((i > 0) && (k==0))
	{
		if (arr2[i] == 1)
		{
			k = 1;
			val = i;
		}
		i--;
	}
	afisare2();
	
	for (i = 16; i >16 -val; i--)
	{
		arr2[i] = pop2();
	}
	if (palindrom(arr2, val) == 1) printf("DA");
	else printf("NU");
}


void push10(int element)
{
	if (isFull10())
		printf("Stiva este plina \n");
	else
	{
		top10++;
		stack10[top10] = element;
	}
}

int isFull10()
{
	if (top10 == CAPACITY - 1)
		return 1;
	else
		return 0;
}

int pop10()
{
	if (isEmpty10())
		return 0;
	else
		return stack10[top10--];
}

int isEmpty10()
{
	if (top10 == -1)
		return 1;
	else
		return 0;
}


void afisare10()
{
	if (isEmpty10())
		printf("Stiva este goala \n");
	else
	{
		int k;
		printf("Stack elements : \n");
		for (k = 0; k <= top10; k++)
			printf("%d \n", stack10[k]);
	}
}

int stiva10(int numar)
{
	//k pentru a vedea cate cifre are numar si ulterior cate 
	//elemente are vectorul pe care il vom testa capalindrom
	int i, k = 0, aux;
	aux = numar;
	
	while (aux != 0)
	{
		aux = aux / 10;
		k++;
	}
	
	for (i = 0; i < 16; i++)
	{
		arr10[i] = numar % 10;
		push10(arr10[i]);
		numar = numar / 10;
	}
	
	afisare10();
	for (i = 16; i >16- k; i--)
	{
		arr10[i] = pop10();
	}
	if (palindrom(arr10, k) == 0) printf("DA");
	else printf("NU");
}


int main()
{
	int nr;
	printf("Introduceti numarl: \n");
	scanf("%d", &nr);
	if (nr < 65535)
	{
		if ((stiva10(nr) == 0) && (stiva2(nr) == 1)) printf("sunt palindroame");
		else printf("nu sunt palindroame");
		
	}
	else printf("NUMARUL ESTE GRESIT");

	return 0;
}