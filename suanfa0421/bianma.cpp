#include<stdio.h>
#include<string.h>
#define len 100000
struct haha
{
    int start;
    int l[len];
    int weight;
}code[100],cd;
struct xixi
{
    int weight;
    int parent;
    int l_child;
    int r_child;
}tree[100];
int a[300];
int main()
{
    char c[100000+10];
    int n,i,j,m,d,m1,m2,x1,x2,pare,child,ans,temp,cnt;
    while(scanf("%s",c)!=EOF)
    {
        ans=0;
        n=0;
        d=strlen(c);
        memset(a,0,sizeof(a));
        for(i=0;i<d;i++)
		{
			a[c[i]]++; //printf("d=%d",c[i]);
		}
        j=0;
        for(i=0;i<200;i++)
            if(a[i]!=0)
            {
                tree[n].weight=a[i];
                tree[n].l_child=-1;
                tree[n].r_child=-1;
                tree[n].parent=-1;
                n++;                               
            }
		//	printf("n=%d\n",n);
            m=2*n-1;
            for(i=n;i<m;i++)
            {
                tree[i].l_child=-1;
                tree[i].r_child=-1;
                tree[i].parent=-1;
                tree[i].weight=0;
            }
            for(i=0;i<n-1;i++)
            {
                m1=m2=1000000000;//��¼Ȩֵ
                x1=x2=0;//��¼ �ڵ�����λ��
                for(j=0;j<n+i;j++)
                {
                    if(tree[j].weight<m1&&tree[j].parent==-1)
                    {
                        m2=m1;
                        x2=x1;
                        m1=tree[j].weight;
                        x1=j;
                    }
                    else if(tree[j].weight<m2&&tree[j].parent==-1)
                    {
                        m2=tree[j].weight;
                        x2=j;
                    }
                }
                tree[n+i].weight=tree[x1].weight+tree[x2].weight;
                tree[x1].parent=n+i;
                tree[x2].parent=n+i;
                tree[n+i].l_child=x1;
                tree[n+i].r_child=x2;       
            }
            for(i=0;i<n;i++)
            {
                cd.start=n-1;
                child=i;
                pare=tree[child].parent;
                while(pare!=-1)
                {
                    if(tree[pare].l_child==child)
                        cd.l[cd.start]=0;
                    else cd.l[cd.start]=1;
                    cd.start--;
                    child=pare;
                    pare=tree[child].parent;
                }
                for(j=cd.start+1;j<n;j++)
                {
                    code[i].l[j]=cd.l[j];
                }
                code[i].start=cd.start+1; 
                code[i].weight=tree[i].weight;
                //   printf("code[i]=%d d=%d\n",code[i].start,n-code[i].start);
            }
            for(i=0;i<n;i++)
            {
                temp=i;cnt=0;
                while(tree[temp].parent!=-1)
                {
                    /*��nΪ1��ʱ��ֻ��һ���ڵ��޷������ ���Ը��׽ڵ�Ϊ-1
                �����cnt=0  ��ansҲ����0  ���������  10 10  dddddddddddddddddddddd�Ͳ�����
                Ҫ�����������������
                    */
                    temp=tree[temp].parent;
                    cnt++;
                }
                ans=ans+cnt*tree[i].weight;
			//	printf("ans=%d\n",ans);
            }
            if(n==1) ans=tree[0].weight;// Ҫ�ر�ע������ط� ��Ϊ��n����1��ʱ���һ������Ϊ0
              printf("%d\n",ans);
    }
    return 0;
}