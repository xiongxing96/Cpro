/*
	��β�ֱ�ȡ�����������һ�� 
**/ 
# include <bits/stdc++.h>
using namespace std;
# define MAXN 110
int N;
int data[MAXN];///存放初始值
int sum[MAXN];///存放前i个数的和
int gain[MAXN][MAXN];///从区间[i,j]取数的最大值
int main()
{
    while(cin>>N)
    {
        memset(sum,0,sizeof(sum));
        for(int i=1;i<=N;i++)
        {
            cin>>data[i];
            sum[i]=sum[i-1]+data[i];
            gain[i][i]=data[i];///初始化
        }
        for(int i=N-1;i>0;i--)///动态规划，从小区间扩展到大区间
        {
            for(int j=i;j<=N;j++)
            {
                gain[i][j]=sum[j]-sum[i-1]-min(gain[i+1][j],gain[i][j-1]);
                ///sum[j]-sum[i-1]代表[i,j]区间所有数的和
                ///当前人从[i,j]区间取数，那么下一个人只能从[i+1,j]或者
                ///[i,j-1]区间取数
            }
        }
        cout<<gain[1][N]<<' '<<sum[N]-gain[1][N]<<endl;
    }
    return 0;
}
