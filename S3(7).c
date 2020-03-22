#include<stdio.h>
#include<stdlib.h>

int main()
{
	int N, bit, contor = 0, i,num;
	printf("N=");
	scanf("%d", &N);
	for (i = 1; i <= N; i++)
	{
		num = i;
		while (num != 0)
		{
			bit = num % 2;
			num = num / 2;
			if (bit == 1) contor++;
		}
	}
	printf("%d ", contor);

	system("pause");
	return 0;
}