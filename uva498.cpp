#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string> 
using namespace std;

int power(int x, int y)
{
	int res = 1;
	while(y > 0)
	{
		if(y & 1) res *= x;
		y >>= 1;
		x *= x;
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	string in;
	stringstream line;
	
	while(getline(cin, in))
	{
		vector<int> p, v;
		int n;
		
		line.clear();
		line.str(in);
		while(line >> n)
			p.push_back(n);
			
		line.clear();
		getline(cin, in);
		line.str(in);
		while(line >> n)
			v.push_back(n);
		
		int c = (int)p.size();
		for(int i = 0; i < v.size(); i++)
		{
			n = 0;
			for(int j = 0; j < c; j++)
				n += p[c-1-j] * power(v[i],j);
			if(i) cout << " ";
			cout << n; 
		}
		cout << "\n";
	}
}