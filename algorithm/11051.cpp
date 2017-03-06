#include <iostream>
#define MOD 10007
using namespace std;

int N,K;
int dp[1001][1001];
int main(void){

	cin>>N>>K;

	for(int i=0;i<=N;i++){
		dp[i][i]=1;
	}
	for(int i=0;i<=N;i++)
		dp[i][0]=1;
	
	for(int i=2;i<=N;i++){
		for(int j=1;j<=N;j++){
			dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%MOD;
		}
	}
	cout<<dp[N][K]<<endl;
}