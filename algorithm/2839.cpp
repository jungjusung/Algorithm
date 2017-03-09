#include <iostream>
#include <queue>
using namespace std;


bool visited[5001];
int bfs(int sugar){
	int cnt=0;
	queue<int> q;
	q.push(0);
	q.push(cnt);
	visited[0]=true;
	while(!q.empty()){
		int here=q.front();
		q.pop();
		cnt=q.front();
		q.pop();
		
		if(here==sugar)
			return cnt;

		if(here+5<5001&&!visited[here+5]){
			int there=here+5;
			q.push(there);
			q.push(cnt+1);
			visited[there]=true;
		}

		if(here+3<5001&&!visited[here+3]){
			int there=here+3;
			q.push(there);
			q.push(cnt+1);
			visited[there]=true;
		}
	}

	return -1;
}
int main(void){

	int n;
	cin>>n;
	cout<<bfs(n)<<endl;	
}