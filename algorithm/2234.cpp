#include <iostream>
#include <queue>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;
 
int board[51][51];
int visited[51][51];
 
int width,height;
int totalRoom=1;
int maxSize;
int sumRoom;
class Point{
public:
    int x;
    int y;
    int cnt;
    Point(int _x,int _y)
    {
        x=_x;
        y=_y;
        cnt=0;
    }
};
 
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
//동서남북
 
int getAbit(unsigned short x, int n) {
  return (x & (1 << n)) >> n;
}
/*int bfs(){
    int cnt=0;
    int breakNum=0;
    queue<Point> q;
    queue<int> qCnt;
    //카운트 넣고 부쉰 횟수를 넣는다.
    Point start(0,0);
    q.push(start);
    qCnt.push(cnt);
    visited[start.y][start.x][start.cnt]=1;
 
    while(!q.empty()){
        // 조건 1.breakNum > 1 이면 안 넣는다
        // 조건 2.breakNum 가 1 일때 cnt 값 찾는다.
        Point here=q.front();
        q.pop();
        cnt=qCnt.front();
        qCnt.pop();
        //if(here.cnt>1)
          //  continue;
        cout<<here.x<<" "<<here.y<<" "<<here.cnt<<endl;
        maxSize=max(cnt,maxSize);
        if(cnt==width*height)
            return cnt;
        //맵을 다 돌았을 경우
        for(int i=0;i<4;i++){
            int x=here.x+dx[i];
            int y=here.y+dy[i];
            int count=here.cnt;
 
            if(y<0||y>height-1||x<0||x>width-1)
                continue;
            //방문 한 곳
            if(visited[y][x][count]==1)
                continue;
            //동쪽 이동 막히는 경우
            //2진수 우측에서 2번째가 1일 경우
            Point there(x,y);
            if(i==0)
            {
                //오른쪽으로 가려고 하는데 막혀 있음!
                if(getAbit(board[here.y][here.x],2)==1)
                    there.cnt+=1;
                q.push(there);
                qCnt.push(cnt+1);
                visited[y][x][count]=1;
            }else if(i==1){
            //왼쪽 이동이 막히는 경우
            //2진수 우측에서 0번째가 1인 경우
                //오른쪽으로 가려고 하는데 막혀 있음!
                if(getAbit(board[here.y][here.x],0)==1)
                    there.cnt+=1;
                q.push(there);
                qCnt.push(cnt+1);
                visited[y][x][count]=1;
            }else if(i==2){
            //아래쪽 이동이 막히는 경우
            //2진수 우측에서 3번째가 1인 경우
                //오른쪽으로 가려고 하는데 막혀 있음!
                if(getAbit(board[here.y][here.x],3)==1)
                    there.cnt+=1;
                q.push(there);
                qCnt.push(cnt+1);
                visited[y][x][count]=1;
            }else{
            //북쪽 이동이 막히는 경우
            //2진수 우측에서 1번째가 1인 경우
                //오른쪽으로 가려고 하는데 막혀 있음!
                if(getAbit(board[here.y][here.x],1)==1)
                    there.cnt+=1;
                q.push(there);
                qCnt.push(cnt+1);
                visited[y][x][count]=1;
            }
        }
 
    }
 
    return -1;
}*/
int Count=1;
vector<int> sizeVec;
vector<pair<int,int> > diff;
void dfs(int y,int x){
    Point start(x,y);
    if(y<0||y>=height||x<0||x>=width)
            return;
    if(visited[start.y][start.x]!=0)
        return;
    visited[start.y][start.x]=totalRoom;
 
    for(int i=0;i<4;i++){
        int x=start.x+dx[i];
        int y=start.y+dy[i];
 
        if(y<0||y>=height||x<0||x>=width)
                continue;
 
 
        if(i==0)
        {
            if(getAbit(board[y][x],0)==1)
                continue;
            //오른쪽으로 가려고 하는데 막혀 있음!
            if(getAbit(board[start.y][start.x],2)==1)
                continue;
 
        }else if(i==1){
        //왼쪽 이동이 막히는 경우
        //2진수 우측에서 0번째가 1인 경우
            //오른쪽으로 가려고 하는데 막혀 있음!
            if(getAbit(board[y][x],2)==1)
                continue;
 
            if(getAbit(board[start.y][start.x],0)==1)
                continue;
 
        }else if(i==2){
        //아래쪽 이동이 막히는 경우
        //2진수 우측에서 3번째가 1인 경우
            //오른쪽으로 가려고 하는데 막혀 있음!
            if(getAbit(board[y][x],1)==1)
                continue;
            if(getAbit(board[start.y][start.x],3)==1)
                continue;
 
        }else if(i==3){
        //북쪽 이동이 막히는 경우
        //2진수 우측에서 1번째가 1인 경우
            //오른쪽으로 가려고 하는데 막혀 있음!
 
            if(getAbit(board[y][x],3)==1)
                continue;
            if(getAbit(board[start.y][start.x],1)==1)
                continue;
        }
 
        Point there(x,y);
        if(visited[there.y][there.x]==0)
        {
            dfs(there.y,there.x);
            Count++;
        }
    }
    //totalRoom++;
 
}
int main(void){
    cin>>width>>height;
 
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            cin>>board[i][j];
        }
    }
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(visited[i][j]==0)
            {
                dfs(i,j);
                totalRoom++;
                maxSize=max(maxSize,Count);
                sizeVec.push_back(Count);
                Count=1;
            }
        }
    }
   /* for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            cout<<setw(2)<<visited[i][j]<<" ";
        }
        cout<<endl;
    }*/
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(j==width||i==height)
                break;
            if(visited[i][j]!=visited[i][j+1])
                diff.push_back(make_pair(visited[i][j],visited[i][j+1]));
            if(visited[i][j]!=visited[i+1][j])
                diff.push_back(make_pair(visited[i][j],visited[i+1][j]));
        }
        //cout<<endl;
    }

    for(int i=0;i<diff.size();i++){
        if(diff[i].second==0)
            continue;
        sumRoom=max(sizeVec[diff[i].first-1]+sizeVec[diff[i].second-1],sumRoom);
        //cout<<diff[i].first<<" "<<diff[i].second<<endl;
    }
    cout<<totalRoom-1<<endl;
    cout<<maxSize<<endl;
    if(diff.size()==0)
        sumRoom=maxSize;
    cout<<sumRoom<<endl;
 
}