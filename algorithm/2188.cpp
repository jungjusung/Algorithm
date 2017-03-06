#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;

class Edge {
public:
   int to;
   int capacity;
   Edge *rev;
   Edge(int to, int capacity){
   		this->to=to;
   		this->capacity=capacity;
   }
};

int N,M;
int n,source,sink;
vector<vector<Edge* > > graph;

int bfs(){
	vector<bool> check(N+M+2,false);
	vector<pair<int, int> > from(N+M+2,make_pair(-1,-1));

	queue<int> q;
	q.push(source);
	check[source]=true;
	while(!q.empty()){
		int here=q.front();
		q.pop();

		for(int i=0;i<graph[here].size();i++){
			int capacity=graph[here][i]->capacity;
			int there=graph[here][i]->to;			
			if(capacity>0&&!check[there]){
				q.push(there);
				check[there]=true;
				from[there]=make_pair(here,i);
			}
		}
	}
	if (!check[sink])
		return 0;

	int x=sink;
	int c=graph[from[x].first][from[x].second]->capacity;
	
	//최고 작은 유량을 찾는다.
	while(from[x].first!= -1){
		if(c > graph[from[x].first][from[x].second]->capacity)
			c = graph[from[x].first][from[x].second]->capacity;
		x = from[x].first;
	}

	//레지듀얼 커페서티 그래프 작성
	x=sink;
	while(from[x].first!= -1){
		Edge *e=graph[from[x].first][from[x].second];
		e->capacity-=c;
		e->rev->capacity+=c;
		x=from[x].first;
	}
	return c;
}

int main(void){
	
	scanf("%d %d",&N,&M);
	graph.resize(N+M+2);
	sink=N+M+1;
	source=0;
	
	for(int i=1;i<=N;i++){
		int maxJob;
		scanf("%d",&maxJob);
		for(int j=0;j<maxJob;j++){
			int job;
			scanf("%d",&job);
			Edge *ori = new Edge(N+job,1);
        	Edge *rev = new Edge(i,0);
        	ori->rev = rev;
        	rev->rev = ori;
        	graph[i].push_back(ori);
        	graph[N+job].push_back(rev);
		}
	}
	for(int i=1;i<=N;i++){
			Edge *ori = new Edge(i,1);
        	Edge *rev = new Edge(source,0);
        	ori->rev = rev;
        	rev->rev = ori;
        	graph[source].push_back(ori);
        	graph[i].push_back(rev);	
        
		}
	for(int i=1;i<=M;i++){
		Edge *ori = new Edge(sink,1);
       	Edge *rev = new Edge(i+N,0);
       	ori->rev = rev;
       	rev->rev = ori;
       	graph[i+N].push_back(ori);
       	graph[sink].push_back(rev);	
	}

	int result = 0;
	while (true) {
		int f = bfs();
		if (f == 0) break;
		result += f;
	}
	printf("%d\n",result);
}