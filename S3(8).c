#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a, b = 2, rez = 1;
	printf("a=");
	scanf("%d", &a);
	while (b > 0)
	{
		if (b & 1) rez = rez * a;
		a = a * a;
		b = b >> 1;
	}
	printf("%d\n", rez);
	system("pause");
	return 0;
}