#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int L,C;
vector<char> charSet;
char result[16];
char ch1[5]={'a','e','i','o','u'};
void dfs(int s,int c)
{
    int cnt=c;
    int start=s;
    result[cnt-1]=charSet[start];
    if(cnt==L)
    {
        int  num1=0;
        //모음
        int  num2=0;
        //자음
        for(int i=0;i<L;i++)
        {
            bool isNum1=false;
            for(int j=0;j<5;j++){
                if(result[i]==ch1[j])
                    isNum1=true;
            }
            if(isNum1)
                num1++;
            else
                num2++;
        }
        if(num1<1||num2<2)
            return;
        for(int i=0;i<L;i++)
            cout<<result[i]<<"";
        cout<<endl;
        return;
    }
    for(int i=1;i<charSet.size();i++){
        int next=s+i;
        if(next>=C)
            continue;
        //cout<<next<<" "<<cnt<<" "<<charSet[next]<<endl;
        dfs(next,cnt+1);
    }
    return;
}

int main(void){

    cin>>L>>C;
    for(int i=0;i<C;i++)
    {
        char ch;
        cin>>ch;
        charSet.push_back(ch);
    }
    sort(charSet.begin(),charSet.end());
    for(int i=0;i<=C-L;i++)
        dfs(i,1);



}