//Accepted

#include <bits/stdc++.h>
#define int long long
using namespace std;
struct Point{
	double x, y;
	Point(){};
	Point(int a, int b): x(a), y(b) {}
	Point(Point a, Point b): x(b.x - a.x), y(b.y - a.y) {}
	Point operator + (const Point &b) {
		return Point(x + b.x, y + b.y);
	}
	Point operator - (const Point &b) {
		return Point(x - b.x, y - b.y);
	}
	double operator * (const Point &b) {
		return x * b.y - y * b.x;
	}
	double operator & (const Point &b) {
		return x * b.x + y * b.y;
	}
	bool operator == (const Point &b) {
		return x == b.x && y == b.y;
	}
};
typedef Point Vec;
inline bool cmp1(Vec a, Vec b) {
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}
inline bool check(Point s1, Point s2, Point p) {
	return Vec(s2, s1) * Vec(s1, p) > 0;
}
int Convex_hull_2d(int n, Point *p, Point *ret) {
	sort(p, p + n, cmp1);
	int top = -1;
	for (int i = 0; i < n; i++) {
		while (top > 0 && !check(ret[top], ret[top - 1], p[i]))
			top--;
		ret[++top] = p[i];
	}
	int k = top;
	for (int i = n - 2; i >= 0; i--) {
		while (top > k && !check(ret[top], ret[top - 1], p[i]))
			top--;
		ret[++top] = p[i];
	}
	return top;
}
const int MAXN = 50010;
int n;
Point p[MAXN], convex[MAXN];
double Get_Max(int n, Point *ch) {
	double ret = 0;
	ch[n] = ch[0];
	int j = 1, k = 2;
	for(int i = 0; i < n; i++) {
		while(Vec(ch[i], ch[j]) * Vec(ch[i], ch[k]) <
			  Vec(ch[i], ch[j]) * Vec(ch[i], ch[k+1]))
			k = (k + 1) % n;
		while(Vec(ch[i], ch[j]) * Vec(ch[i], ch[k]) <
			  Vec(ch[i], ch[j+1]) * Vec(ch[i], ch[k]))
			j = (j + 1) % n;
		ret = max(ret, Vec(ch[i], ch[j]) * Vec(ch[i], ch[k]));
	}
	return ret;
}
signed main() {
	while(cin >> n) {
		if(n == -1) break;
		for(int i = 0; i < n; i++) cin >> p[i].x >> p[i].y;
		if(n <= 2) { cout << "0.00\n"; continue; }
		int siz = Convex_hull_2d(n, p, convex);
		if(siz <= 2) { cout << "0.00\n"; continue; }
		double ans = Get_Max(siz, convex);
		printf("%.2lf\n", ans/2.0);
	}
	return 0;
}