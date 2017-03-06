#include <iostream>
#include <queue>

using namespace std;

int F,S,G,U,D;

bool dis[1000001];

int bfs(int start) {
    int cnt =  -1;
    queue<int> q;
    q.push(start);
    q.push(0);
    dis[start] = 1;
    while(!q.empty()) {
        int here = q.front();
        q.pop();
        cnt = q.front();
        q.pop();
        if(here == G) return cnt;

        if(here+U <= F && dis[here+U] == 0) {
            q.push(here+U);
            q.push(cnt+1);
            dis[here+U] = 1;
        }
        if(here-D > 0 && dis[here-D] == 0) {
            q.push(here-D);
            q.push(cnt+1);
            dis[here-D] = 1;
        }
    }
    return -1;
}


int main() {
    cin>>F>>S>>G>>U>>D;
    int res = bfs(S);
    if(res == -1) {
        cout << "use the stairs" << endl;
    }
    else {
        cout << res << endl;
    }

    return 0;
}