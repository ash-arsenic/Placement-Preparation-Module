/*  ______                         ____
   |             /\      |      | |    |     /\  \          /
   |            /  \     |      | |    |    /  \  \        /
   |   ___     /    \    |      | |____|   /    \  \      /
   |      |   /------\   |      | | \     /------\  \    /
   |      |  /        \  |      | |  \   /        \  \  /
   |______| /          \ |______| |   \ /          \  \/
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

int main()
{
    ll n;
    cin >> n;

    vl a;
    for(ll i=0; i<n; i++) {
        ll x; cin >> x;
        a.push_back(x);
    }

    ll sum = a[0], best = a[0];
    for(int i=1; i<n; i++) {
        sum = max(a[i], sum+a[i]);
        best = max(sum, best);
    }
    cout << best;
    cout << "\n";
    return 0;
}