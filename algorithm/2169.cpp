#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int board[1001][1001];
int dp[1001][1001];
int N,M;
int temp[1001];
int temp2[1001];
int main(void){

	cin>>N>>M;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin>>board[i][j];
		}
	}
	dp[0][0]=board[0][0];
	for(int i=1;i<M;i++){
		dp[0][i]=dp[0][i-1]+board[0][i];
	}
	for(int i=1;i<N;i++){
		memset(temp,0,sizeof(temp));
		memset(temp2,0,sizeof(temp2));
		for(int j=M-1;j>=0;j--){
			temp[j]=dp[i-1][j]+board[i][j];
			if(j+1<M)
				temp[j]=max(dp[i-1][j],temp[j+1])+board[i][j];
		}
		for(int j=0;j<M;j++){
			temp2[j]=dp[i-1][j]+board[i][j];
			if(j-1>=0)
				temp2[j]=max(dp[i-1][j],temp2[j-1])+board[i][j];
		}
		for(int j=0;j<M;j++){
			dp[i][j]=max(temp[j],temp2[j]);
		}

	}
	cout<<dp[N-1][M-1]<<endl;
}