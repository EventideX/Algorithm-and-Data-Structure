#include<stdio.h>

int main()
{
	int i, k, n, m, t, x;
	scanf("%d%d%d", &n, &m, &x);
	x %= n;
	if (x == 0) x = n;
	t = 0;
	if (x > n / 2)
	{
		x = n - x + 1;
		t++;
	}
	for (i = 0; i < m; i++)
	{
		scanf("%d", &k);
		if (k <= x) t++;
	}
	printf("%d", t % 2 == 0 ? x : n - x + 1);
	return 0;
}