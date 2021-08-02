#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define deb(x) cout<<#x<<": "<<x<<endl
#define test(x) cout<<"test: "<<x<<endl;


void allFactors(int n)
{

	// APPROACH 1 //          // T - O(n)
	// vector<int> ans;
	// ans.pb(1);
	// for (int i = 2; i <= n / 2; i++)
	// {
	// 	if (n % i == 0)
	// 		ans.pb(i);
	// }
	// if (n != 1)
	// 	ans.pb(n);

	// for (int i = 0; i < ans.size(); i++)
	// 	cout << ans[i] << " ";


	// APPROACH 2 // optimized one  		// T - O(sqrt(n))
	set<int> ans;

	for (int i = 1; i <= sqrt(n); i++)
	{
		if (n % i == 0)
			ans.insert(i);
		if (i != sqrt(n))
			ans.insert(n / i);
	}

	for (auto it = ans.begin(); it != ans.end(); it++)
		cout << *it << " ";

	// for (int i = 0; i < ans.size(); i++)
	// 	cout << ans[i] << " ";
}

int main()
{
	int n = 10;
	// cout << "hello";
	allFactors(n);
}