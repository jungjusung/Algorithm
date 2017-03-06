/* 
- 문제 2 -

2차원 배열이 주어졌을 때 (i,j) 위치부터 (x,y)위치까지 저장되어 있는 수의 합

1) 배열의 크기 N,M(1<=N,M<=300)
2) 합을 구할 부분의 개수 K (1<= K<=10000) 주어진다.
3) 다음 K줄에는 네 개의 정수로 i,j,x,y가 주어진다.

해결 방법

ex ) (1,3) (2,3)   (1,3)+(2,3)

*/

#include<iostream>
#include<cstring>
using namespace std;

int arr[301][301];
//int cache[301][301];
int N, M, K;

int sumArr(int i, int j, int x, int y)
{
	int sum = 0;
	for (int a = i; a <= x; a++)
	{
		for (int b = j; b <= y; b++)
		{
			sum += arr[a][b];
		}
	}
	return sum;
}


int main(void)
{
	cin >> N >> M;
	//memset(cache, -1, sizeof(cache));
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			int num;
			cin >> arr[i][j];
		}
	}
	cin >> K;

	for (int i = 0; i < K; i++)
	{
		int y1, x1, y2, x2;
		cin >> y1 >> x1 >> y2 >> x2;
		cout << sumArr(y1, x1, y2, x2) << endl;
	}
}