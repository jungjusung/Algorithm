#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

char memo[50][50];
char memo_temp[50][50];
char distance1[50][50];

class location
{
    public:
        int x;
        int y;
};
int Y,X;
location start;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int maxCount=0;
void bfs(int y,int x)
{
    if(memo[y][x]=='L')
    {
        queue<location> q;
        start.y=y;
        start.x=x;
        //cout<<start.y<<" "<<start.x<<endl;
        memo[start.y][start.x]='W';
        q.push(start);
        distance1[y][x]=0;

        while(!q.empty())
        {

            location here=q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                int x=here.x+dx[i];
                int y=here.y+dy[i];
                //cout<<y<<" "<<x<<endl;
                if(0<=x&&x<X&&0<=y&&y<Y)
                {
                    if(memo[y][x]=='L')
                    {
                        location there;
                        there.x=x;
                        there.y=y;

                        q.push(there);
                        distance1[y][x]=distance1[here.y][here.x]+1;
                        maxCount=max((int)distance1[y][x],maxCount);
                        memo[y][x]='W';

                    }
                }
            }
        }
    }

    //vector<int,int > start(1,make_pair(y,x));
    //q.push()
}
int main(void)
{
    cin>>Y>>X;

    for(int i=0;i<Y;i++)
    {
        for(int j=0;j<X;j++)
        {
            cin>>memo_temp[i][j];
        }
    }

    for(int i=0;i<Y;i++)
    {
        for(int j=0;j<X;j++)
        {
            memcpy(memo,memo_temp,sizeof(memo));
            bfs(i,j);
        }

    }
    cout<<maxCount<<endl;

}