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

    string pre = "";
    string mid = "";
    string post = "";

    for(int i=0; i<str.size(); i++) {
        if(str[i] == str[i+1]) {
            pre.push_back(str[i]);
            post.push_back(str[i+1]);
            i++;
        } else {
            mid.push_back(str[i]);
        }
    }
    if(mid.size() > 1)
        cout << "NO SOLUTION";
    else {
        cout << pre;
        cout << mid;
        for(int i=post.size()-1; i>=0; i--)
            cout << post[i];
    }
    cout << "\n";
    return 0;
}