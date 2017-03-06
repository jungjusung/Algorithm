#include <iostream>
#define ll long long
using namespace std;

ll dp[91][2];
ll compute(int n){
    dp[1][0]=0;
    dp[1][1]=1;
    for(int i=2;i<=n;i++){
        dp[i][0]=dp[i-1][1]+dp[i-1][0];
        dp[i][1]=dp[i-1][0];
    }
    return dp[n][1]+dp[n][0];
}
int main(void){
    int n;
    cin>>n;
    cout<<compute(n)<<endl;
}