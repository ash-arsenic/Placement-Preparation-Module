#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vl;

int main() 
{
	ll x, n;
	cin >> x >> n;
	
	multiset<ll> position, len;
	position.insert(0);
	position.insert(x);
	len.insert(x-0);
	while(n--) {
		ll z;
		cin >> z;

		position.insert(z);
		auto itr = position.find(z);
		ll pre = *prev(itr);
		ll nex = *next(itr);

		len.erase(len.find(nex - pre));
		len.insert(z - pre);
		len.insert(nex - z);
		cout << *len.rbegin() << " "; 		
	}
	return 0;
