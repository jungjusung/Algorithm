#include <iostream>
#include <cstring>
#include <queue>
using namespace std;


class Point{
public:
	int x;
	int y;
	Point(int x,int y){
		this->x=x;
		this->y=y;
	}

};
int T,L;
bool visited[301][301];
int dx[8]={-2,-1,-2,-1,1,2,1,2};
int dy[8]={-1,-2, 1, 2,-2,-1,2,1};

int bfs(Point start,Point des){
	queue<Point> q;
	queue<int> qCnt;
	int cnt=0;
	q.push(start);
	qCnt.push(cnt);
	visited[start.y][start.x]=true;
	while(!q.empty()){

		Point here=q.front();
		q.pop();
		cnt=qCnt.front();
		qCnt.pop();
		if(here.x==des.x&&here.y==des.y){
			return cnt;
		}
		for(int i=0;i<8;i++){
			int x=here.x+dx[i];
			int y=here.y+dy[i];
			Point there(x,y);

			if(x<0||x>=L||y<0||y>=L)
				continue;
			if(visited[y][x])
				continue;

			q.push(there);
			qCnt.push(cnt+1);
			visited[y][x]=true;

		}
	}

	return -1;
}

int main(void){

	cin>>T;
	for(int i=0;i<T;i++){
		cin>>L;
		int x,y,_x,_y;
		cin>>x>>y>>_x>>_y;

		Point start(x,y);
		Point des(_x,_y);
		memset(visited,false,sizeof(visited));
		int result=bfs(start,des);
		cout<<result<<endl;
	}


}