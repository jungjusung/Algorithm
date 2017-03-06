#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
struct Edge {
    int to;
    int cost;
    Edge(int to, int cost) : to(to), cost(cost) {
    }
};
vector<Edge> a[20001];
int dist[20001];
bool check[20001];
int inf = 1000000000;
int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    int start;
    scanf("%d",&start);
    for (int i=0; i<m; i++) {
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        a[x].push_back(Edge(y,z));
    }
    for (int i=1; i<=n; i++) {
        dist[i] = inf;
    }

    dist[start] = 0;
    priority_queue<pair<int,int>> q;
    q.push(make_pair(0, start));
    while (!q.empty()) {
        auto here = q.top();
        q.pop();
        int v = here.second;
        if (check[v]) {
            continue;
        }
        check[v] = true;
        for (int i=0; i<a[v].size(); i++) {
            int there = a[v][i].to;
            if (dist[there] > dist[v] + a[v][i].cost) {
                dist[there] = dist[v] + a[v][i].cost;
                q.push(make_pair(-dist[there], there));
            }
        }
    }
    for (int i=1; i<=n; i++) {
        if (dist[i] >= inf) {
            printf("INF\n");
        } else {
            printf("%d\n",dist[i]);
        }
    }
    return 0;
}

