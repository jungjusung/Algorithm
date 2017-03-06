#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int N,M;
class point{
public:
    int x;
    int y;
    point(){};
    point(int y,int x){
        this->x=x;
        this->y=y;
    };
};
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int board[101][101];
int visit[101][101];

int bfs(int y,int x){

    queue<point> q;
    queue<int> qCnt;
    int cnt=1;
    point start(y,x);
    q.push(start);
    visit[y][x]=1;
    qCnt.push(cnt);
    int num=0;
    while(!q.empty()){

        point here=q.front();
        q.pop();
        cnt=qCnt.front();
        qCnt.pop();

        if(here.y==N&&here.x==M){
            return cnt;
        }

        for(int i=0;i<4;i++){
            int x=here.x+dx[i];
            int y=here.y+dy[i];

            if(x<1||y<1||x>M||y>N)
                continue;
            if(visit[y][x]==1)
                continue;
            if(board[y][x]==0)
                continue;
            point next(y,x);
            q.push(next);
            qCnt.push(cnt+1);
            visit[y][x]=1;
        }

    }
    return -1;

}
int main(void){

    cin>>N>>M;
    string str;
    for(int i=1;i<=N;i++){
        cin>>str;
        for(int j=0;j<M;j++){
            if(str[j]=='1')
                board[i][j+1]=1;
            else
                board[i][j+1]=0;
        }
    }
    cout<<bfs(1,1)<<endl;

}