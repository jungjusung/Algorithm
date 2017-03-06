#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

int R,C;
char board[51][51];
int waterBoard[51][51];
int heroBoard[51][51];

class point{
public:
    int x;
    int y;
};
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
point hero,result;
vector<point> waterV;

int bfs(point hero){
    int waterCnt=-1;
    int cnt=-1;
    int hIdx=1;
    int idx=waterV.size();
    queue<point> q;
    queue<int> numbers;
    for(int i=0;i<waterV.size();i++)
    {
        q.push(waterV[i]);
        waterBoard[waterV[i].x][waterV[i].y]=1;
        numbers.push(1);
    }
    //물 이동을 먼저 계산 할거라서 먼저 큐에 넣고

    q.push(hero);
    heroBoard[hero.x][hero.y]=1;
    numbers.push(0);


    //다람쥐를 그 후위에 넣는다.
    while(!q.empty()){
         int count=0;
         int hCount=0;
        for(int i=0;i<idx;i++){
            point waterLocation=q.front();
            q.pop();
            waterCnt=numbers.front();
            numbers.pop();
            //물의 움직임
            for(int j=0;j<4;j++){
                int x=waterLocation.x+dx[j];
                int y=waterLocation.y+dy[j];
                if(x>=R||x<0)
                    continue;
                if(y>=C||y<0)
                    continue;
                if(board[x][y]!='D'&&board[x][y]!='*'&&board[x][y]!='X'&&waterBoard[x][y]==0){
                    board[x][y]='*';
                    point newLocation;
                    newLocation.x=x;
                    newLocation.y=y;
                    //cout<<"물 : "<<newLocation.x<<" "<<newLocation.y<<endl;
                    q.push(newLocation);
                    waterBoard[x][y]=1;
                    numbers.push(waterCnt+1);
                    count++;
                }
            }
        }

        idx=count;
        count=0;
        for(int h=0;h<hIdx;h++){
            point heroLocation=q.front();
            q.pop();
            cnt=numbers.front();
            numbers.pop();
            //다람쥐의 움직임
            if(heroLocation.x==result.x&&heroLocation.y==result.y)
                return cnt;
            for(int i=0;i<4;i++)
            {
                int x=heroLocation.x+dx[i];
                int y=heroLocation.y+dy[i];
                if(x>=R||x<0)
                    continue;
                if(y>=C||y<0)
                    continue;
                if(board[x][y]!='X'&&board[x][y]!='S'&&board[x][y]!='*'&&heroBoard[x][y]==0){
                    if(board[x][y]=='.'||board[x][y]=='D'){
                        point newLocation;
                        newLocation.x=x;
                        newLocation.y=y;
                    //cout<<"다람쥐 :"<<newLocation.x<<" "<<newLocation.y<<endl;
                        board[newLocation.x][newLocation.y]='S';
                        board[heroLocation.x][heroLocation.y]='.';
                        q.push(newLocation);
                        heroBoard[x][y]=1;
                        numbers.push(cnt+1);
                        hCount++;
                    }
                }
            }
        }
        hIdx=hCount;
        hCount=0;

        /*for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;*/
    }

    return -1;
}
int main(void){
    cin>>R>>C;

    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>board[i][j];
            if(board[i][j]=='S'){
                hero.x=i;
                hero.y=j;
            }
            if(board[i][j]=='*'){
                point water;
                water.x=i;
                water.y=j;
                waterV.push_back(water);
            }
            if(board[i][j]=='D'){
                result.x=i;
                result.y=j;
            }
        }
    }
    int cnt=bfs(hero);
    if(cnt==-1)
        cout<<"KAKTUS"<<endl;
    else
        cout<<cnt<<endl;

}