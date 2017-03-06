#include <iostream>
#include <algorithm>
using namespace std;


int a[1001];
int dp[1001];
int N;
int main(void){
    cin>>N;
    for(int i=0;i<N;i++)
        cin>>a[i];

    dp[0]=1;
    int maxResult=0;
    int result=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<i;j++){
            if(a[i]>a[j]){
                maxResult=max(dp[j],maxResult);
            }
        }
        dp[i]=maxResult+1;
        maxResult=0;
        result=max(dp[i],result);
    }

/*    for(int i=0;i<N;i++)
        cout<<dp[i]<<" ";
    cout<<endl;*/
    cout<<result<<endl;

}