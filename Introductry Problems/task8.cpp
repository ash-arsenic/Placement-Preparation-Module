#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    cin >> n;

    vector<long long> first;
    vector<long long> second;

    long long sum = (n*(n+1))/2;
    if(sum & 1)
        cout << "NO";
    else {
        cout << "YES\n";

        long long one = n;
        long long two = 0;
        first.push_back(n);

        for(long long i=n-1; i>=1; i--) {
            if(one < two) {
                first.push_back(i);
                one += i;
            } else {
                two += i;
                second.push_back(i);
            }
        }

        cout << first.size() << "\n";
        for(long long gg : first) {
            cout << gg << " ";
        }

        cout << "\n" << second.size() << "\n";
        for(long long gg : second) {
            cout << gg << " ";
        }
    }

    return 0;
}