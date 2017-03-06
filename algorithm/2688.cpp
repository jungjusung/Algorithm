#include <iostream>
#include <cstring>
using namespace std;

long long T,n;
long long arr[10][65];
void compute(long long n){
    for(int i=0;i<10;i++){
            arr[i][1]=1;
    }
    for(int i=2;i<=n;i++){
        for(int j=0;j<10;j++){
            for(int k=0;k<=j;k++){
                arr[j][i]+=arr[k][i-1];
            }
        }
    }

}
int main(void){

    cin>>T;
    for(int i=0;i<T;i++){
        cin>>n;
        memset(arr,0,sizeof(arr));
        compute(n);
        long long sum=0;
        /*for(long j=0;j<10;j++){
            for(long k=1;k<=n;k++)
            {
                cout<<arr[j][k]<<" ";
            }
            cout<<endl;
        }*/
        for(int j=0;j<10;j++){
            sum+=arr[j][n];
        }
        cout<<sum<<endl;
    }

}
