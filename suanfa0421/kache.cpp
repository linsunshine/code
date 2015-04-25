#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct haha
{
	double cost;
	double val;
	double cmp;
}a[1000000+100];
int bag[100000];
int cp(const void *a,const void *b)
{
	return (*(struct haha*)b).cmp>(*(struct haha*)a).cmp?1:-1;
}
int main()
{
    int m,i;
	double ans,n;
	while(scanf("%lf %d",&n,&m)!=EOF)
	{
		ans=0;
          for(i=0;i<m;i++)
		  {
			  scanf("%lf %lf",&a[i].cost,&a[i].val);
			  a[i].cmp=a[i].val/a[i].cost;
		  }
		  qsort(a,m,sizeof(a[0]),cp);
		  for(i=0;i<m;i++)
		  {
			  if(n<=0) break;
			  if(a[i].cost<=n)
			  {
				  ans+=a[i].val;n=n-a[i].cost;
			  }
			  else
			  {
                   ans+=a[i].cmp*n;n=0;
			  }
		  }
		  printf("%lf\n",ans);
	}
	return 0;
}
