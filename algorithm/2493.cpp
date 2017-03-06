#include <cstdio>
#include <stack>
#include <utility>
using namespace std;
int n, k;
stack<pair<int, int> > s;
int main() {
    scanf("%d", &n);
    for (int i = 1; i<=n; i++) {
        scanf("%d", &k);
        while (!s.empty()) {
            if (s.top().second > k){
                printf("%d ", s.top().first);
                break;
            }
            s.pop();
        }
        if(s.empty())
        	printf("0 ");
        s.push(make_pair(i, k));
    }
}