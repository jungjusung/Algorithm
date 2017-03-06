#include <stdio.h>
#include <algorithm>
#define MAX 987654321
#define NO_TICKET 10000
#define FIRST_TICKET 25000
#define SECOND_TICKET 37000
using namespace std;


int N,M;
int day[105];
int dp[105][105];
int main(void){

	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++){
		int k;
		scanf("%d",&k);
		day[k]=-1;
	}
	for(int i=0;i<=N;i++){
		for(int j=0;j<=N;j++){
			dp[i][j]=MAX;
		}
	}
	dp[0][0]=0;
	//dp[N][M] N개의 일에서 M개의 쿠폰을 가지고 있을때 최소 금액
	for(int i=0;i<=N;i++){
		for(int j=0;j<=N;j++){
			//j는 i일동안 가질수 있는 최대 쿠폰의 개수
			//j시간동안 반복한다.
			
            //관람 x
            if(day[i+1]==-1)
				dp[i+1][j]=min(dp[i][j],dp[i+1][j]);
			
			if(j>=3)
				dp[i+1][j-3]=min(dp[i][j],dp[i+1][j-3]);
				
				dp[i+1][j]=min(dp[i][j]+NO_TICKET,dp[i+1][j]);
				dp[i+3][j+1]=min(dp[i][j]+FIRST_TICKET,dp[i+3][j+1]);		
				dp[i+5][j+2]=min(dp[i][j]+SECOND_TICKET,dp[i+5][j+2]);
		}
	}

	int result=MAX;	
    //cout 쓰면 런타임
	for(int j=0;j<=N;j++)
		result=min(dp[N][j],result);
	printf("%d\n",result);
}