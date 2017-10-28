#include<iostream>
#include<string>
using namespace std;

int i, j, k, n, m, s, t, a[1500];
string c;

int main()
{
	scanf("%d", &n);
	i = 0;
	while (n--)
	{
		cin >> c;
		switch (c[0])
		{
		case 'I':
		{
			if (c == "IN")
			{
				scanf("%d", &m);
				a[i] = m;
				i++;
			}
			break;
		}
		case 'P':
		{
			if (c == "POP")
			{
				if (i >= 1) i--;
			}
			break;
		}
		case 'A':
		{
			if (c == "ASUB")
			{
				if (i >= 2)
				{
					i -= 2;
					m = a[i] - a[i + 1];
					a[i++] = m >= 0 ? m : -m;
				}
			}
			break;
		}
		case 'C':
		{
			if (c == "COPY")
			{
				if (i >= 1)
				{
					a[i++] = a[i - 1];
				}
			}
			break;
		}
		}
	}
	if (i >= 0)
	{
		s = 0;
		for (j = 0; j < i; j++)
			s += a[j];
		printf("%d", s);
	}
	else printf("%d", 0);
	return 0;
}