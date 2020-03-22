#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int N, i, nr;
	printf("numaru de elemente : ");
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		printf("Dati elementu nr %d : ", i + 1);
		scanf("%d", &nr);
		if (((nr << 31 )|0)==0)
			printf("\n%d este par\n", nr);
		else
			printf("\n%d este impar\n", nr);
	}
	system("pause");
	return 0;

}