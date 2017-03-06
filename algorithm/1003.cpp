#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int> > fibo;
int N;
int zero=0;
int one=0;
int fibonacci(int n) {
    if(n==0){
        zero++;
        return 0;
    }
    else if(n==1){
        one++;
        return 1;
    }
    else
        return fibonacci(n-1)+fibonacci(n-2);
}
int main(void)
{
    cin>>N;
    for(int i=0;i<N;i++)
    {
        int n;
        cin>>n;

        fibonacci(n);
        fibo.push_back(make_pair(zero,one));
        zero=one=0;
    }
    for(int i=0;i<fibo.size();i++){
        cout<<fibo[i].first<<" "<<fibo[i].second<<endl;
    }
}