#include <iostream>
using namespace std;

int result;
void dfs(int start,int cnt,int last1){
    int count=cnt;
    int init=start;
   // cout<<init<<" "<<cnt<<" "<<last1<<endl;
    if(init==last1){
        result++;
        return;
    }
    for(int i=1;i<=3;i++){
        int next=init+i;
        if(next>last1)
            continue;
        dfs(next,count+1,last1);
    }

    return;
}



int main(void){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=3;j++)
            dfs(j,1,k);
        cout<<result<<endl;
        result=0;
    }
}