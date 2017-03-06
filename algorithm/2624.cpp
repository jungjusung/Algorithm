#include <iostream>
using namespace std;

int dp[10001][101];
int T,N;
class coin{
public:
    int price;
    int num;
    coin(){};
    coin(int price,int num){
        this->price=price;
        this->num=num;
    }
};
int main(void){

    cin>>T>>N;
    coin c[101];
    dp[0][0]=1;
    for(int i=1;i<=N;i++){
        int price,num;
        cin>>price>>num;
        c[i].price=price;
        c[i].num=num;
        dp[0][i]=1;
    }


    for (int i=1;i<=N;i++ )
    {
        for (int j=1;j<=T;j++ )
        {
            for (int k=0 ;k<=c[i].num;k++ )
            {
                if (c[i].price*k>j)
                    break;
                dp[j][i] += dp[j-c[i].price*k][i-1];
            }
        }
    }

    cout<<dp[T][N]<<endl;

}