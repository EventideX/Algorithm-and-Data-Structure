#include<stdio.h>
#include<string.h>

int son[100001],tree[100001],x[100001],nxt[100001],Thieves[100001],MaxThief[100001],top=0,n,m;

void PushTree(int p,int s){
	tree[++top]=s;
	nxt[top]=son[p];
	son[p]=top;
}

void Reset(int *Arr){
	memset(Arr,0,sizeof(Arr));
}

int Max(int x,int y){
	return x>y?x:y;
}

void Search(int Node){
	int NextNode=son[Node];
	while (NextNode!=0){
		Search(tree[NextNode]);
		Thieves[Node]+=Thieves[tree[NextNode]]+x[tree[NextNode]];
		MaxThief[Node]=Max(x[tree[NextNode]],Max(MaxThief[Node],MaxThief[tree[NextNode]]));
		NextNode=nxt[NextNode];
	};
}

int main(){
	scanf("%d",&n);
	Reset(son);
	Reset(tree);
	Reset(x);
	Reset(nxt);
	Reset(Thieves);
	Reset(MaxThief);
	for (int i=2;i<=n;++i){
		int p;
		scanf("%d%d",&p,&x[i]);
		PushTree(p,i);
	};
	Search(1);
	scanf("%d",&m);
	for (int j=1;j<=m;++j){
		int kj;
		scanf("%d",&kj);
		printf("%d %d\n",Thieves[kj],MaxThief[kj]);
	};
	return 0;
}