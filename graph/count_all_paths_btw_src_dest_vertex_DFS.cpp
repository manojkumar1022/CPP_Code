#include<bits/stdc++.h>
using namespace std;
#define pb push_back
void path_finder(int src, int dest, int &cc, vector<int> adj[], vector<bool> vis)
{
	vis[src] = 1;
	if (src == dest)
		cc++;

	for (auto it : adj[src])
	{
		if (!vis[it])
			path_finder(it, dest, cc, adj, vis);
	}
}


int allPaths(int v, int src, int dest, vector<int> adj[])
{
	vector<bool> vis(v, 0);
	int cc = 0;
	path_finder(src, dest, cc, adj, vis);
	return cc;
}

int main()

{
	int V, E;
	cin >> V >> E;
	vector<int> adj[V];
	for (int i = 0; i < E; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
	}

	int src, dest;
	cin >> src >> dest;
	cout << allPaths(V, src, dest, adj);
}
