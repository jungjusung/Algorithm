#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
int M,N;
int board[1001][1001];
int visited[1001][1001];
class Point{
public:
    int x;
    int y;
    Point(int _x,int _y){
        x=_x;
        y=_y;
    }
};
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
vector<Point> start;
int countTime=0;
bool tomatoChk(){

    for(int j=0;j<N;j++){
        for(int k=0;k<M;k++){
            if(board[j][k]==0){
               return false;
             }
         }
     }
    
    return true;
}

int bfs(){
    int cnt=0;
    //큐에 넣은 갯수
    queue<Point> q;
    queue<int> qCnt;
    for(int i=0;i<start.size();i++){
        q.push(start[i]);
        qCnt.push(cnt);
        visited[start[i].y][start[i].x]=1;
    }
    while(!q.empty()){

            Point here=q.front();

            q.pop();
            countTime=cnt=qCnt.front();
            qCnt.pop();

            for(int i=0;i<4;i++){
                int x=here.x+dx[i];
                int y=here.y+dy[i];

                if(x<0||y<0||x>=M||y>=N)
                    continue;

                if(visited[y][x]==1||board[y][x]==-1)
                    continue;

                Point there(x,y);
                q.push(there);
                qCnt.push(cnt+1);
                board[y][x]=1;
                visited[y][x]=1;

        }
    }


    if(tomatoChk())
        return countTime;

    return -1;
}


int main(void){
    cin>>M>>N;

    
        for(int j=0;j<N;j++){
            for(int k=0;k<M;k++){
                cin>>board[j][k];
                if(board[j][k]==1){
                    Point p(k,j);
                    start.push_back(p);
                }
            }
        }
    cout<<bfs()<<endl;



}