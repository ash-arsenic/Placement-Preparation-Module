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
    ll n, sum;
    cin >> n >> sum;
    vector<pair<ll, ll>> a;
    for(ll i=0; i<n; i++) {
        ll x; cin >> x;
        a.push_back(make_pair(x, i+1));
    }

    sort(a.begin(), a.end());
    ll i=0, j=n-1;
    bool found = false;
    while(i<j){
        if(a[i].first + a[j].first > sum)
            j--;
        else if(a[i].first + a[j].first < sum)
            i++;
        else {
            found = true;
            break;
        }
    }
    if(found)
        cout << a[i].second << " " << a[j].second;
    else
        cout << "IMPOSSIBLE";
    cout << "\n";
    return 0;
}