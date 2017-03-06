#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001];
int dp2[1001];
int A[1001];
int N;
int main(void){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    int result=0;
    dp[0]=1;
    dp2[N-1]=1;
    for(int i=1;i<N;i++){
        for(int j=0;j<i;j++){
            if(A[j]<A[i]){
                dp[i]=max(dp[j]+1,dp[i]);
            }
            else{
                dp[i]=max(dp[i],1);
            }
        }
    }
    for(int i=N-2;i>=0;i--){
        for(int j=N-1;j>=0;j--){
            if(A[j]<A[i]){
                dp2[i]=max(dp2[j]+1,dp2[i]);
            }
            else{
                dp2[i]=max(dp2[i],1);
            }
        }
    }

    for(int i=0;i<N;i++){
        result=max(result,dp[i]+dp2[i]);
        //cout<<dp[i]<<" ";
    }
/*    cout<<endl;
    for(int i=0;i<N;i++)
        cout<<dp2[i]<<" ";
    cout<<endl;*/
    cout<<result-1<<endl;
}