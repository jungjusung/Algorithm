#include <iostream>
using namespace std;

int N,S,M;

int V[101];
int dp[101][1001];
int main(void){

	int result=-1;
	cin>>N>>S>>M;
	for(int i=1;i<=N;i++){
		cin>>V[i];
	}
	dp[0][S]=1;
	for(int i=1;i<=N;i++){
		for(int j=0;j<=M;j++){
			if(j-V[i]>=0&&dp[i][j]==0)
				dp[i][j]=dp[i-1][j-V[i]];
			if(j+V[i]<=M&&dp[i][j]==0)
				dp[i][j]=dp[i-1][j+V[i]];
		}
	}
	for(int i=0;i<=M;i++){
		if(dp[N][i]!=0)
			result=i;
	}
	cout<<result<<endl;
}