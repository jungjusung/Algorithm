#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
int A[2001];
int B[2001];
int cache[2001][2001];

int card(int i, int j) {
  if (i == N || j == N)
    return 0;
  //기저사례 3, 남는 카드카드가 더이상 없다면 종료
  int &ret = cache[i][j];
  if (ret != -1)
    return ret;
  ret=max(card(i+1,j),card(i+1,j+1));
  // 규칙 1 따라서 재귀함수 반복
  if (A[i] > B[j]) {
    ret = max(card(i, j+1) + B[j],ret);
  } // 규칙 2 따라서 재귀함수

  return ret;
}
int main(void)
{
    cin>>N;
    memset(cache,-1,sizeof(cache));
    for(int i=0;i<N;i++)
    {
        cin>>A[i];
    }
    for(int i=0;i<N;i++)
    {
        cin>>B[i];

    }
    cout<<card(0,0)<<endl;


}