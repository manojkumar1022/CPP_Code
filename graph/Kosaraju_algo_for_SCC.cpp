#include<bits/stdc++.h>
using namespace std;
#define pb push_back

void dfs1(int node, vector<int> adj[], vector<bool> &vis, stack<int> &st) {
	vis[node] = true;

	for (auto it : adj[node])
		if (!vis[it])
			dfs1(it, adj, vis, st);

	st.push(node);
}

void reverse1(int v, vector<int> adj[], vector<int> rev[]) {
	// vector<int> rev(v);
	for (int i = 0; i < v; i++) {
		for (auto j : adj[i]) {
			rev[j].pb(i);
		}
	}

}

void dfs2(int node, vector<int> adj[], vector<bool> &vis)
{
	cout << node << " ";
	vis[node] = true;
	for (auto it : adj[node]) {
		if (!vis[it]) {
			dfs2(it, adj, vis);
		}
	}
}



int kosaraju(int v, vector<int> adj[])
{
	vector<bool> vis(v, false);
	stack<int> st;
	for (int i = 0; i < v; i++)
	{
		if (!vis[i]) {
			dfs1(i, adj, vis, st);
		}
	}

	vector<int> rev[v];

	reverse1(v, adj, rev);

	vis.assign(v, false);
	int c = 0;
	while (st.empty() == false) {
		int curr = st.top();
		st.pop();
		if (!vis[curr]) {
			dfs2(curr, rev, vis);
			cout << endl;
			c++;
		}
	}
	return c;
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

	cout << kosaraju(V, adj) << endl;
}