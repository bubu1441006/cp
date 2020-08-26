#include <bits/stdc++.h>
using namespace std;
#define ll long long 

ll nChoosek (ll n, ll k)
{
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    ll result = n;
    for(ll i = 2; i <= k; ++i) 
    {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll n, k;
	while(cin >> n >> k)
	{
		if (n == 0 && k == 0) break;
	    cout << n << " things taken " << k << " at a time is " <<  nChoosek(n,k) << " exactly.\n";
	}
	return 0;
}