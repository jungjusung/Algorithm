#include<iostream>
#include<cstring>
using namespace std;

int N, K;
int coin[101];
int coinProbability[100001];
/*

1 1 1 1 1 1 1 1 1 1 1
    2 2 3 3 4 4 5 5 6
	      4 5 6 7 8 10

*/
void computeCoin()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			if (j - coin[i] >= 0)
			{
				coinProbability[j] += coinProbability[j - coin[i]];
			}
		}
	}
}

int main(void)
{
	
	cin >> N >> K;
	memset(coin, 0, sizeof(coin));
	memset(coinProbability, 0, sizeof(coinProbability));
	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		coin[i] = n;
	}
	coinProbability[0] = 1;
	/*for (int i = 0; i <= K; i++)
	{
		cout << coinProbability[i] << " ";
	}
	cout << endl;*/
	computeCoin();
	/*for (int i = 0; i <= K; i++)
	{
		cout << coinProbability[i] << " ";
	}
	cout << endl;*/
	cout << coinProbability[K] << endl;
}