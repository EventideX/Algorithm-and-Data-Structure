#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int a[200000], b[200000];
__int64 s;

void p(int l, int m, int r)
{
	int i = l;
	int j = m + 1;
	int k = l;
	while (i <= m && j <= r)
	{
		if (a[i] < a[j])
		{
			b[k++] = a[j++];
			s += m - i + 1;
		}
		else
		{
			b[k++] = a[i++];
		}
	}
	while (i <= m) b[k++] = a[i++];
	while (j <= r) b[k++] = a[j++];
	for (i = l; i <= r; i++)
		a[i] = b[i];
}

void q(int l, int r)
{
	if (l < r)
	{
		int m = (l + r) >> 1;
		q(l, m);
		q(m + 1, r);
		p(l, m, r);
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i<n; i++)
		scanf("%d", &a[i]);
	s = 0;
	q(0, n - 1);
	printf("%I64d", s);
	return 0;
}