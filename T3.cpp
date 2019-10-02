/*
	首尾分别取数，求和最大的一方 
**/ 
# include <bits/stdc++.h>
using namespace std;
# define MAXN 110
int N;
int data[MAXN];///瀛樻斁鍒濆鍊�
int sum[MAXN];///瀛樻斁鍓峣涓暟鐨勫拰
int gain[MAXN][MAXN];///浠庡尯闂碵i,j]鍙栨暟鐨勬渶澶у��
int main()
{
    while(cin>>N)
    {
        memset(sum,0,sizeof(sum));
        for(int i=1;i<=N;i++)
        {
            cin>>data[i];
            sum[i]=sum[i-1]+data[i];
            gain[i][i]=data[i];///鍒濆鍖�
        }
        for(int i=N-1;i>0;i--)///鍔ㄦ�佽鍒掞紝浠庡皬鍖洪棿鎵╁睍鍒板ぇ鍖洪棿
        {
            for(int j=i;j<=N;j++)
            {
                gain[i][j]=sum[j]-sum[i-1]-min(gain[i+1][j],gain[i][j-1]);
                ///sum[j]-sum[i-1]浠ｈ〃[i,j]鍖洪棿鎵�鏈夋暟鐨勫拰
                ///褰撳墠浜轰粠[i,j]鍖洪棿鍙栨暟锛岄偅涔堜笅涓�涓汉鍙兘浠嶽i+1,j]鎴栬��
                ///[i,j-1]鍖洪棿鍙栨暟
            }
        }
        cout<<gain[1][N]<<' '<<sum[N]-gain[1][N]<<endl;
    }
    return 0;
}
