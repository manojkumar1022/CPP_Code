#include<bits/stdc++.h>
using namespace std;

void primeFactors(int n)
{
	for (int i = 2; i <= sqrt(n); i++)
	{

		if (n % i == 0)
		{
			while (n % i == 0)
			{
				n = n / i;
				// ct++;
				cout << i << " ";
			}
		}


	}

	if (n != 1)
		cout << n;
}

int main()
{
	int n = 36;
	primeFactors(n);
}