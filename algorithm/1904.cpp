#include <iostream>
#define MOD 15746
using namespace std;

int N;
int dp[1000001][2];
int main(void){

	cin>>N;
	dp[1][1]=1;
	dp[1][0]=0;
	dp[2][0]=1;
	dp[2][1]=1;

	for(int i=3;i<=N;i++){

		dp[i][0]=dp[i-2][1]%MOD+dp[i-2][0]%MOD;
		dp[i][1]=dp[i-1][1]%MOD+dp[i-1][0]%MOD;
	}

	cout<<(dp[N][0]+dp[N][1])%MOD<<endl;


}