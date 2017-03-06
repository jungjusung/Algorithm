#include <iostream>
using namespace std;

int T,n;
long long dp[68];

long long koong(int n){
    if(n<2){
        if(dp[n]==0)
            dp[n]=1;
        return dp[n];
    }
    else if(n==2){
        if(dp[n]==0)
            dp[n]=2;
        return dp[n];
    }
    else if(n==3){
        if(dp[n]==0)
            dp[n]=4;
        return dp[n];
    }
    else if(n>3){
        if(dp[n]!=0)
            return dp[n];

        long long result=koong(n-1)+koong(n-2)+koong(n-3)+koong(n-4);
        return dp[n]=result;
    }
}
int main(void){

    cin>>T;
    for(int i=0;i<T;i++){
        cin>>n;
        cout<<koong(n)<<endl;
    }
}