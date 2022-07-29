#include<bits/stdc++.h>
#define INF INT_MAX

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

const unsigned int MAX = 505;
const unsigned int MOD = 1e9+7;

int main()
{
	int n;
	cin >> n;
	int a[n];
	ll sum=0;
	for(int i=0; i<n; i++)	{
		cin >> a[i];
		sum += a[i];
	}

	vi res(sum+1);
	res[0] = 1;

	for(int i=0; i<n; i++) {
		for(int j=sum; j>=1; j--) {
			if(a[i] <= j && res[j-a[i]])
				res[j] = res[j-a[i]];
		}
	}

	int cnt = 0;
	for(int i=1; i<sum+1; i++) 
		if(res[i])
			cnt++;
	
	cout << cnt << "\n";
	for(int i=1; i<sum+1; i++) 
		if(res[i])
			cout << i << " ";
	return 0;
