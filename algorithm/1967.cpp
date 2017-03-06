#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
vector<pair<int,int> > adj[10001];
int res=0;
int dfs(int here){
   int r1=0,r2=0;
   //cout<<here<<endl;
    for (int i=0;i<adj[here].size();i++) {
        r2 = max(r2, adj[here][i].second + dfs(adj[here][i].first));
        if (r1 < r2)
            swap(r1, r2);
    }
    res = max(res, r1 + r2);
    return r1;

}

int main(void){

    cin>>N;
    for(int i=1;i<=N;i++){
        int v,e,val;
        cin>>v>>e>>val;
        adj[v].push_back({e,val});
    }
    dfs(1);
    cout<<res<<endl;
}