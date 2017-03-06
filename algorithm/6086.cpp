#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#define ALPHABAT 52
using namespace std;

class Edge {
public:
   int to;
   int capacity;
   Edge *rev;
   Edge(char to, int capacity){
   		this->to=to;
   		this->capacity=capacity;
   }
};
vector<vector<Edge* > > graph;

int N;
int source,sink;

int bfs(){
	vector<bool> visited(ALPHABAT,false);
	vector<pair<int, int> > from(ALPHABAT,make_pair(-1,-1));

	queue<int> q;
	q.push(source);
	visited[source]=true;

	while(!q.empty()){
		int here=q.front();
		q.pop();
		for(int i=0;i<graph[here].size();i++){
			if (graph[here][i]->capacity > 0 && !visited[graph[here][i]->to]) {
				q.push(graph[here][i]->to);
				visited[graph[here][i]->to] = true;
				from[graph[here][i]->to] = make_pair(here,i);
			}
		}
	}
	if(!visited[sink])
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
int charToInteger(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c - 'A';
    } else {
        return c - 'a' + 26;
    }
}
int main(void){
	cin>>N;
	source=0;
	sink='Z'-'A';
	graph.resize(ALPHABAT);

	for(int i=0;i<N;i++){
		int v,e,c;
		char _v,_e;
		cin>>_v>>_e>>c;

		v=charToInteger(_v);
		e=charToInteger(_e);
		Edge *ori = new Edge(e,c);
        Edge *rev = new Edge(v,0);
        ori->rev = rev;
        rev->rev = ori;
        graph[v].push_back(ori);
        graph[e].push_back(rev);
	}
	int result = 0;
	while (true) {
		int f = bfs();
		if (f == 0) break;
		result += f;
	}
	cout<<result<<endl;
}