#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main()
{
    ll n;
    cin >> n;

    vector<ll> arr(n);
    for(int i=0; i<n-1; i++) {
        int a;
        cin >> a;
        arr[a-1] = 1;
    }

    for(int i=0; i<n; i++) {
        if(!arr[i]) {
            cout << i+1;
            break;
        }
    }
    return 0;
}