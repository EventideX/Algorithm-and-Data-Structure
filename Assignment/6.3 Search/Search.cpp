#include<stdio.h>
#include<string.h>

struct tree
{
	int p, b[2], x, t;
};

tree a[100001];
int i, j, k, n, m, s, t;

void q(int now, int &s)
{
	int next = 0;
	a[now].t = s;
	if (a[now].b[next] != 0)
	{
		if (a[now].b[next ^ 1] != 0)
		{
			if (a[a[now].b[next ^ 1]].x>a[a[now].b[next]].x)
			{
				s++;
				q(a[now].b[next ^ 1], s);
				s++;
				q(a[now].b[next], s);
			}
			else
			{
				s++;
				q(a[now].b[next], s);
				s++;
				q(a[now].b[next ^ 1], s);
			}
		}
		else
		{
			s++;
			q(a[now].b[next], s);
		}
	}
	s++;
}

int main()
{
	scanf("%d", &n);
	memset(a, 0, sizeof(a));
	for (i = 2; i <= n; i++)
	{
		scanf("%d %d", &a[i].p, &a[i].x);
		if (a[a[i].p].b[0] != 0)
			a[a[i].p].b[1] = i;
		else a[a[i].p].b[0] = i;
	}
	s = 0;
	q(1, s);
	scanf("%d", &m);
	for (j = 1; j <= m; j++)
	{
		scanf("%d", &k);
		printf("%d\n", a[k].t);
	}
	return 0;
}