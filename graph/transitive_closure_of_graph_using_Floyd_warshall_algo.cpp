#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> transitiveClosure(int n, vector<vector<int>> graph)
{
	vector<vector<int>> dist(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			dist[i][j] = graph[i][j];


	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == j) dist[i][j] = 1;
				else
					dist[i][j] = (dist[i][j] || (dist[i][k] && dist[k][j]));
			}

		}

	}
	return dist;
}

int main()
{
	int n;
	cin >> n;
	vector<vector<int>> matrix(n, std::vector<int>(n, -1));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> matrix[i][j];

	vector<vector<int>> ans = transitiveClosure(n, matrix);
	for (int i = 0; i < n; i++)
	{	for (int j = 0; j < n; j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}

}