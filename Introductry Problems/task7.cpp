#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

int main()
{
    ll k;
    cin >> k;
    for (ll n = 1; n <= k; n++)
    {
        cout << n * n * (n * n - 1) / 2 - 4 * (n - 1) * (n - 2) << endl;
    }

    return 0;
}