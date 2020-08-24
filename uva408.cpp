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
	int step, mod;
	while(scanf("%d%d", &step, &mod) == 2)
	{
		if(__gcd(step, mod) == 1)
			printf("%10d%10d    Good Choice\n\n", step, mod); 
		else
			printf("%10d%10d    Bad Choice\n\n", step, mod); 
	}		
}
