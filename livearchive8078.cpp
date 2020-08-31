#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string> 
using namespace std;
#define ll long long

int power(int x,int y){int res=1;while(y>0){if(y&1)res*=x;y>>=1;x*=x;}return res;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	
	string s;
	for(int tt = 1; tt <= t; tt++)
	{
		cin >> s;
		int n = s.size();
		
		vector<int> ans(n);
		for(int i = 0; i < n; i++)
		{
			if(s[i] == '}' || s[i] == ')' || s[i] == ']' || s[i] == '>') continue;
			
			stack<char> st;
			int len = 0;
			for(int j = i; j < n; j++)
			{
				if(s[j] == '(' || s[j] == '{' || s[j] == '[' || s[j] == '<')
					st.push(s[j]);
				else 
				{
					if(st.empty()) continue;
					
					char tmp = st.top();
					if(s[j] == ')' && tmp == '(') 
					{
						st.pop();
						if(st.empty()) len = max(len, j-i+1);
					}
					else if(s[j] == '}' && tmp == '{')
					{
						st.pop();
						if(st.empty()) len = max(len, j-i+1);
					}
					else if(s[j] == ']' && tmp == '[')
					{
						st.pop();
						if(st.empty()) len = max(len, j-i+1);
					}
					else if(s[j] == '>' && tmp == '<')
					{
						st.pop();
						if(st.empty()) len = max(len, j-i+1);
					}
					else break;
				} 
				
				ans[i] = len;
			}
		}
		
		cout << "Case " << tt << ":\n";
		for(int i : ans)
			cout << i << "\n";
	}
}