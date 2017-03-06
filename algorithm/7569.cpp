#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
int M,N,H;
int board[101][101][101];
int visited[101][101][101];
class Point{
public:
    int x;
    int y;
    int z;
    Point(int _x,int _y,int _z){
        x=_x;
        y=_y;
        z=_z;
    }
};
int dx[6]={1,-1,0,0,0,0};
int dy[6]={0,0,1,-1,0,0};
int dz[6]={0,0,0,0,1,-1};
vector<Point> start;
bool tomatoChk(){
    for(int i=0;i<H;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<M;k++){
                if(board[j][k][i]==0){
                    return false;
                }
            }
        }
    }
    return true;
}
int count=0;
int bfs(){
    int cnt=0;
    //큐에 넣은 갯수
    queue<Point> q;
    queue<int> qCnt;
    for(int i=0;i<start.size();i++){
        q.push(start[i]);
        qCnt.push(cnt);
        visited[start[i].y][start[i].x][start[i].z]=1;
    }
    while(!q.empty()){

            Point here=q.front();

            q.pop();
            count=cnt=qCnt.front();
            qCnt.pop();

            for(int i=0;i<6;i++){
                int x=here.x+dx[i];
                int y=here.y+dy[i];
                int z=here.z+dz[i];

                if(x<0||y<0||z<0||x>=M||y>=N||z>=H)
                    continue;

                if(visited[y][x][z]==1||board[y][x][z]==-1)
                    continue;

                Point there(x,y,z);
                q.push(there);
                qCnt.push(cnt+1);
                board[y][x][z]=1;
                visited[y][x][z]=1;

        }
    }


    if(tomatoChk())
        return count;

    return -1;
}


int main(void){
    cin>>M>>N>>H;

    for(int i=0;i<H;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<M;k++){
                cin>>board[j][k][i];
                if(board[j][k][i]==1){
                    Point p(k,j,i);
                    start.push_back(p);
                }
            }
        }
    }
    cout<<bfs()<<endl;



}