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
    ll mean = 0;
    for(ll i=0; i<n; i++) {
        ll x; cin >> x;
        a.push_back(x);
        mean += x;
    }
    sort(a.begin(), a.end());
    ll act = a[n/2];
    ll count = 0;
    for(ll i=0; i<n; i++) {
        count += abs(a[i] - act);
    }
    cout << count;
    cout << "\n";
    return 0;
}