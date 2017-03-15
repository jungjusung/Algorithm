#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;


int N,M,K;
int board[101][101];
int visited[101][101];

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int cnt=1;
vector<int> ans;
void bfs(int y,int x){
	queue<int> xq;
	queue<int> yq;
	xq.push(x);
	yq.push(y);
	visited[y][x]=cnt;
	while(!xq.empty()){
		int x=xq.front();
		int y=yq.front();
		xq.pop();
		yq.pop();

	
		for(int i=0;i<4;i++){
			int _x=x+dx[i];
			int _y=y+dy[i];

			//cout<<_y<<" "<<_x<<endl;
			
			if(_x<0||_y<0||M<=_x||N<=_y||visited[_y][_x]>0)
				continue;
			if(board[_y][_x]==1)
			   	continue;
			xq.push(_x);
			yq.push(_y);
			visited[_y][_x]=cnt;
		}
	}
}
int main(void){
	cin>>N>>M>>K;
	memset(visited,0,sizeof(visited));
	for(int i=0;i<K;i++){
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		for(int y=y1;y<y2;y++){
			for(int x=x1;x<x2;x++){
				board[y][x]=1;
			}
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(board[i][j]==0&&visited[i][j]==0){
				bfs(i,j);
				cnt++;
			}	
		}
	}
	for(int t=1;t<=cnt-1;t++){
		int result=0;
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				if(visited[i][j]==t)
					result++;
			}
			
		}
		ans.push_back(result);
	}
	cout<<ans.size()<<endl;
	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";
}