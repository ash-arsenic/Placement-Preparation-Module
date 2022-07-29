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
    vl b, c;
    for(int i=0; i<n; i++) {
        long t, q;
        cin >> t >> q;
        b.push_back(t);
        c.push_back(q);
        a.push_back((make_pair(t, q)));
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());


    ll i=0, j=0, cont = 0, m = 0;
    while(i < n || j < n) {
        if(i < n && b[i] < c[j]) {
            cont++;
            i++;
        } else{
            cont--;
            j++;
        }
        m = max(cont, m);
    }
    cout << m;
    cout << "\n" ;
    return 0;
}