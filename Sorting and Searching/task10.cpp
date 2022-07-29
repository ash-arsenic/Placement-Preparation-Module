#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

int main()
{
    ll n;
    cin >> n;
    vl a(n);
    for(ll i=0; i<n; i++)   cin >> a[i];

    sort(a.begin(), a.end());
    ll c=1;

    for(ll i=0; i<n; i++) {
        if(a[i] > c) {
            cout << c;
            return 0;
        } else {
            c += a[i];
        }
    }
    cout << c;
    return 0;
}