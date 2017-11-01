#include<stdio.h>
#include<string.h>

struct TreeNode
{
	int p,son[2],x,FirstTime;
};

TreeNode tree[100001];
int n,m;

void InitializationSearch(int CurrentNode,int &Time){
	tree[CurrentNode].FirstTime=Time;
	int NextNode=0;
	if (tree[CurrentNode].son[NextNode]!=0){
		if (tree[CurrentNode].son[NextNode^1]!=0){
			if (tree[tree[CurrentNode].son[NextNode^1]].x>tree[tree[CurrentNode].son[NextNode]].x){
				++Time;
				InitializationSearch(tree[CurrentNode].son[NextNode^1],Time);
				++Time;
				InitializationSearch(tree[CurrentNode].son[NextNode],Time);
			}else{
				++Time;
				InitializationSearch(tree[CurrentNode].son[NextNode],Time);
				++Time;
				InitializationSearch(tree[CurrentNode].son[NextNode^1],Time);
			};
		}else{
			++Time;
			InitializationSearch(tree[CurrentNode].son[NextNode],Time);
		};
	};
	++Time;
}

int main(){
	scanf("%d",&n);
	memset(tree,0,sizeof(tree));
	for (int i=2;i<=n;++i){
		scanf("%d %d",&tree[i].p,&tree[i].x);
		if (tree[tree[i].p].son[0]!=0)
			tree[tree[i].p].son[1]=i;
		else tree[tree[i].p].son[0]=i;
	};
	int Time=0;
	InitializationSearch(1,Time);
	scanf("%d",&m);
	for (int j=1;j<=m;++j){
		int kj;
		scanf("%d",&kj);
		printf("%d\n",tree[kj].FirstTime);
	};
	return 0;
}