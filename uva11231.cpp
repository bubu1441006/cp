#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;
#define ll long long 

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	// CHECK FOR:
	// OVERFLOW ?? 
	// OUT OF BOUNDS ??
	// DIVIDE 0 ??
	// CORNER CASES ??
	
	// NEVER RUSH TO SUBMIT
	
	ll n, m, c;
	while(cin >> n >> m >> c && n != 0)
		cout << ((n-8+1) * (m-8+1) + c )/ 2 << "\n";
	
}
