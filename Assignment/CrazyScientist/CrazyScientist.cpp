#include<stdio.h>

int i, j, k, n, m, s, t, p, a[2010], b[80010][3], c[2010];
bool d[2010];

void q(int k)
{
	int i, j;
	d[k] = true;
	i = a[k];
	while (i != 0)
	{
		j = b[i][0];
		if (c[k] + b[i][1] < c[j])
		{
			c[j] = c[k] + b[i][1];
			if ((d[j] == true) || (p == 1))
			{
				p = 1;
				if (d[s] == true)
				{
					t = 1;
				}
				break;
			}
			q(j);
		}
		i = b[i][2];
	}
	d[k] = false;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++)
	{
		a[i] = 0;
		c[i] = 0;
		d[i] = false;
	}
	s = 0;
	for (i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &j, &k, &t);
		s++;
		b[s][0] = k;
		b[s][1] = t;
		b[s][2] = a[j];
		a[j] = s;
	}
	scanf("%d", &s);
	t = 0;
	for (i = 1; i <= n; i++)
	{
		p = 0;
		q(i);
		if (t == 1) break;
	}
	if (t == 1)
		printf("EL PSY CONGROO");
	else
		printf("ttt");
	return 0;
}