#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;
#define ll long long 

ll power(ll x, unsigned ll y, ll p)  
{  
    ll res = 1;   
    x = x % p;
    if (x == 0) return 0;
  
    while (y > 0)  
    {  
        if (y & 1)  
            res = (res*x) % p;  
  
        y = y>>1;
        x = (x*x) % p;  
    }  
    return res;  
}  

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	// CHECK FOR:
	// OVERFLOW ?? 
	// OUT OF BOUNDS ??
	// DIVIDE 0 ??
	// CORNER CASES ??
	
	// NEVER RUSH TO SUBMIT
	
	ll x;
	unsigned ll y;
	ll p;
		
	while(cin >> x >> y >> p)
		cout << power(x,y,p) << "\n";
	
}
