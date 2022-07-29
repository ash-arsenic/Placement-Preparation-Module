#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

int main()
{
    ll n;
    cin >> n;

    vl per;
    for(int i=2; i<=n; i+=2) {
        per.push_back(i);
    }
    for(int i=1; i<=n; i+=2){
        per.push_back(i);
    }
    if(n < 4 && n != 1)
        cout << "NO SOLUTION";
    else {
        for(ll in : per)
            cout << in << " ";
    }

    return 0;
}