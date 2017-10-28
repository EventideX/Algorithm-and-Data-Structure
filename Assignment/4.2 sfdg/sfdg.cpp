#include<stdio.h>

int i, j, k, n, m, s, t, p, q, x, y, z, a[100001];

int main()
{
	scanf("%d%d", &n, &k);
	for (i = 0; i < n; i++) scanf("%d", &a[i]);
	s = -2000;
	z = -2000;
	i = 0;
	while (i < n)
	{
		t = 0;
		p = i;
		for (j = i; (j < i + k) && (j < n); j++)
		{
			if (a[j] > z)
			{
				z = a[j];
				q = j;
			}
			t += a[j];
			if (t < 0)
			{
				i = j;
				break;
			}
			else
				if (t > s)
				{
					s = t;
					x = p;
					y = j;
				}
		}
		i++;
	}
	if ((s > z) || ((s == z) && (x < q))) printf("%d %d %d", s, x + 1, y + 1);
	else printf("%d %d %d", z, q + 1, q + 1);
	return 0;
}