#include<bits/stdc++.h>
using namespace std;

class point
{
public:
	double x;
	double y;
};

float crossProduct(point a, point b)
{
	return a.x * b.y - a.y * b.x;
}

float areaOfPolygon(vector<point> p, int n)
{
	float sum = 0.0;
	for (int i = 0; i < n; i++)
	{
		sum = sum + crossProduct(p[i], p[(i + 1) % n]);
	}
	return abs(sum) / 2;
}

int main()
{
	int n;
	cin >> n;
	vector<point> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i].x >> v[i].y;
	}

	cout << areaOfPolygon(v, n);

}
