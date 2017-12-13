#include<stdio.h>
#include<stdlib.h>

int i, j, k, n, m, s, t, a[100001];

struct node
{
	int dep;
	int val;
	node *p;
	node *l;
	node *r;
};

node* insert(node *tree, int value);
void updata(node *tree);
int depth(node *tree);
node* aaaavl(node *tree, node *newp);
int papa(node *tree);
node* leftSingle(node *tree);
node* rightSingle(node *tree);
node* leftDouble(node *tree);
node* rightDouble(node *tree);
int haha(node *tree, int pp);

node* insert(node *tree, int value)
{
	node *newp, *nowp;
	newp = new node;
	newp->val = value;
	newp->p = NULL;
	newp->l = NULL;
	newp->r = NULL;
	if (tree == NULL)
	{
		newp->dep = 1;
		tree = newp;
	}
	else
	{
		nowp = tree;
		while (1 > 0)
		{
			if (newp->val <= nowp->val)
			{
				if (nowp->l == NULL)
				{
					nowp->l = newp;
					newp->p = nowp;
					break;
				}
				else
				{
					nowp = nowp->l;
					continue;
				}
			}
			else
			{
				if (nowp->r == NULL)
				{
					nowp->r = newp;
					newp->p = nowp;
					break;
				}
				else
				{
					nowp = nowp->r;
					continue;
				}
			}
		}
		updata(newp);
		tree = aaaavl(tree, newp);
	}
	return tree;
}

void updata(node *tree)
{
	if (tree == NULL) return;
	else
	{
		int l, r;
		l = depth(tree->l);
		r = depth(tree->r);
		tree->dep = 1 + (l > r ? l : r);
	}
}

int depth(node *tree)
{
	if (tree == NULL) return 0;
	else return tree->dep;
}

node* aaaavl(node *tree, node *newp)
{
	int pa;
	while (newp != NULL)
	{
		updata(newp);
		pa = papa(newp);
		if ((pa < -1) || (pa > 1))
		{
			if (pa > 1)
			{
				if (papa(newp->r) > 0)
				{
					newp = leftSingle(newp);
				}
				else
				{
					newp = leftDouble(newp);
				}
			}
			if (pa < -1)
			{
				if (papa(newp->l) < 0)
				{
					newp = rightSingle(newp);
				}
				else
				{
					newp = rightDouble(newp);
				}
			}
			if (newp->p == NULL) tree = newp;
			break;
		}
		newp = newp->p;
	}
	return tree;
}

int papa(node *tree)
{
	if (tree == NULL) return 0;
	else return depth(tree->r) - depth(tree->l);
}

node* leftSingle(node *tree)
{
	node *newroot, *mature;
	mature = tree->p;
	newroot = tree->r;
	if (newroot->l != NULL)
	{
		newroot->l->p = tree;
	}
	tree->r = newroot->l;
	updata(tree);
	newroot->l = tree;
	newroot->p = mature;
	if (mature != NULL)
	{
		if (mature->l == tree)
		{
			mature->l = newroot;
		}
		else
		{
			mature->r = newroot;
		}
	}
	tree->p = newroot;
	updata(newroot);
	return newroot;
}

node* rightSingle(node *tree)
{
	node *newroot, *mature, *naive;
	mature = tree->p;
	newroot = tree->l;
	if (newroot->r != NULL)
	{
		newroot->r->p = tree;
	}
	tree->l = newroot->r;
	updata(tree);
	newroot->r = tree;
	newroot->p = mature;
	if (mature != NULL)
	{
		if (mature->l == tree)
		{
			mature->l = newroot;
		}
		else
		{
			mature->r = newroot;
		}
	}
	tree->p = newroot;
	updata(newroot);
	return newroot;
}

node* leftDouble(node *tree)
{
	rightSingle(tree->r);
	return leftSingle(tree);
}

node* rightDouble(node *tree)
{
	leftSingle(tree->l);
	return rightSingle(tree);
}

int haha(node *tree, int pp)
{
	node *nowp;
	int qq;
	qq = 1;
	nowp = tree;
	while (nowp)
	{
		if (nowp->val > pp)
		{
			nowp = nowp->l;
			qq++;
		}
		else
		{
			if (nowp->val < pp)
			{
				nowp = nowp->r;
				qq++;
			}
			else break;
		}
	}
	return qq;
}

int main()
{
	node *tree, *now;
	int val;
	tree = NULL;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		tree = insert(tree, a[i]);
	}
	printf("%d", haha(tree, a[0]));
	for (i = 1; i < n; i++)
		printf(" %d", haha(tree, a[i]));
	return 0;
}