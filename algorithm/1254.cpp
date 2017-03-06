#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int dp[1001][1001];
int main(void){
	string str;
	cin>>str;
	int N=str.size();
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(i==j)
				dp[i][j]=1;
		}
	}
	for(int j=1;j<N;j++){
		for(int k=0;k<j;k++){
			if(j-k==1){
				if(str[k]==str[j])
					dp[k][j]=1;
			}else{
				if(str[k]==str[j])
					dp[k][j]=dp[k+1][j-1];
			}
		}
	}
	int result=0;
	for(int i=0;i<N;i++){
		if(dp[i][N-1]==1){
			result=i;
			break;
		}
	}
	cout<<N+result<<endl;
}