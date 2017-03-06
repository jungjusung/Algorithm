#include<iostream>
#include<algorithm>
using namespace std;
int rgb[1000][3];
int cost[1000][3];
int N;
int rgbMin(int k)
{

	cost[0][0] = rgb[0][0];
	cost[0][1] = rgb[0][1];
	cost[0][2] = rgb[0][2];

	for (int i = 1; i < k; i++)
	{
		cost[i][0] = min(cost[i - 1][1], cost[i - 1][2]) + rgb[i][0];
		cost[i][1] = min(cost[i - 1][0], cost[i - 1][2]) + rgb[i][1];
		cost[i][2] = min(cost[i - 1][0], cost[i - 1][1]) + rgb[i][2];
	}

	return min(min(cost[k - 1][0], cost[k - 1][1]), cost[k - 1][2]);
}
int main(void)
{
	int n;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int r, g, b;
		cin >> r >> g >> b;
		rgb[i][0] = r;
		rgb[i][1] = g;
		rgb[i][2] = b;
	}
	cout << rgbMin(N)<< endl;

	return 0;
}