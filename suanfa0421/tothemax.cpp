//�������������m*n�ľ���ĳһ������ֵ
//���������㷨û�д��󣡵��ǳ�ʱ����˻�Ҫ��һ���Ż��㷨��
//����������˵�ıȽ�ģ������Ŀ��û��˵Ҫ����������ݣ�Ū����ֻ������һ�Σ��������Ǵ������Ҳ����������ڣ�
/*
#include<iostream>
#include<cstdio>
using namespace std;
const int MAX=10010;
int arr[MAX];

int main()
{
	int s,max=-200;
	int we=0;
	int m,n;
	while(scanf("%d",&arr[0])!=EOF)
	{
	//cin>>arr[0];//���뷽���ά��
	m=n=arr[0];
	for(int i=1;i<=arr[0]*arr[0];i++)
		cin>>arr[i];

	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)//�����Ǳ�ʾ�����Ĵ�С��i*j
			for(int p=1;m-p>=i-1 ;p++)
				for(int q=1;n-q>=j-1 ;q++)//����·�ߣ����϶��£���������
				{
					int cur=p+m*(q-1);
					int count=0;
					int temp=cur; 
					int temp1=1;
					s=0;
					//cout<<"��"<<we<<"�������� "<<endl;
					//cout<<"����� ����"<<p<<","<<"����"<<q<<endl;
					//cout<<"p="<<p<<",n="<<n<<endl;
					for(int k=1;k<=i*j;k++)
					{
						//cout<<arr[temp]<<"  ";
						s=s+arr[temp];
						count++;
						temp++;
						if(count>=i)
						{
							temp=cur+temp1*m;
							temp1++;
							count=0;
						}
					}
					//cout<<endl;
					//we++;
					if(s>max)
					max=s;
				}
     cout<<max<<endl;
	 //system("pause");
	 }
	return 0;
}
*/

//��һ�ֶ�̬�滮
#include<iostream>
#include<cstdio>
#include<string.h>

using namespace std;

int arr[101][101];
int sum[101],dp[101];

int main()
{
	
	int i,j,k,p,n;
	while(scanf("%d",&n)!=EOF)
	{  
		int max=-200;
		memset(sum,0,sizeof(sum));
		memset(dp,0,sizeof(dp));
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			   cin>>arr[i][j];	
		for(i=0;i<n;i++)
		{
			memset(sum,0,sizeof(sum));
			for(k=i;k<n;k++)
			{
				for(j=0;j<n;j++)
				    sum[j]=arr[k][j]+sum[j];
				dp[0]=sum[0];
				for(p=1;p<n;p++)
				{
					if (dp[p-1]>0) dp[p]=dp[p-1]+sum[p];
                    else dp[p]=sum[p];
                    if (dp[p]>max) max=dp[p];
						/*
						if(dp[p-1]+sum[p]>sum[p])
							dp[p]=dp[p-1]+sum[p];
						else
							dp[p]=dp[p-1];
						if(dp[p]>max) max=dp[p];
						*/
				}
					
			}
		}
		cout<<max<<endl;
		//system("pause");
	}
	return 0;
}

//�����뵽�����Ȼ��һ����̬�滮��
		//1��������ֶκ�
	/*
	��Ŀ����ת��Ϊ���������⣺
	1������n������������Ϊ��������ɵ�����a[1],a[2],a[3],��,a[n],���������a+a+��+a[j]���Ӷκ͵����ֵ��������������Ϊ����ʱ�����Ӷκ�Ϊ0�����˶��壬���������ֵΪMax{0,a+a+��+a[j]},1<=i<=j<=n
	���ǰ�b[j]���Ϊ��ǰ��ĳ�ʼ����a[j]��a[j]Ϊ���һ��Ԫ�أ��������Ķεĺ����ֵ����֪����ʼ��a[i]�ض�Ϊ������
��b[j]=max(a+..+a[j-1]+a[j]),����1<=i<=j,����1<=j<=n,��Ҫ��ȷ��һ����b[j]��ֵ�������a[j]�������������Ӷκ�Ϊmax{b[j]}��1<=j<=n��
	��b[j]�Ķ������֪����b[j-1]>0ʱ(��ǰ��Ķμ���a[j]��һ��ֵ�������Ȼ��a[j]��һ�ν���)b[j]=b[j-1]+a[j]����������ǰ��Ķ�Ϊ��ֵ������a[j],��ʹֵ��С�������Ļ������ǽ�ǰ��Ķ�ȥ����a[j]�������ֵ��b[j]=a[j]����b[j]�Ķ�̬�滮�ݹ�ʽΪ b[j]=max(b[j-1]+a[j],a[j])��1<=j<=n��
	2������Ӿ����

	�����Ƕ�ά�ģ�����ѹ����һά�Ϳ���������ķ����������Ӿ������
    ����һ��������ӣ�ѹ����һά�ļ��ɣ����Ǳ������е�ѹ�����ܣ��Ϳ���ͨ������ķ�����������ֵ��
	*/ 



//�ڶ��ֶ�̬�滮
#include <stdio.h>
#define MAXSIZE 101


//���һ���������Ӷκ�
int MaxArray( int n, int arr_[])
{
    int i, sum_ = 0, max_ = 0;
    for (i=1; i<=n; i++)
    {
        if (sum_>0)
        {
            sum_ += arr_[i];
        }
        else
        {
            sum_ = arr_[i];
        }
        if (sum_>max_)
        {
            max_ = sum_;
        }
    }
    return max_;
}

int MaxMatrix( int n, int arr_[][MAXSIZE])
{
    int max_ = arr_[1][1];
    int sum_;
    int i, j, k;
    int temp_arr[MAXSIZE]; 
    for (i=1; i<=n; i++) //�ӵ�һ�п�ʼ��ֱ����n��
    {
        for (j=1; j<=n; j++) //ֻ����ʼ�иı䣬temp_arr����ų�ʼ��
        {
            temp_arr[j] = 0;
        }
        
        for (j=i; j<=n; j++) //��i�е���n��
        {
            for (k=1; k<=n; k++)  
            {
                temp_arr[k] += arr_[j][k]; //temp_arr[k] ��ʾ�ӵ�i�е���n���е�k�е��ܺ͡�
            }
            
            sum_ = MaxArray(n, temp_arr); //��������������Ӷκ�
            
            if (sum_ > max_)
            {
                max_ = sum_;
            }
		}
    }
    
    return max_;
}

int main()
{
    int n;
    int i, j;
    int arr_[MAXSIZE][MAXSIZE];
    int max_;
    while (~scanf("%d", &n)) //������ԡ� �൱�� scanf("%d", &n) != EOF
    {
        for (i=1; i<=n; i++)
        {
            for (j=1; j<=n; j++)
            {
                scanf("%d", &arr_[i][j]);
            }
        }
        max_ = MaxMatrix(n, arr_);
        printf("%d\n", max_);
    }
    
    return 0;
}


//�����ֶ�̬�滮��ͨ����
#include <stdio.h>
#define INT_MIN -1000
int a[101][101];
int b[101];
int n;
int maxSum1()
{
    int i,sum,max=INT_MIN;
    sum=0;
    for(i=1;i<=n;i++)
    {
      if(sum>0)
        sum+=b[i];
      else
        sum=b[i];
      
      if(sum>max)
        max=sum;
    }
    return max;
}

void maxSum2()
{
    int i,j,k,sum,max=INT_MIN;
    for(i=1;i<=n;i++)
    {
      for(k=1;k<=n;k++)
        b[k]=0;
      for(j=i;j<=n;j++)
      {
        for(k=1;k<=n;k++)
          b[k]+=a[j][k];
        sum=maxSum1();
        if(sum>max)
          max=sum;
      }
    }
    printf("%d\n",max);
}

int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
      scanf("%d",&a[i][j]);
    
    maxSum2();
    
    return 0;
}
