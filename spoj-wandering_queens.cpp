#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define y first 
#define x second

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	
	vector<int> diry = {1, -1, 1, -1, 0, 1, -1, 0};
	vector<int> dirx = {0, 0, 1, 1, 1, -1, -1, -1};

	while(t--)
	{
		int n, m;
		cin >> n >> m;
		
		vector<vector<char>> a(n, vector<char>(m, '.'));
		vector<vector<int>> dist(n, vector<int>(m, 0));
		
		int sy, sx;
		int fy, fx;
		
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				cin >> a[i][j];
				if(a[i][j] == 'S')
					sy = i, sx = j, dist[i][j] = 1; 
				// note that we are +1 for the distance to seperate from unvisted cells
				else if(a[i][j] == 'F')
					fy = i, fx = j;
			}
		}
		
		// do bfs
		queue<pair<int,int>> q;
		q.push({sy,sx});
		while(!q.empty())
		{
			pair<int,int> u = q.front();
			q.pop();
			
			// for every direction 
			for(int i = 0; i < 8; i++)
			{
				pair<int,int> tmp = u;
				
				// go in a specific direction
				tmp.y += diry[i];
				tmp.x += dirx[i];
				
				while(tmp.y >= 0 && tmp.y < n && tmp.x >= 0 && tmp.x < m && a[tmp.y][tmp.x] != 'X')
				{
					if(dist[tmp.y][tmp.x] == 0) // not visited cell
					{
						dist[tmp.y][tmp.x] = dist[u.y][u.x] + 1;
						q.push(tmp);
					}
					
					// if not going in the same direction
					else if(dist[tmp.y][tmp.x] != dist[u.y][u.x] + 1)
						break;
					
					// else keep going in the same direction
					tmp.y += diry[i];
					tmp.x += dirx[i];
				}
			}
		}
		
		// because we +1 in dist previously
		cout << dist[fy][fx] - 1 << "\n";
	}
}