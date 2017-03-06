#include <iostream>
#include <algorithm>
using namespace std;

int N;
long long dp[100001];
long long a[100001];
int main(void){

    cin>>N;
    for(int i=1;i<=N;i++)
        cin>>a[i];

   for(int i=1;i<=N;i++){
        dp[i]=max(dp[i-1]+a[i],a[i]);
    }
   /* for(int i=1;i<=N;i++)
        cout<<dp[i]<<" ";
    cout<<endl;*/

    long long result=-999999;
    for(int i=1;i<=N;i++){
        result=max(result,dp[i]);
    }
    cout<<result<<endl;

}
