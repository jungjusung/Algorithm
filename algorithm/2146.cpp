#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int board[101][101];
int N;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
int visited[101][101];
class point{
	public:
	int y;
	int x;
	int cnt;
	point(){};
	point(int y,int x,int cnt){
		this->y=y;
		this->x=x;
		this->cnt=cnt;
	};
};
int cnt=1;
int result=99999;
void dfs(int y,int x){

	if(board[y][x]==0)
		return;

	visited[y][x]=cnt;
	for(int i=0;i<4;i++){
		int nextX=x+dx[i];
		int nextY=y+dy[i];
		if(nextX<0||nextY<0||nextX>=N||nextY>=N)
			continue;
		if(visited[nextY][nextX]>0)
			continue;

		dfs(nextY,nextX);
	}

}
void bfs(int y,int x,int loc){
	int count=0;
	int visit[101][101]={};
	queue<point> q;
	queue<int> qCnt;
	point start(y,x,loc);
	q.push(start);
	qCnt.push(count);
	visit[y][x]=1;
	// /int num=0;
	while(!q.empty()){
		
		point here=q.front();
		q.pop();
		count=qCnt.front();
		qCnt.pop();

		if(count>result)
			continue;
		if(visited[here.y][here.x]>loc)
		{
			result=min(count,result);
		}
		for(int i=0;i<4;i++){
			int newX=here.x+dx[i];
			int newY=here.y+dy[i];

			if(newX<0||newY<0||newX>=N||newY>=N)
				continue;
			if(visit[newY][newX]==1)
				continue;
			if(visited[newY][newX]==loc)
				continue;

			point there(newY,newX,loc);
			q.push(there);
			qCnt.push(count+1);
			visit[newY][newX]=1;

		}
	}

}
int main(void){
	cin>>N;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++)
			cin>>board[i][j];
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(board[i][j]==1&&visited[i][j]==0){
				dfs(i,j);
				cnt++;
			}
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++)
		{
			for(int k=0;k<4;k++){
				if(visited[i][j]>0)
				{
					if(i+dy[k]<0||i+dy[k]>=N||j+dx[k]<0||j+dx[k]>=N)
						continue;
					if(visited[i+dy[k]][j+dx[k]]==0){
						bfs(i,j,visited[i][j]);
					}
				}

			}
		}
	}
	cout<<result-1<<endl;

}