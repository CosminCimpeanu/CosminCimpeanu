#include<stdio.h>
#include<stdlib.h>

int inmultire(int a, int b)
{
	int rez = 0, poz = 0;
	while (b != 0)
	{
		if (b % 2 == 1) rez += a << poz;
		poz++;
		b = b / 2;
	}
	return rez;
}

int main()
{
	int a, b;
	printf("a=");
	scanf("%d", &a);
	printf("b=");
	scanf("%d", &b);
	printf("%d", inmultire(a, b));
	return 0;
}
