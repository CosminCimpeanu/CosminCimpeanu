#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *a, *s,*n,*i;

	n = (int*)malloc(sizeof(int));
	s = (int*)malloc(sizeof(int));
	i = (int*)malloc(sizeof(int));

	printf("Cate elemente doriti: ");
	scanf("%d", n);
	a = (int*)malloc(sizeof(int) * (*n));	
	*s = 0;

	for (*i = 0; *i < *n; (*i)++)
	{
		printf("a[%d]=", *i);
		scanf("%d", (a + *i));
		*s = *s + *(a + *i);
	}
	printf("s=%d ", *s);
	system("pause");
	return 0;
}
