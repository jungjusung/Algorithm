#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 987654321
using namespace std;

int sum[501];
int dp[501][501];
int T,N;
int main(void){

	cin>>T;
	for(int t=0;t<T;t++){
		cin>>N;
		memset(sum,0,sizeof(sum));
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=N;i++){
			int k;
			cin>>k;
			sum[i]=sum[i-1]+k;
		}
	
		for (int i = 2; i <= N; i++) {
            for (int j = i; --j;) {
                dp[j][i] = MAX;
                for (int k = j; k <= i; k++)
                    if (dp[j][i] > dp[j][k] + dp[k + 1][i]) dp[j][i] = dp[j][k] + dp[k + 1][i];
                dp[j][i] += sum[i] - sum[j - 1];
            }
        }
		cout<<dp[1][N]<<endl;
	}
}