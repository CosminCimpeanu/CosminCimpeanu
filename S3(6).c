#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int ZecimalBinar(int n)
{
	int rez = 0, p = 1;
	while (n)
	{
		rez = rez + n % 2 * p;
		n = n / 2;
		p = p * 10;
	}
	printf("%d\n", rez);
}

int Max(int nr)
{
	int i, c = 0, nr_nou = 0;
	while (nr != 0)  //aflam catid e 1 avem in numarul in binar
	{
		nr = nr & (nr - 1);
		c++;
	}
	for (i = 7; i > 7 - c; i--)
	{
		nr_nou = nr_nou + pow(2, i);
	}
	printf("%d", ZecimalBinar(nr_nou));
}

int main()
{
	int nr;
	printf("nr=");
	scanf("%d", &nr);
	ZecimalBinar(nr);
	Max(nr);
	system("pause");
	return 0;
	//afiseaza la final de fiecare data un 9 dar nu imi dau seama de ce:((
}