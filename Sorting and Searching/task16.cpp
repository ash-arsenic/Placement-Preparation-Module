#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vl;

int main() 
{
	ll n;
	cin >> n;
	vl a(n);

	for(ll i=1; i<=n; i++)
		a[i-1] = i;

	ll c=0;
	int flag = 0;
	ll fg = 0;
	while(fg != n) {
		
		if(a[c] != -1) {
			flag++;
		}

		if(flag == 2) {
			cout << a[c] << " ";
			a[c] = -1;
			flag = 0;
			fg++;
		}
		c = (c+1)%n;
	}

	return 0;
