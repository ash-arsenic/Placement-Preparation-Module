#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

int main()
{
    string str;
    cin >> str;

    sort(str.begin(), str.end());
    vector<string> res;
    do {
        string ss = "";
        for(char gg : str) {
            ss.push_back(gg);
        }
        res.push_back(ss);
    } while(next_permutation(str.begin(), str.end()));

    cout << res.size() << "\n";
    for(string gg : res)
        cout << gg << "\n";

    cout << "\n";
    return 0;
}