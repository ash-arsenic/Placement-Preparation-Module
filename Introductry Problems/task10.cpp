#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

int main()
{
    ll n;
    cin >> n;

    vl factors;
    ll num = 5;
    while(num <= n) {
        factors.push_back(num);
        num = num*5;
    }

    ll res = 0;
    for(ll gg : factors) {
        res += n/gg;
    }
    cout << res;
    return 0;
}