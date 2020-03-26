#include <stdio.h>
#include <stdlib.h>
void suma(int v[], int n, int *s)
{
	int i;
	*s = 0;
	for (i = 0; i < n; i++)
		*s = *s + v[i];
}
int main()
{
	int v[10], n, i, s;
	printf("Cate elemente doriti? : ");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("a[%d]=",i);
		scanf("%d", &a[i]);
	}
	suma(v, n, &s);
	printf("s=%d", s);
	system("pause");
	return 0;
}
