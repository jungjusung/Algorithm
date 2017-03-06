#include <iostream>
#include <cstring>
#include <vector>
using namespace std;


int N;
int M;
int cache[41];


int fibo(int n)
{
    if(n==0)
        return 1;
    if(n==1)
        return 1;
    int& ret=cache[n];
    if(ret!=-1)
        return ret;

    return ret=fibo(n-1)+fibo(n-2);
}

int compute(vector<int> s){
    int cnt=1;
    for(int i=1;i<s.size();i++)
    {
        cnt*=fibo(s[i]-s[i-1]-1);
    }

    return cnt;
}

int main(void)
{
    cin>>N;
    cin>>M;
    memset(cache,-1,sizeof(cache));
    vector<int> fixed;
    fixed.push_back(0);
    for(int i=0;i<M;i++)
    {
        int n;
        cin>>n;
        fixed.push_back(n);
    }
    fixed.push_back(N+1);
    cout<<compute(fixed)<<endl;
}