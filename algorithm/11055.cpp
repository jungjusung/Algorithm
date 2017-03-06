#include <iostream>
#include <algorithm>
using namespace std;

int A[1001];
int dp[1001];
int N;
int main(void){

    cin>>N;
    int result=0;
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    dp[0]=A[0];
    for(int i=1;i<=N;i++){
        for(int j=0;j<i;j++){
            if(A[j]<A[i])
                dp[i]=max(dp[j]+A[i],dp[i]);
            else
                dp[i]=max(A[i],dp[i]);
        }
    }
    for(int i=0;i<N;i++){
        //cout<<dp[i]<<" ";
        result=max(dp[i],result);
    }
   // cout<<endl;
    cout<<result<<endl;
}