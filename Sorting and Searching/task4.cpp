#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

ll binary_search(vl a, ll start, ll end, ll key) {
    if(start > end)
        return -1;
    int mid = (start + end)/2;
    if(a[mid] == key) {
        return mid;
    } else if(a[mid] > key) {
        return binary_search(a, start, mid-1, key);
    } else {
        return binary_search(a, mid+1, end, key);
    }
}

int main()
{
    ll n, m;
    cin >> n >> m;

    multiset<int> a;
    for(int i=0; i<n; i++)  {
        ll k;
        cin >> k;
        a.insert(k);
    }
    ll k;
    for(int i=0; i<m; i++) {
        cin >> k;
        auto it = a.upper_bound(k);
        if(it == a.begin())
            cout << -1 << "\n";
        else {
            cout << *(--it) << "\n";
            a.erase(it);
        }

    }

    cout << "\n" ;
    return 0;
}