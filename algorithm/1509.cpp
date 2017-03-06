#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int dp[2501][2501];
int dp2[2501];
int main(void){
	string str;
	cin>>str;
	str=" "+str;
	int N=str.size();
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(i==j)
				dp[i][j]=1;
		}
	}
	for(int j=2;j<=N;j++){
		for(int k=1;k<j;k++){
			if(j-k==1){
				if(str[k]==str[j])
					dp[k][j]=1;
			}else{
				if(str[k]==str[j])
					dp[k][j]=dp[k+1][j-1];
			}
		}
	}
	dp2[0]=0;
	for(int i=1;i<=N;i++){
		dp2[i]=-1;
		for(int j=1;j<=i;j++){
			if(dp[j][i]==1){
				if(dp2[i]==-1||dp2[i]>dp2[j-1]+1)
					dp2[i]=dp2[j-1]+1;
			}
		}
	}

	cout<<dp2[N-1]<<endl;

}