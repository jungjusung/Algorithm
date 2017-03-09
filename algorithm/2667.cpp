#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int N,cnt;
int board[26][26];
int visited[26][26];

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
vector<int> ans;
void dfs(int y, int x){
	if(visited[y][x]!=0)
		return;

	visited[y][x]=cnt;
	for(int i=0;i<4;i++){
	 	int _x=x+dx[i];
	 	int _y=y+dy[i];
	 	if(_x<0 || _y<0 ||_x>=N || _y>=N||board[_y][_x]==0)
	 		continue;
	 	dfs(_y,_x);
	}
}

int main(void){
	cin>>N;
	for(int i=0;i<N;i++){
		string s;
		cin>>s;
		for(int j=0;j<N;j++){
			board[i][j]=(int)s[j]-'0';
			visited[i][j]=0;
		}
	}
	cnt=1;

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(board[i][j]==1&&visited[i][j]==0){
				dfs(i,j);
				cnt++;
			}
		}
	}
	
	cout<<cnt-1<<endl;
	for(int k=1;k<cnt;k++){
		int num=0;
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(visited[i][j]==k)
					num+=1;
			}
		}
		ans.push_back(num);
	}
	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<endl;

}