#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
int N,M;
vector<int> board[10001];
int val[10001];
int maxSize=0;
int size=0;

void bfs(int start){
    int visited[10001]={};
    queue<int> q;
    int cnt=0;
    q.push(start);
    visited[start]=1;
    cnt++;

    while(!q.empty()){

        int here=q.front();
        q.pop();

        for(int i=0;i<board[here].size();i++){

            int there=board[here][i];

            if(visited[there]!=0)
                continue;

            q.push(there);
            visited[there]=1;
            cnt++;
        }
    }
    if (maxSize < cnt)
    {
        size = 0;
        maxSize = cnt;
        val[size++] = start;
    }
    else if (maxSize == cnt)
    {
        val[size++] = start;
    }

}

int main(void){

    cin>>N>>M;
    for(int i=0;i<M;i++){
        int x,y;
        cin>>x>>y;
        board[y].push_back(x);

    }
    for(int i=1;i<=N;i++){
        bfs(i);
    }


    for (int i = 0; i < size; i++)
        cout<<val[i]<<" ";
}