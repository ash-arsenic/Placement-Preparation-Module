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
    for(int i=0; i<n; i++) {
        ll t;
        cin >> t;
        a.push_back(t);
    }

    sort(a.begin(), a.end());
    ll count = 1;
    ll prev = a[0];
    for(int i=1; i<n; i++) {
        if(prev == a[i])
            continue;
        count++;
        prev = a[i];
    }

    cout << count;
    cout << "\n" ;
    return 0;
}