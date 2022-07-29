#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

int main()
{
    ll n, k;
    cin >> n >> k;

    vl a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());
    ll count = 0;

    ll i = 0, j = n-1;

    while(i < j) {
        if(a[i] + a[j] <= k) {
            count++;
            i++;
            j--;
        }
        else if(a[j] <= k) {
            j--;
            count++;
        }
        else
            j--;
    }

    if(i == j) {
        count++;
    }
    cout << count;
    cout << "\n" ;
    return 0;
}