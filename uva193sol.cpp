#include <bits/stdc++.h>
using namespace std;

#define all(v)			((v).begin()), ((v).end())
#define sz(v)			((int)((v).size()))
#define clr(v, d)		memset(v, d, sizeof(v))
#define rep(i, v)		for(int i=0;i<sz(v);++i)
#define lp(i, n)		for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)	for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)	for(int i=(j);i>=(int)(n);--i)
typedef long long ll;

enum Color { white, black };

int n, m;
vector< vector<int> > adjList;

vector<int> bestBlacks, curBlacks;
vector<Color> curColor;

bool canBeBlack(int cur)
{	// Neighbors must be white
	for(auto nei : adjList[cur])
	{
		if (nei == cur || curColor[nei] == black)	// handle self loops
			return false;
	}
	return true;
}

// Maximum Independent Set is NP-complete
// 2^100 = TLE ... note very weak test cases, it will pass
void backtrack_1(int cur)
{
	if (cur == n)	// marked all?
	{
		if (bestBlacks.size() < curBlacks.size())
			bestBlacks = curBlacks;
		return ;
	}
	backtrack_1(cur+1);		// leave it white

	if (canBeBlack(cur))	// switch to black
	{	// do...rec...undo
		curColor[cur] = black;
		curBlacks.push_back(cur);

		backtrack_1(cur+1);

		curBlacks.pop_back();
		curColor[cur] = white;
	}
}

void backtrack_2(int cur)
{
	if (cur == n)	// marked all?
	{
		if (bestBlacks.size() < curBlacks.size())
			bestBlacks = curBlacks;
		return ;
	}

	int max_possible_blacks = n - cur;

	if(max_possible_blacks + curBlacks.size() <= bestBlacks.size())
		return;	// pruning: even if all next is black, we won't do well

	if (canBeBlack(cur))	// switch to black
	{	// do...rec...undo
		curColor[cur] = black;
		curBlacks.push_back(cur);

		backtrack_2(cur+1);

		curBlacks.pop_back();
		curColor[cur] = white;
	}

	// optimization: let the black calls be first, they help pruning happens more
	// Tip: order of tracking calls matter alot when you have prunings
	backtrack_2(cur+1);		// leave it white
}

// max depth = max # blacks
void backtrack_3(int cur)
{
	if (bestBlacks.size() < curBlacks.size())
		bestBlacks = curBlacks;	// you have to check earlier..you may not reach cur = n

	if (cur == n)
		return ;

	int max_possible_blacks = n - cur;

	if(max_possible_blacks + curBlacks.size() <= bestBlacks.size())
		return;	// pruning: even if all next is black, we won't do well

	// Minimize depth: avoid big search tree
	for(int i = cur; i < n; ++i)
	{
		if (canBeBlack(i))	// switch to black
		{	// do...rec...undo
			curColor[i] = black;
			curBlacks.push_back(i);

			backtrack_3(i+1);

			curBlacks.pop_back();
			curColor[i] = white;
		}
	}
	// no need to call specific white, loop do so
}

// What else?
// Trick 1: randomization
// Instead of following normal order...randomize the order
// E.g. use order: 5 2 0 1 3 4

// Trick 2: Greedy order
// Sort nodes order based on its degree: Less degree first

// More: run several randomization, each for few recursion steps...and have initial bound for answer
// Then do Trick 1 again

// As N = 100, we can use bits to represents states...and check for canBeBlack

// Have some good ordering, use DP with last 20 nodes, and use backtracking with n-20 nodes

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.txt", "rt", stdin);
#endif

	int cases;

	cin>>cases;

	lp(cc, cases)
	{
		cin>>n>>m;

		adjList.clear();
		adjList.resize(n);
		curBlacks.clear();
		bestBlacks.clear();
		curColor = vector<Color>(n, white);

		lp(i, m)
		{
			int f, t;

			cin>>f>>t;
			--f, --t;

			adjList[f].push_back(t);
			adjList[t].push_back(f);
		}
		backtrack_3(0);	// no need to handle disconnected components

		cout<<bestBlacks.size()<<"\n";

		string space = "";
		for(auto x : bestBlacks)
			cout<<space<<x+1, space = " ";
		cout<<"\n";
	}

	return 0;
}