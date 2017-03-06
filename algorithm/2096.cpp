#include <iostream>
#include <algorithm>

using namespace std;

int N;
int dp[100001][3];

int a[100001][3];
int main(void){

	cin>>N;

	for(int i=0;i<N;i++){
		for(int j=0;j<3;j++){
			cin>>a[i][j];
		}
	}
	dp[0][0]=a[0][0];
	dp[0][1]=a[0][1];
	dp[0][2]=a[0][2];

	for(int i=1;i<=N;i++){
		dp[i][0]=max(dp[i-1][0]+a[i][0],dp[i-1][1]+a[i][0]);
		dp[i][1]=max(dp[i-1][0]+a[i][1],dp[i-1][1]+a[i][1]);
		dp[i][1]=max(dp[i][1],dp[i-1][2]+a[i][1]);
		dp[i][2]=max(dp[i-1][1]+a[i][2],dp[i-1][2]+a[i][2]);
	}
	int maxSum=dp[N][0];
	for(int i=0;i<3;i++){
		maxSum=max(maxSum,dp[N][i]);
	}
	for(int i=1;i<=N;i++){
		dp[i][0]=min(dp[i-1][0]+a[i][0],dp[i-1][1]+a[i][0]);
		dp[i][1]=min(dp[i-1][0]+a[i][1],dp[i-1][1]+a[i][1]);
		dp[i][1]=min(dp[i][1],dp[i-1][2]+a[i][1]);
		dp[i][2]=min(dp[i-1][1]+a[i][2],dp[i-1][2]+a[i][2]);
	}
	int minSum=dp[N][0];
	for(int i=0;i<3;i++){
		minSum=min(minSum,dp[N][i]);
	}	
	cout<<maxSum<<" "<<minSum<<endl;
}