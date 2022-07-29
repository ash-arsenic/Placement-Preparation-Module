#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

int main()
{
    ll n;
    cin >> n;

    vl arr(n);
    for(ll i=0; i<n; i++)  cin >> arr[i];

    ll count = 0;
    for(ll i=1; i<n; i++) {
        if(arr[i] < arr[i-1]) {
            count += arr[i-1]-arr[i];
            arr[i] = arr[i-1];
        }
    }

    cout << count;
    return 0;
}