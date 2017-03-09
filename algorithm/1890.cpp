#include <iostream>
using namespace std;


int board[101][101];
long long dp[101][101];
int N;

long long go(int y,int x){
	
	if(y==N-1&&x==N-1)
		return 1;

	if(dp[y][x])
		return dp[y][x];
	
	if (!board[y][x])
		return dp[y][x] = 0;

	if(0<=y+board[y][x]&&y+board[y][x]<N){
		dp[y][x]+=go(y+board[y][x],x);
	}
	if(0<=x+board[y][x]&&x+board[y][x]<N){
		dp[y][x]+=go(y,x+board[y][x]);
	}

	return dp[y][x];

}
int main(void){

	cin>>N;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>board[i][j];
		}
	}
	dp[N-1][N-1]=1;
	cout<<go(0,0)<<endl;
}