#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

int main()
{
    int n;
    cin >> n;

    for(ll i=0; i<pow(2, n); i++) {
        vi bin;
        for(int k=n-1; k>=0; k--) {
            if(i&(1<<k))    bin.push_back(1);
            else    bin.push_back(0);
        }

        vi gray;
        gray.push_back(bin[0]);

        for(int i=0; i<bin.size()-1; i++) {
            gray.push_back(bin[i] ^ bin[i+1]);
        }

        for(int l : gray)
            cout << l;
        cout << "\n";
    }

    cout << "\n";
    return 0;
}