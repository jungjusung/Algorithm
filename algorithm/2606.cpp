#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int> > adj;

int N,M;

int num=0;
int visited[101];
void bfs(){

	int start=1;
	int cnt=1;
	visited[start]=1;
	queue<int> q;
	q.push(start);
	q.push(cnt);
	while(!q.empty()){

		int here=q.front();
		
		q.pop();
		cnt=q.front();
		q.pop();
		//cout<<here<<" "<<cnt<<endl;
		for(int i=0;i<adj[here].size();i++){
			int there=adj[here][i];
			
			if(visited[there]==1)
				continue;

			q.push(there);
			q.push(cnt+1);
			visited[there]=1;
			num++;
			//cout<<num<<endl;
		}
	}




}
int main(void){

	cin>>N>>M;

	adj=vector<vector<int> >(N+1,vector<int>(0,0));
	for(int i=0;i<M;i++){
		int v;
		int e;
		cin>>v>>e;
		adj[v].push_back(e);
		adj[e].push_back(v);
	}

	 // for(int i=1;i<N+1;i++){
	 // 	for(int j=0;j<adj[i].size();j++)
	 // 		cout<<adj[i][j]<<" ";
	 // 	cout<<endl;
	 // }
	bfs();
	cout<<num<<endl;
}
