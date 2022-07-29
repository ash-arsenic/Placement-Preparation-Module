#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

void toh(int n, int a, int b, int c) {

    if(n==1){
        cout << a << " " << b << "\n";
        return;
    }

    toh(n-1, a, c, b);
    cout << a << " " << b << "\n";
    toh(n-1, c, b, a);
}

int main()
{
    int n;
    cin >> n;
    cout << pow(2, n)-1 << "\n";

    toh(n, 1, 3, 2);
    cout << "\n";
    return 0;
}