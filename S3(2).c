`#include<stdio.h>
#include<stdlib.h>

int main()
{
	int c, n, N, bit, contor;
	printf("N=");
	scanf("%d", &N);
	printf("c=");
	scanf("%d", &c);
	contor = 0;
	for (int i = 0; i < N ; i++)
	{
		printf("n=");
		scanf("%d", &n);
		int k = 0;       //contor pentru pozitia pe care am ajuns
		while (n != 0)
		{
			bit = n % 2;
			n = n / 2;
			k++;
			if ((k == c) && (bit == 1) )contor++; //contorizeaza in total cate numare care indeplinesc conditia avem
		}
	}
	printf("%d", contor);

	system("pause");
	return 0;
}