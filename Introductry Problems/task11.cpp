#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

int main()
{
    ll t;
    cin >> t;

    while(t--) {
        ll a, b;
        cin >> a >> b;

        while(a%3 != 0 && b%3 != 0) {
            if((a == 2 && b == 1) || (a == 1 && b == 2))
                break;

            //cout << a << " " << b << "\n";
            if(a > b) {
                a -= 2;
                b -= 1;
            } else {
                a -= 1;
                b -= 2;
            }

        }
        if((a == 2 && b == 1) || (a == 1 && b == 2))
            cout << "YES\n";
        else if(a%3 == 0 && b%3 == 0) {
            if((a > b && (ceil(a/2) <= b)) || (b > a && (ceil(b/2) <= a))) {
                cout << "YES\n";
            } else if(a == b){
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
        else
            cout << "NO\n";
    }

    cout << "\n";
    return 0;
}