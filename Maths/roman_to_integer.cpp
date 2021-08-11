#include<bits/stdc++.h>
using namespace std;

int Roman_2_integer(string s)
{
	unordered_map<char, int> mp;
	mp['I'] = 1;
	mp['V'] = 5;
	mp['X'] = 10;
	mp['L'] = 50;
	mp['C'] = 100;
	mp['D'] = 500;
	mp['M'] = 1000;

	int sum = 0;
	for (int i = 0; i < s.size() - 1; i++)
	{
		if (mp[s[i]] >= mp[s[i + 1]])
			sum += mp[s[i]];
		else
			sum -= mp[s[i]];
	}

	sum += mp[s[s.size() - 1]];
	return sum;
}

int main()
{
	string s;
	cin >> s;
	cout << Roman_2_integer(s);
}