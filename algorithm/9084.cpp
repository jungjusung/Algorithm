#include <iostream>
#include <cstring>
using namespace std;

int T,N,M;
int coin[21];
long long dp[10001];
int main(void){

	cin>>T;
	for(int i=0;i<T;i++){
		memset(dp,0,sizeof(dp));
		cin>>N;
		for(int j=0;j<N;j++){
			cin>>coin[j];
		}

		cin>>M;
		dp[0]=1;
		for(int k=0;k<N;k++){
			for(int j=1;j<=M;j++){
				if(j-coin[k]>=0){
					dp[j]+=dp[j-coin[k]];
				}
			}
		}
		cout<<dp[M]<<endl;
	}
}