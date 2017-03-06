#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N,K;
int dis[100001];
int bfs(int start){
    int cnt=-1;
    queue<int> q;
    q.push(start);
    q.push(0);
    dis[start] = 1;

    while(!q.empty()) {
        int here = q.front();
        q.pop();
        cnt = q.front();
        q.pop();
        if(here==K)
            return cnt;
        if(0<=here+1&&here+1<=100000&&dis[here+1]==0){
            q.push(here+1);
            q.push(cnt+1);
            dis[here+1]=1;
        }
        if(0<=here-1&&here-1<=100000&&dis[here-1]==0){
            q.push(here-1);
            q.push(cnt+1);
            dis[here-1]=1;
        }
        if(0<=here*2&&here*2<=100000&&dis[here*2]==0){
            q.push(here*2);
            q.push(cnt+1);
            dis[here*2]=1;
        }
    }
    return -1;
}
int main(void)
{

    cin>>N>>K;
    memset(dis,0,sizeof(dis));
    cout<<bfs(N)<<endl;

}