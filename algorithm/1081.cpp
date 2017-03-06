#include<iostream>

using namespace std;
#define INF 999999999
#define ll long long
 
ll g(ll x) {
    if (x < 10) return x;
    return g(x / 10) + g(x % 10);
}
ll f(ll x) {
    if (x < 10) return x*(x + 1) / 2;
    if (x % 10 == 9) return 45 * (x / 10 + 1) + f(x / 10) * 10;
    else return g(x) + f(x - 1);
}
int main()
{
    ll L, U;
    cin >> L >> U;
    cout << f(U) - f(L - 1) << endl;
}
