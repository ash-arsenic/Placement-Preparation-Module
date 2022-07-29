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
    vector<pair<ll, ll>> a;

    for(ll i=0; i<n; i++) {
        ll t, q;
        cin >> t >> q;
        a.push_back(make_pair(q, t));
    }

    sort(a.begin(), a.end());

    ll c=1, m=a[0].first;
    for(ll i=1; i<n; i++) {
        if(a[i].second >= m) {
            c++;
            m = a[i].first;
        }
    }
    cout << c;
    cout << "\n";
    return 0;
}