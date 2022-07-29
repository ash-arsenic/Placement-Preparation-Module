#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

ll cnt = 0;

void queens_problem(int y, int n, int col[], int d1[], int d2[], vector<pair<int, int>> input)
{
    if(y == n) {
        cnt++;
        return;
    }

    for(int i=0; i<n; i++) {

        bool flag = false;
        for(auto p : input) {
            if(p.first == y && p.second == i) {
                flag = true;
            }
        }

        if(flag) {
            continue;
        }

        if(col[i] || d1[i+y] || d2[i-y+n-1])
            continue;
        col[i] = d1[i+y] = d2[i-y+n-1] = 1;
        queens_problem(y+1, n, col, d1, d2, input);
        col[i] = d1[i+y] = d2[i-y+n-1] = 0;
    }
}

int main()
{
    int n=8;
    vector<pair<int, int>> input;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            char ch;
            cin >> ch;
            if(ch == '*') {
                input.push_back(make_pair(i, j));
            }
        }
    }

    int col[n] = {0};
    int d1[2*n-1] = {0};
    int d2[2*n-1] = {0};
    queens_problem(0, n, col, d1, d2, input);

    cout << cnt;
    cout << "\n";
    return 0;
}