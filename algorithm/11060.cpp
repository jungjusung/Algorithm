#include <iostream>
#include <algorithm>
#define MAX 9999999
using namespace std;


int N;
int dp[1001];
int A[1001];
int main(void){

	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>A[i];
		dp[i]=MAX;
	}

	dp[1]=0;
	for(int i=2;i<=N;i++){
		for(int j=1;j<i;j++){
			if(A[i-j]>=j){
				dp[i]=min(dp[i-j]+1,dp[i]);
			}
		}
	}
	if(dp[N]==MAX)
		cout<<-1<<endl;
	else
		cout<<dp[N]<<endl;
}