#include<stdio.h>
int a[100001],b[100001],c[100001],po[100001],ans[100001],n,m,zero_tot=0,a_tot=0;
void qsort(int *num,int l,int r){
	int i=l,j=r,mid=num[(i+j)>>1];
	while(i<=j){
		while (num[i]<mid) ++i;
		while (num[j]>mid) --j;
		if (i<=j){
			int tmp=num[i];num[i]=num[j];num[j]=tmp;
			++i;--j;
		};
	};
	if (j>l) qsort(num,l,j); 
	if (i<r) qsort(num,i,r);
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	};
	for (int i=1;i<=n;++i){
		if (a[i]==0){
			po[++zero_tot]=i;
		}else{
			c[++a_tot]=a[i];
		};
	};
	for (int i=1;i<=m;++i){
		scanf("%d",&b[i]);
	};
	qsort(c,1,a_tot);
	qsort(b,1,m);
	int b_insert=1,c_insert=1,judge=0;
	for (int i=1;i<=n;++i){
		if (b_insert<=m && po[b_insert]==i){
			ans[i]=b[b_insert++];
		}else{
			ans[i]=c[c_insert++];
		};
		if (i>1 && ans[i]<ans[i-1]){
			judge=1;
			break;
		};
	};
	if (judge==1){
		printf("-1");
	}else{
		for (int i=1;i<= n;++i){
			printf("%d ",ans[i]);
		};
	};
	return 0;
}