#include<bits/stdc++.h>
using namespace std;              // TC- O(1)  SC - O(1)

void solve(int dig, vector<string> place, string &s)
{
	switch (dig)
	{
	case 1:
	case 2:
	case 3: while (dig--) {
			s += place[0];
		}
		break;
	case 4: s += place[0];
		s += place[1];
		break;

	case 5: s += place[1];
		break;
	case 6:
	case 7:
	case 8:
		s += place[1];
		dig = dig % 5;
		while (dig--) {
			s += place[0];
		}
		break;
	case 9: s += place[0];
		s += place[2];
	}

}


string Roman_to_integer(int num)
{
	vector<string> one = {"I", "V", "X"};
	vector<string> ten = {"X", "L", "C"};
	vector<string> hundred = {"C", "D", "M"};
	vector<string> thousand = {"M"};

	string ans = "";
	int dig;
	dig = num / 1000;
	solve(dig, thousand, ans);

	num = num % 1000;
	dig = num / 100;
	solve(dig, hundred, ans);

	num = num % 100;
	dig = num / 10;
	solve(dig, ten, ans);
	num = num % 10;
	dig = num;
	solve(dig, one, ans);

	return ans;

}

int main()
{
	int x;
	cin >> x;
	cout << Roman_to_integer(x);
}