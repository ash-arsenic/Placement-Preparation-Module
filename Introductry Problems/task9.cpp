#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

int main()
{
    ll n;
    cin >> n;
    ll res = 1;

    for(ll i=0; i<n; i++) {
        res = (res * 2) % 1000000007;
    }
    cout << res;
    return 0;
}