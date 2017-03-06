#include <iostream>
#define ull unsigned long long
#define MOD 10007
using namespace std;

ull dp[1001];
ull compute(int n){
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-2]%MOD+dp[i-1]%MOD;
    }
    return dp[n]%MOD;
}


int main(void){

    int n;
    cin>>n;
    cout<<compute(n)<<endl;
}