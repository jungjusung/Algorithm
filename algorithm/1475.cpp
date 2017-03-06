#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
char room[10]={'0','1','2','3','4','5','6','7','8','9'};
int roomNum[10];
int main(void)
{
    int maxNum=0;
    string str;
    cin>>str;
    memset(roomNum,0,sizeof(roomNum));
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='9'||str[i]=='6')
        {
            roomNum[6]++;
        }
        else{
            for(int j=0;j<10;j++)
            {
                if(room[j]==str[i])
                {
                    roomNum[j]++;
                }
            }
        }
    }

    if(roomNum[6]%2==0)
        roomNum[6]=roomNum[6]/2;
    else
        roomNum[6]=roomNum[6]/2+1;

    for(int i=0;i<10;i++)
    {
        maxNum=max(roomNum[i],maxNum);
    }
    cout<<maxNum<<endl;


}