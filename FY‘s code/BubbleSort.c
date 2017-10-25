#include<stdio.h>
int p[100001],tree[300001],n,zkw_length,ans[100001];
int min(int x,int y){
	return x<y?x:y;
}
int max(int x,int y){
	return x>y?x:y;
}
int getsum(int l,int r){
	int sum=0;
	l+=zkw_length-1;r+=zkw_length+1;
    while (l^r !=1 && l!=r){
		if (l&1==0) sum+=tree[l^1];
		if (r&1==1) sum+=tree[r^1];
		l>>=1;
		r>>=1;
	};
	return sum;
}
void sifup(int k){
	k>>=1;
	while (k>1){
		tree[k]=tree[k<<1]+tree[(k<<1)+1];
		k>>=1;
	};
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		scanf("%d",&p[i]);
	};
	zkw_length=1;
	while (zkw_length<=n) zkw_length<<=1;
	for (int i=zkw_length+1;i<=zkw_length+n;++i){
		tree[i]=1;
	};
	for (int i=zkw_length-1;i>0;--i){
		tree[i]=tree[i<<1]+tree[(i<<1)+1];
	};
	for (int i=1;i<=n;++i){
		int max_right=getsum(1,p[i]-1)+i;
		ans[p[i]]=max(p[i],max(max_right,i))-min(p[i],min(max_right,i));
		tree[zkw_length+p[i]]=0;
		sifup(zkw_length+p[i]);
	};
	for (int i=1;i<=n;++i){
		printf("%d ",ans[i]);
	};
	return 0;
}