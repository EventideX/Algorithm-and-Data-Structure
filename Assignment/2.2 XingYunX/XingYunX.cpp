#include<stdio.h>

int main()
{
	int a;
	scanf("%d", &a);
	printf("%d", a % 2 == 0 ? a >> 1 : a);
	return 0;
}