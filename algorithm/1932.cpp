#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int n;
int tri[500][500];
int cache[500][500];

int maxPath(int y, int x)
{
	if (y == n - 1)
		return tri[y][x];

	int& ret = cache[y][x];
	if (ret != -1)
		return ret;
	return ret = max(maxPath(y + 1, x), maxPath(y + 1, x + 1)) + tri[y][x];
}

int main(void)
{
	cin >> n;
	memset(cache, -1, sizeof(cache));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			int num;
			cin >> num;
			tri[i][j] = num;
		}
	}

	cout << maxPath(0, 0) << endl;
}