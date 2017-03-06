#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class point{
public:
    int y;
    int x;
    int val;

    point(){};
    point(int _x,int _y,int _val){
        x=_x;
        y=_y;
        val=_val;
    };
};

int N;
int dp[501][501];
int board[501][501];

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

vector<point> vec;
bool comp(point p1,point p2){
    if(p1.val>p2.val)
        return true;
    else
        return false;
}
int main(void){
    cin>>N;
    int result=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>board[i][j];
            point p(j,i,board[i][j]);
            vec.push_back(p);
            dp[i][j]=1;
        }
    }

    sort(vec.begin(),vec.end(),comp);

    for(int i=0;i<vec.size();i++){
        for(int k=0;k<4;k++){
            int x=vec[i].x+dx[k];
            int y=vec[i].y+dy[k];

            if(x<0||y<0||x>=N||y>=N)
                continue;

            if(board[vec[i].y][vec[i].x]>=board[y][x])
                continue;

            dp[vec[i].y][vec[i].x]=max(dp[y][x]+1,dp[vec[i].y][vec[i].x]);
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            result=max(dp[i][j],result);
        }
    }
    cout<<result<<endl;

}