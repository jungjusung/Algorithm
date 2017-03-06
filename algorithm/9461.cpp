#include <iostream>
using namespace std;

long long pado[101];
long long T,N;
void compute(){
    pado[1]=1;
    pado[2]=1;
    pado[3]=1;
    for(int i=4;i<=100;i++){
        pado[i]=pado[i-3]+pado[i-2];
    }
}
int main(void){
    cin>>T;
    compute();
    for(int i=0;i<T;i++){
        cin>>N;
        cout<<pado[N]<<endl;
    }
}