#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	long long int x;
	printf("x=");
	scanf("%lli", &x);
	if ((x | (0 << 7)) == (0 << 7))
		printf("0\n"); //este egal cu 0
	else if ((x & (1 << 7)) == (1 << 7))
		printf("Negativ\n");
	else
		printf("Pozitiv\n");

	system("pause");
	return 0;
}