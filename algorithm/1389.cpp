#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N,M;
int visited[101];
vector<int> adj[101];

int bfs(int start,int end){

    int cnt=0;
    queue<int> q;
    q.push(start);
    q.push(cnt);
    visited[start]=1;

    while(!q.empty()){

        int here=q.front();
        q.pop();
        cnt=q.front();
        q.pop();
        if(here==end)
            return cnt;

        for(int i=0;i<adj[here].size();i++)
        {
            int there=adj[here][i];
            if(visited[there]==1)
                continue;

            q.push(there);
            q.push(cnt+1);
            visited[there]=1;
        }
    }
}

int main(void){

    cin>>N>>M;
    for(int i=0;i<M;i++){
        int v,e;
        cin>>v>>e;
        adj[v].push_back(e);
        adj[e].push_back(v);
    }

    int minKevin=999999;
    int idx=0;
    for(int i=1;i<=N;i++){
        int result=0;
        for(int j=1;j<=N;j++){
            if(i==j)
                continue;
            memset(visited,0,sizeof(visited));
            result+=bfs(i,j);
        }
        if(minKevin>result){
            minKevin=result;
            idx=i;
        }
    }
    cout<<idx<<endl;

}