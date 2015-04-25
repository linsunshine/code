/*#include <stdio.h>

void greedy(int n)
{
	int t;
	printf("%d\n",&t);
}

int main()
{
	int m,n,i,a[10];
	float sum,change;
	scanf("%d",&n);
	sum=n*2.5;
	for (i=0;i<5;i++)
		scanf("%d",a[i]);
	greedy(n);
	return 0;
}
*/

#include <iostream>  
using namespace std;  
int main()  
{  
 int n;  
 cin>>n;  
 int money[6];  
 for(int i=0;i<6;i++)  
  cin>>money[i];  
 int left=1000-25*n;  
 int count=0;  
 while(left>=500&&money[0]>0)  
 {  
  left-=500;  
  count++;  
  money[0]--;  
 }  
 while(left>=100&&money[1]>0)  
 {  
  left-=100;  
  count++;  
  money[1]--;  
 }  
 while(left>=50&&money[2]>0)  
 {  
  left-=50;  
  count++;  
  money[2]--;  
 }  
 while(left>=10&&money[3]>0)  
 {  
  left-=10;  
  count++;  
  money[3]--;  
 }  
 while(left>=5&&money[4]>0)  
 {  
  left-=5;  
  count++;  
  money[4]--;  
 }  
 while(left>=1&&money[5]>0)  
 {  
  left-=1;  
  count++;  
  money[5]--;  
 }  
 if(left!=0)  
  cout<<-1<<endl;  
 else 
  cout<<count<<endl;  
 return 0;  
} 

	





