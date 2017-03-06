#include <iostream>
#include <algorithm>
using namespace std;

int dp[4001][4001];
string str1;
string str2;

int main(void){

	cin>>str1;
	cin>>str2;

	int n=str1.size();
	int m=str2.size();
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(str1[i]==str2[j])
			{
				if(i==0||j==0)
					dp[i][j]=1;
				else{

					dp[i][j]=dp[i-1][j-1]+1;
				}
			}
		}
	}

	int result=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			result=max(dp[i][j],result);
		}
	}
	cout<<result<<endl;
}