#include <iostream>
#include <algorithm>
using namespace std;

int a[1001];
int dp[1001];
int N;
int main(void){


    cin>>N;
    int result=0;
    for(int i=0;i<N;i++)
        cin>>a[i];
    dp[0]=0;

    for(int i=0;i<N;i++){
        int maxSize=0;
        for(int j=0;j<i;j++){
            if(a[j]<a[i])
            {
                maxSize=max(maxSize,dp[j]);
            }
        }
        dp[i]=maxSize+1;
    }

    for(int i=0;i<N;i++){
       // cout<<dp[i]<<" ";
        result=max(result,dp[i]);
    }
    cout<<result<<endl;

}