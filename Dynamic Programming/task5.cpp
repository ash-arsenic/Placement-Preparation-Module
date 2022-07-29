#include<bits/stdc++.h>
#define INF INT_MAX
#define MOD (long long) 1e9+7

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

vl values(1000001);

ll count(ll n, ll cnt) {
	if(n == 0) {
		return cnt;
	}
	if(values[n]) {
		return values[n];
	}
	ll a=n;
	ll f=a%10;
	while(a!=0) {
		f = max(f, a%10);
		a/=10;
	}

	ll d = count(n-f, cnt+1);
	values[n] = d;
	return d;
}

int main() 
{
	ll n;
	cin >> n;
	cout << count(n, 0);

	return 0;
