#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main()
{
    string s;
    cin >> s;
    int best = 0;
    int count = 0;
    char temp = s[0];
    for(int i=0; i<s.size(); i++) {
        if(s[i] != temp) {
            count = 0;
        }
        temp = s[i];
        count++;
        best = max(count, best);
    }

    cout << best;
    return 0;
}