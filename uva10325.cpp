#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll lcm(ll a, ll b) { return a * b / __gcd(a,b); }

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    ll n, m;
    while(cin >> n >> m)
    {
        vector<ll> a(m);
        for(ll i = 0; i < m; i++)
            cin >> a[i];
        
        ll ans = n;
        for(ll msk = 1; msk < (1 << m); msk++)
        {
            ll LCM = 1, bits = 0;
            for(ll i = 0; i < m; i++)
            {
                if(msk & (1 << i)) // if the i-th bits is set
                {
                    LCM = lcm(LCM, a[i]);
                    bits++;
                }
            }
            ll cur = n / LCM;
            if(bits & 1) ans -= cur;
            else ans += cur;
        }
        
        cout << ans << "\n";
    }
}