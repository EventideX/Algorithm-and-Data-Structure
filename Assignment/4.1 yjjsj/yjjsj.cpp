#include<stdio.h>

int i, j, k, n, m, s, t, p, a[100001][2];

int main()
{
	scanf("%d%d%d", &n, &p, &k);
	printf("%d\n", n / k);
	for (i = 2; i < n; i++)
	{
		a[i][0] = i - 1;
		a[i][1] = i + 1;
	}
	a[1][0] = n;
	a[1][1] = 2;
	a[n][0] = n - 1;
	a[n][1] = 1;
	i = 0;
	j = 1;
	t = n;
	s = n - n%k;
	while (i < n)
	{
		i++;
		if (i%k == 0)
		{
			if (i < s) printf("%d ", j);
			else
			{
				printf("%d", j);
				break;
			}
		}
		a[a[j][0]][1] = a[j][1];
		a[a[j][1]][0] = a[j][0];
		t--;
		j = a[j][1];
		if (t >= p)
		{
			m = 0;
			while (m < p)
			{
				j = a[j][1];
				m++;
			}
		}
	}
	return 0;
}