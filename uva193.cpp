#include <iostream>
#include <vector>
using namespace std;

int m, n, k, u, v;
vector<vector<int>> adj;
vector<int> bestb, curb;
vector<bool> curcolor;

bool canbeblack(int cur)
{
	for(int neighbor : adj[cur])
		if(neighbor == cur || curcolor[neighbor])
			return false;
	return true;
}

void backtrack(int cur)
{
	if(bestb.size() < curb.size())
		bestb = curb;
	if(cur == n)
		return;
	int maxposblack = n - cur;
	// pruning: even if all next tree is black, we won't have a new best
	if(maxposblack + curb.size() <= bestb.size()) 
		return;

	//minimize depth, avoid big search tree
	for(int i = cur; i < n; i++)
	{
		if(canbeblack(i)) // switch to black
		{
			// do .. recursion ... undo -> backtracking 
			curb.push_back(i);
			curcolor[i] = 1;

			backtrack(i + 1);

			curb.pop_back();
			curcolor[i] = 0;
		}
	}

	// no need to call white since the loop already did it
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	cin >> m;
	while(m--)
	{
		cin >> n >> k;
		adj.clear(); adj.resize(n);
		bestb.clear();
		curb.clear();
		curcolor.clear(); curcolor.resize(n);

		for(int i = 0; i < k; i++)
		{
			cin >> u >> v; 
			u--; v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		backtrack(0);
		cout << bestb.size() << "\n";
		for(int i = 0; i < bestb.size(); i++)
		{
			if(i) cout << " ";
			cout << bestb[i] + 1;
		}
		cout << "\n";
	}
}
