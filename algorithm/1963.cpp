#include <iostream>
#include <sstream>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

int isPrime[10001];
int N;
int visited[10001];
char number[10]={'0','1','2','3','4','5','6','7','8','9'};
string intToString(int n)
{

    stringstream s;
    s << n;
    return s.str();

}
int bfs(int start,int end){
    int cnt=0;
    queue<int> q;
    q.push(start);
    q.push(cnt);
    visited[start]=1;
    int num=0;
    while(!q.empty()){
        num++;
        int here=q.front();
        q.pop();
        cnt=q.front();
        q.pop();

        if(here==end){
            return cnt;
        }
        for(int i=0;i<4;i++){
            string str=intToString(here);
            for(int j=0;j<=9;j++){
                str[i]=number[j];
                int there=(str[0]-48)*1000+(str[1]-48)*100+(str[2]-48)*10+(str[3]-48);

                if(1000>there||there>=10000)
                    continue;
                if(isPrime[there]==1||visited[there]==1)
                    continue;
                q.push(there);
                q.push(cnt+1);
                visited[there]=1;
            }
        }
    }
    return -1;

}
int main(void){

    cin>>N;
    for(int i=2;i<10001;i++){
        for(int j=2;i*j<10001;j++){
            isPrime[i*j]=1;
        }
    }
    for(int i=0;i<N;i++){
        int start,end;
        memset(visited,0,sizeof(visited));
        cin>>start>>end;
        int result=bfs(start,end);
        if(result==-1)
            cout<<"Impossible"<<endl;
        else
            cout<<result<<endl;
    }
}