#include <iostream>
using namespace std;

int dp[101][2][21];
char board[101][2];
int main(void){

	string key;
	string str1;
	string str2;
	cin>>key>>str1>>str2;
	int n=str1.size();
	for(int i=1;i<=n;i++){
		board[i][0]=str1[i-1];
		board[i][1]=str2[i-1];
	}
	for(int i=1;i<=n;i++){
		if(board[i][0]==key[0])
			dp[i][0][0]=1;
		if(board[i][1]==key[0])
			dp[i][1][0]=1;
	}	
	for(int i=1;i<=n;i++){
		for(int k=0;k<key.size();k++){
			for(int j=1;j<i;j++){
				if(k-1>=0){
					if(board[i][0]==key[k])
						dp[i][0][k]+=dp[j][1][k-1];
					if(board[i][1]==key[k])
						dp[i][1][k]+=dp[j][0][k-1];
				}
			}			
		}
	}
	int result=0;
	for(int i=1;i<=n;i++){
		result+=dp[i][1][key.size()-1];
		result+=dp[i][0][key.size()-1];
	}
	cout<<result<<endl;
}
