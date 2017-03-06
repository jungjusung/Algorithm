#include <iostream>
#include <algorithm>
using namespace std;

int dp[5001][5001];
int arr[5001];
int N;
int main(void){
	cin>>N;
	for(int i=1;i<=N;i++)
		cin>>arr[i];

	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){

			if(arr[i]==arr[N-j+1]){
				dp[i][j]=dp[i-1][j-1]+1;
			}else{
				dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
			}

		}
	}
	cout<<N-dp[N][N]<<endl;
}