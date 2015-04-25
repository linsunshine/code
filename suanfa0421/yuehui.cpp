#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;
struct MM{
       char name[16];
       char s[6];
       char f[6];
};
MM mm[1000];
int x[1000];
void swap(int i, int j)
{
   char tmp[16];
   strcpy(tmp, mm[i].name); 
   strcpy(mm[i].name, mm[j].name);
   strcpy(mm[j].name, tmp);
   strcpy(tmp, mm[i].s);
   strcpy(mm[i].s, mm[j].s);
   strcpy(mm[j].s, tmp);
   strcpy(tmp, mm[i].f);
   strcpy(mm[i].f, mm[j].f);
   strcpy(mm[j].f, tmp);
}
int partion(int p, int q)
{
     int t=rand()%(q-p+1)+p;
     swap(t,p);
     int i=p;
     int j=q+1;
     while(true)
     {
       while(strcmp(mm[++i].f,mm[p].f)<0);
       while(strcmp(mm[--j].f,mm[p].f)>0);
       if(i>=j)break;
       swap(i,j);
     }
     swap(p,j);
     return j;
}
void quicksort(int p, int q)
{
     if(p<q)
     {
       int r=partion(p,q);
       quicksort(p,r-1);
       quicksort(r+1,q);
     }
}
void GreedySelect(int n)
{
    int i,j,count;
    quicksort(0,n-1);
    j=0;
    count=1;
    x[0]=1;
    for(i=1;i<n;i++)
    {
      if(strcmp(mm[i].s, mm[j].f)>=0)
      {
        x[i]=1;
        count++;
        j=i;
      }
      else
      {
        x[i]=0;
      }
    }
    printf("%d\n",count);
    for(i=0;i<n;i++)
    {
      if(x[i])
        printf("%s ",mm[i].name);
    }
    printf("\n");
}
int main()
{
    int i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%s%s%s", mm[i].name, mm[i].s, mm[i].f);
    GreedySelect(n);
    return 0;
}
