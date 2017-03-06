#include <iostream>
#include <queue>
using namespace std;


int board[101][101];
int dis[101][101][5];

int dx[5]={0,0,0,1,-1};
int dy[5]={0,1,-1,0,0};
int N,M;

class point{
public:
    int x;
    int y;
    int dir;
};
point startPoint;
point endPoint;
int bfs(point startPoint, point endPoint){
    int cnt=-1;
    queue<point> q;
    q.push(startPoint);
    queue<int> qCnt;
    qCnt.push(0);
    dis[startPoint.x][startPoint.y][startPoint.dir]=1;
    point turnDir;
    point there;
    while(!q.empty()){
        point here=q.front();
        q.pop();
        cnt=qCnt.front();
        qCnt.pop();
        //cout<<here.x<<" "<<here.y<<" "<<here.dir<<" "<<cnt<<endl;
        if(here.x==endPoint.x&&here.y==endPoint.y&&here.dir==endPoint.dir){
            return cnt;
        }
        for(int i=1;i<=4;i++){
            if(here.dir!=i){
                turnDir.x=here.x;
                turnDir.y=here.y;
                turnDir.dir=i;

                if(dis[turnDir.x][turnDir.y][turnDir.dir]==1)
                    continue;
                q.push(turnDir);

                if(here.dir==1)
                {
                    if(i==3||i==4)
                        qCnt.push(cnt+1);
                    else
                        qCnt.push(cnt+2);
                }else if(here.dir==2){
                    if(i==3||i==4)
                        qCnt.push(cnt+1);
                    else
                        qCnt.push(cnt+2);
                }else if(here.dir==3){
                    if(i==1||i==2)
                        qCnt.push(cnt+1);
                    else
                        qCnt.push(cnt+2);
                }else{
                    if(i==1||i==2)
                        qCnt.push(cnt+1);
                    else
                        qCnt.push(cnt+2);
                }
                dis[turnDir.x][turnDir.y][turnDir.dir]=1;
            }

        }

        for(int i=1;i<=4;i++){
            for(int j=1;j<=3;j++)
            {
                int x=here.x+dx[i]*j;
                int y=here.y+dy[i]*j;
                int dir=here.dir;
                //범위 초과시 break;
                if(y<1||x<1||x>M||y>N)
                    continue;
                if(dis[x][y][dir]==1)
                    continue;
                if(board[x][y]==1)
                    break;
                there.x=x;
                there.y=y;
                there.dir=dir;
                if(there.dir==i){
                   // board[there.x][there.y]=1;
                    dis[there.x][there.y][there.dir]=1;
                    q.push(there);
                    qCnt.push(cnt+1);
                    }
                 }

        }

    }
    return -1;

}


int main(void){

    cin>>M>>N;
    for(int i=1;i<=M;i++){
        for(int j=1;j<=N;j++){
            cin>>board[i][j];
        }
    }
    cin>>startPoint.x>>startPoint.y>>startPoint.dir;
    cin>>endPoint.x>>endPoint.y>>endPoint.dir;

    cout<<bfs(startPoint,endPoint)<<endl;
}