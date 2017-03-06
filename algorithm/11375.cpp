#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;


int N,M;
vector<vector<int > > graph;
vector<bool> check;
vector<int> pred;
bool dfs(int here) {
 	if(here==-1)
 		return true;
 	for(int next:graph[here]){
 		if(check[next])
 			continue;
 		check[next]=true;
 		if(dfs(pred[next])){
 			pred[next]=here;
 			return true;
 		}
 	}
 	return false;
}

int main(void){
	
	scanf("%d %d",&N,&M);
	graph.resize(N+M+2);
	check.resize(N+M+2);
	pred.resize(N+M+2,-1);
	
	for(int i=0;i<N;i++){
		int maxJob;
		scanf("%d",&maxJob);
		for(int j=0;j<maxJob;j++){
			int job;
			scanf("%d",&job);
        	graph[i].push_back(job-1);
		}
	}
	
	int result = 0;
	for(int i=0;i<M+N+2;i++){
		fill(check.begin(),check.end(),false);
		if(dfs(i)){
			result++;
		}
	}
	printf("%d\n",result);
}