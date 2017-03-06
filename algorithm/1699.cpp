#include <iostream>
#include <algorithm>
using namespace std;

long long N;
long long dp[100001];

int main(void){

	cin>>N;
	dp[1]=1;

	for(long i=2;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(i>j*j){
				if(j==1)
					dp[i]=dp[j*j]+dp[i-j*j];
				else
					dp[i]=min(dp[i],dp[j*j]+dp[i-j*j]);

			}else if(i==j*j){
				dp[i]=1;
				break;
			}else
				break;
		}
	}
/*	for(int i=1;i<=N;i++){
		cout<<dp[i]<<" ";
	}
	cout<<endl;*/
	cout<<dp[N]<<endl;
}