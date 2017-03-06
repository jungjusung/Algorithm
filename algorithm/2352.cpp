#include <iostream>
#include <algorithm>
using namespace std;

int N;
int dp[40001];
int A[40001];
int main(void){

	cin>>N;
	int size=1;
	for(int i=1;i<=N;i++){
		cin>>A[i];
	}
	dp[1]=A[1];
	for(int i=2;i<=N;i++){

		if(dp[size]<A[i]){
			size++;
			dp[size]=A[i];
		}else{
			int it=lower_bound(dp+1,dp+size+1,A[i])-dp;
			dp[it]=A[i];
		}
	}
	int result=0;
	for(int i=1;i<=N;i++){
		if(dp[i]==0){
			result=i-1;
			break;
		}
	}
	cout<<result<<endl;
}