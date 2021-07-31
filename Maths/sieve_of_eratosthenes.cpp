#include<bits/stdc++.h>
using namespace std;

void PrintPrime(int n)       /////       T- O(n*log(logn))
{
	vector<int> prime(n + 1, 1);

	prime[0] = 0;
	prime[1] = 0;

	for (int i = 2; i <= sqrt(n); i++)
	{
		if (prime[i]) {
			for (int j = 2; i * j <= n; j++)
				prime[i * j] = 0;
		}
	}
	// cout << "e";
	for (int i = 0; i <= n; i++)
	{
		if (prime[i])
			cout << i << " ";
	}
}

int main()
{
	int n;
	// cin>>n;
	n = 29;
	PrintPrime(n);
}