#include<iostream>
using namespace std;

int gcd(int x, int y)
{
	if (y == 0) return x;
	else return gcd(y, x%y);
}

int i, j, k, n, m, s, t, a[100001], b[100001], c[100001];

int main()
{
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> a[i];
	b[0] = a[0];
	for (i = 1; i < n; i++)
		b[i] = gcd(b[i - 1], a[i]);
	c[n - 1] = a[n - 1];
	for (i = n - 2; i >= 0; i--)
		c[i] = gcd(c[i + 1], a[i]);
	if (b[n - 2] > c[1]) s = b[n - 2];
	else s = c[1];
	for (i = 1; i < n - 1; i++)
	{
		t = gcd(b[i - 1], c[i + 1]);
		if (t > s) s = t;
	}
	cout << s;
	return 0;
}