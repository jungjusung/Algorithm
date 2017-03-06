#include <iostream>
#include <cstring>
using namespace std;


long dp[31][31];
int T;
int N,M;	
int main(void){
	
	cin>>T;
	for(int t=0;t<T;t++){
		cin>>N>>M;
		memset(dp,0,sizeof(dp));
		long result=0;

		for(int j=1;j<=M;j++)
			dp[1][j]=1;

		 for(int i=1;i<=N;i++){
		 	for(int j=1;j<=M;j++){
		 		for(int k=1;k<j;k++){
		 			dp[i][j]+=dp[i-1][k];
		 		}
		 	}
		 }
		for(int i=1;i<=M;i++)
			result+=dp[N][i];
		cout<<result<<endl;
	}
}