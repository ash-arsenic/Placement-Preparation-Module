#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

ll n;
ll sum = 0;
ll mini = INT_MAX;
vl nums, x;

void test()
{
    sum = 0;
    int j=0;
    for(int i=0; i<n; i++) {
        if(x[j] == i) {
            sum += nums[x[j]];
            j++;
        } else {
            sum -= nums[i];
        }
    }

    mini = min(abs(sum), mini);
}

void solve(int i)
{
    if(i == n) {
        test();
        return;
    }

    x.push_back(i);
    solve(i+1);
    x.pop_back();
    solve(i+1);
}

int main()
{
    cin >> n;

    for(ll i=0; i<n; i++)  {
        int t;
        cin >> t;
        nums.push_back(t);
    }

    solve(0);

    cout << mini;
    cout << "\n";
    return 0;
}