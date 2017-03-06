#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
vector<vector<int> > adj;
int board[101][101];
void bfs(int start,vector<int>& distance)
{
    //distance : 각 지점으로 가는 최단 경로의 합
    distance=vector<int>(adj.size(),-1);
    queue<int> q;
    distance[start]=-1;//시작->시작 지점은 0

    q.push(start);
    while(!q.empty()){
        int here=q.front();
        q.pop();
        for(int i=0;i<adj[here].size();i++)
        {
            int there=adj[here][i];
            if(distance[there]==-1)
            {
                q.push(there);
                distance[there]=distance[here]+1;
            }
        }
    }
}

int main(void)
{
    cin>>N;

    adj=vector<vector<int> >(N,vector<int>(0,0));
    vector<int> distance;

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>board[i][j];
        }
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(board[i][j]==1)
            {
                adj[i].push_back(j);
                //adj[j].push_back(i);
            }
        }
    }
   /*for(int i=0;i<N;i++)
    {
        for(int j=0;j<adj[i].size();j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }*/

    for(int i=0;i<N;i++)
    {
        bfs(i,distance);
        for(int j=0;j<distance.size();j++)
        {
            if(distance[j]>=0)
                cout<<"1 ";
            else
                cout<<"0 ";
        }
        cout<<endl;
    }

}
