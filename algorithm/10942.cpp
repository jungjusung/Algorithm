#include <stdio.h>
using namespace std;


int dp[2001][2001];
int A[2001];

int N,M;
int main(void){

	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		scanf("%d",&A[i]);
	}
	scanf("%d",&M);
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(i==j)
				dp[i][j]=1;
		}
	}
	for(int j=2;j<=N;j++){
		for(int k=1;k<j;k++){
			if(j-k==1){
				if(A[k]==A[j])
					dp[k][j]=1;
			}else{
				if(A[k]==A[j])
					dp[k][j]=dp[k+1][j-1];
			}
		}
	}
	for(int i=0;i<M;i++){
		int n,m;
		scanf("%d%d",&n,&m);
		printf("%d\n", dp[n][m]);
	}
}