#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

int main()
{
    long long int q, n;

    std::ios_base::sync_with_stdio(false);
    std::cin >> q;

    std::vector<long long int> computedDigits;

    long long int count = 0;
    long long int upperBound = 1LL << 60;
    long long int order = 10, previousOrder = 1;
    long long int digits = 1;

    computedDigits.push_back(0);
    while (count < upperBound) {
        count += (order - previousOrder) * digits;
        previousOrder = order;

        computedDigits.push_back(count);

        order *= 10;
        digits += 1;
    }

    long long int number, offset, digit, remainder;
    while (q--) {
        std::cin >> n;

        for (long long int i = 0; i < computedDigits.size(); ++i) {
            if ((i + 1 < computedDigits.size() && n < computedDigits[i + 1]) || (i + 1 == computedDigits.size())) {
                offset = n - computedDigits[i];
                number = offset / (i + 1) + (long long int) pow(10, i) - 1;
                if (offset % (i + 1))
                    number += 1;
                remainder = offset % (i + 1);
                if (remainder == 0) {
                    digit = number % 10;
                }
                else {
                    digit = number / (long long int) pow(10, i + 1 - remainder) % 10;
                }
                std::cout << digit << '\n';
                break;
            }
        }
}
    return 0;
}