#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 987654321
using namespace std;

int N,M;
int board[1001][1001];
int visited[1001][1001][2];
class point{
public:
    int x;
    int y;
    int block;
    int cnt;
    point(){}
    point(int y,int x,int block,int cnt){
        this->x=x;
        this->y=y;
        this->block=block;
        this->cnt=cnt;
    }
};

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int bfs(int y,int x){

    int cnt=1;
    int block=0;
    queue<point> q;
    point p(y,x,block,cnt);
    q.push(p);
    visited[y][x][0]=cnt;
    int minCnt=MAX;
    int flag=0;
    while(!q.empty()){
        point here=q.front();
        cnt=here.cnt;
        block=here.block;
        q.pop();
        if(block==2)
            continue;
       //cout<<here.y<<" "<<here.x<<" "<<cnt<<" "<<block<<endl;
        if(here.y==N&&here.x==M){
            flag=1;
            minCnt=min(minCnt,here.cnt);
        }

        for(int i=0;i<4;i++){
            int x=here.x+dx[i];
            int y=here.y+dy[i];

            if(x<1||y<1||x>M||y>N)
                continue;

            //벽일때
            if(board[y][x]==1){
                if(visited[y][x][block]==0){
                    point there(y,x,block+1,cnt+1);
                    q.push(there);
                    visited[y][x][block]=1;
                }else{
                    continue;
                }
            }else if(board[y][x]==0){
            //벽이 아님
                if(visited[y][x][block]==0){
                    point there(y,x,block,cnt+1);
                    q.push(there);
                    visited[y][x][block]=1;
                }
                if(visited[y][x][block]==0){
                    point there(y,x,block,cnt+1);
                    q.push(there);
                    visited[y][x][block]=1;
                }

            }

        }
    }
    if(flag==0)
        return -1;

    return minCnt;
}
int main(void){
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        string str;
        cin>>str;
        for(int j=0;j<str.size();j++){
            if(str[j]=='0')
                board[i][j+1]=0;
            else
                board[i][j+1]=1;
        }
    }
    cout<<bfs(1,1)<<endl;
}