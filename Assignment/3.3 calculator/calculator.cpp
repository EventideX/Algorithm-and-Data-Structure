#include<stdio.h>
#include<string.h>

int i, j, k, n, m, s, t, a[1000];
char b[2000], c[2000], d[2000];

int main()
{
	scanf("%s", &b);
	i = 0;
	j = 0;
	k = 0;
	n = strlen(b);
	while (i < n)
	{
		if ((b[i] >= '0') && (b[i] <= '9'))
		{
			while ((b[i] >= '0') && (b[i] <= '9'))
			{
				c[j++] = b[i++];
			}
			c[j++] = '!';
		}
		if ((b[i] == '+') || (b[i] == '-'))
		{
			while ((k > 0) && (d[k - 1] != '('))
			{
				c[j++] = d[k - 1];
				k--;
			}
			d[k++] = b[i];
		}
		if ((b[i] == '*') || (b[i] == '/'))
		{
			while ((k > 0) && (d[k - 1] != '(') && ((d[k - 1] == '*') || (d[k - 1] == '/')))
			{
				c[j++] = d[k - 1];
				k--;
			}
			d[k++] = b[i];
		}
		if (b[i] == '(')
		{
			d[k++] = b[i];
		}
		if (b[i] == ')')
		{
			while ((k > 0) && (d[k - 1] != '('))
			{
				c[j++] = d[k - 1];
				k--;
			}
			if (k > 0) k--;
		}
		i++;
	}
	while (k > 0)
	{
		c[j++] = d[k - 1];
		k--;
	}
	c[j] = '\0';
	i = 0;
	j = -1;
	while (c[i] != '\0')
	{
		if ((c[i] >= '0') && (c[i] <= '9'))
		{
			double x = 0;
			while ((c[i] >= '0') && (c[i] <= '9'))
			{
				x = 10 * x + c[i] - '0';
				i++;
			}
			j++;
			a[j] = x;
		}
		else
		{
			j--;
			switch (c[i])
			{
			case '+':
			{
				a[j] += a[j + 1];
				break;
			}
			case '-':
			{
				a[j] -= a[j + 1];
				break;
			}
			case '*':
			{
				a[j] *= a[j + 1];
				break;
			}
			case '/':
			{
				a[j] /= a[j + 1];
				break;
			}
			}
		}
		i++;
	}
	printf("%d", a[j]);
	return 0;
}