#include<iostream>
#include<cstdlib>
using namespace std;

int i, j, k, n, m, s, t, p, q, a[100001], b[100001];

int main()
{
	cin >> n >> m >> k;
	for (i = 0; i < n; i++) cin >> a[i];
	for (i = 0; i < m; i++) cin >> b[i];
	for (i = 0; i < n; i++)
	{
		t = k - a[i];
		p = 0;
		q = m - 1;
		while (p < q)
		{
			s = p + ((q - p) >> 1);
			if (t > b[s]) p = s + 1;
			else
				if (t < b[s]) q = s;
				else
					if (t == b[s])
					{
						cout << "yes";
						exit(0);
					}
		}
	}
	cout << "no";
	return 0;
}