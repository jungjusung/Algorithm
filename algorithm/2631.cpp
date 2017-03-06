#include <iostream>
#include <algorithm>
using namespace std;

int N;
int A[201];
int dp[201];
int main(void){

    cin>>N;
    for(int i=0;i<N;i++)
        cin>>A[i];
    dp[0]=1;
    int result=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<i;j++){
            if(A[j]<A[i])
                dp[i]=max(dp[j]+1,dp[i]);
            else
                dp[i]=max(dp[i],1);
        }
    }

    for(int i=0;i<N;i++){
        result=max(result,dp[i]);
    }

    cout<<N-result<<endl;
}