#include <iostream>
using namespace std;

int N;
int dp[100001][3];

int main(void)
{
	cin>>N;
	dp[0][0]=1;
	//둘다 없을 경우
	dp[0][1]=1;
	//왼쪽만 있을 경우
	dp[0][2]=1;
	//오른쪽만 있을 경우
	for(int i=1;i<=N;i++)
	{
		dp[i][0]=(dp[i-1][0]+dp[i-1][1]+dp[i-1][2])%9901;
		//전에 사자가 없으면 다 넣을수 있다.
		dp[i][1]=(dp[i-1][0]+dp[i-1][2])%9901;
		//왼쪽에 사자가 있었을시 한마리도 없거나 오른쪽에 한마리가 존재
		dp[i][2]=(dp[i-1][0]+dp[i-1][1])%9901;
		//오른쪽에 사자가 있었을시 한마리도 없거나 왼쪽에 한마리가 존재
	}
	/*for(int i=0;i<N;i++)
	{
		for(int j=0;j<3;j++)
			cout<<dp[i][j]<<" ";

		cout<<endl;
	}*/
	cout<<(dp[N-1][0]+dp[N-1][1]+dp[N-1][2])%9901<<endl;
}