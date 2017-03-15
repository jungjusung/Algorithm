#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int board[101][101];
int board2[101][101];
int visited[101][101];

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,-0};
int N,H;
int cnt=1;
int ans=0;
void bfs(int y,int x){
	queue<int> qx;
	queue<int> qy;
	qx.push(x);
	qy.push(y);
	visited[y][x]=cnt;
	while(!qx.empty()){
		int x=qx.front();
		qx.pop();
		int y=qy.front();
		qy.pop();
		for(int i=0;i<4;i++){
			int _x=x+dx[i];
			int _y=y+dy[i];

			if(_x<0||_y<0||_x>=N||_y>=N||visited[_y][_x]>0)
				continue;
			
			if(board2[_y][_x]==1)
				continue;

			qx.push(_x);
			qy.push(_y);
			visited[_y][_x]=cnt;
		}
	}
}
int main(void){

	cin>>N;

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>board[i][j];
			H=max(board[i][j],H);
		}
	}
	for(int t=0;t<=H;t++){
		memset(board2,0,sizeof(board2));
		memset(visited,0,sizeof(visited));
		cnt=1;
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(board[i][j]<=t)
					board2[i][j]=1;
			}
		}
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(board2[i][j]==0&&visited[i][j]==0){
					bfs(i,j);
					cnt++;
				}
			}
		}

		ans=max(ans,cnt-1);
	}
	cout<<ans<<endl;

}