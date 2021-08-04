#include<bits/stdc++.h>
using namespace std;
#define pb push_back

void dfsIterative(int node, vector<int> adj[], vector<bool> &vis, vector<int> &dfsStore)
{
	stack<int> st;
	st.push(node);
	// vis[node] = 1;


	while (!st.empty())
	{
		int cur = st.top();
		st.pop();

		if (!vis[cur]) {
			dfsStore.push_back(cur);
			vis[cur] = 1;

		}

		for (auto it : adj[cur])
		{
			if (!vis[it]) {
				st.push(it);
			}
		}
	}
}

void dfsOfGraph(int v, vector<int> adj[])
{
	vector<bool> vis(v, 0);
	vector<int> dfsStore;
	for (int i = 0; i < v; i++)
	{
		if (!vis[i])
			dfsIterative(i, adj, vis, dfsStore);
	}

	for (int i = 0; i < v; i++)
	{
		cout << dfsStore[i] << " ";
	}

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

	dfsOfGraph(V, adj);
}