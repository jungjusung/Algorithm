#include <iostream>
#include <algorithm>
using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int M, N, board[501][501], dp[501][501];

int go(int x, int y){
    if (x<0 || y<0 || x>=M || y>=N) 
        return 0;
    if (dp[x][y]) 
        return dp[x][y];
    for (int i = 0; i < 4; i++)
        if (board[x][y]>board[x + dx[i]][y + dy[i]])
            dp[x][y] += go(x + dx[i], y + dy[i]);
    return dp[x][y];
}
int main(void){
    

    cin>>M>>N;

    for (int i=0; i<M;i++)
        for (int j =0; j<N;j++)
                cin>>board[i][j];

    dp[M - 1][N - 1] = 1;
    cout<<go(0,0)<<endl;
    
}