#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int V,E,S;
vector<vector<int> > adj;
bool visited[1001];
void bfs(int s){
	queue<int> q;
	q.push(s);
	visited[s]=true;
	while(!q.empty()){
		int here=q.front();
		q.pop();
		cout<<here<<" ";
		for(int i=0;i<adj[here].size();i++){
			int there=adj[here][i];

			 if(visited[there])
			 	continue;
			q.push(there);
			visited[there]=true;
		}
	}
	cout<<endl;
}
void dfs(int x){
	if(visited[x])
		return;
	cout<<x<<" ";
	visited[x]=true;
	for(int i=0;i<adj[x].size();i++){
		int there=adj[x][i];
		dfs(there);
	}
}
int main(void){
	cin>>V>>E>>S;
	adj=vector<vector<int> >(V+1,vector<int>(0,0));
	memset(visited, false, sizeof(visited));
    for(int i=0;i<E;i++){
        int v;
        int e;
        cin>>v>>e;
        adj[v].push_back(e);
        adj[e].push_back(v);
    }
    for(int i=1;i<=V;i++){
  		sort(adj[i].begin(),adj[i].end());
  	}
    dfs(S);
    cout<<endl;
  	memset(visited, false, sizeof(visited));
  	bfs(S);
}