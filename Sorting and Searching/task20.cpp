#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
 
int main() 
{
	ll n;
	cin >> n;
	vector<pair<pair<ll, ll>, ll>> a;
	for(int i=0; i<n; i++) {
		ll x, y;
		cin >> x >> y;
		a.push_back({{x, y}, i});
	}

	vector<int> room(n);
	sort(a.begin(), a.end());
	int id = 1;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> r;
	for(int i=0; i<n; i++) {
		if(r.size() == 0) {
			room[a[i].second] = id++;
			r.push(make_pair(a[i].first.second, id-1));
		} else {
			if(a[i].first.first > r.top().first) {
				room[a[i].second] = r.top().second;
				int d = r.top().second;
				r.pop();
				r.push(make_pair(a[i].first.second, d));
			} else {
				room[a[i].second] = id++;
				r.push(make_pair(a[i].first.second, id-1));
			}
		}
 	}

 	cout << id-1 << "\n";
 	for(auto i : room)
 		cout << i << " ";
	return 0;
