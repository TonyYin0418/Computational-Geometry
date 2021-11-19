#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 3010;
struct Point{
	int x, y;
	Point(){};
	Point(int a, int b): x(a), y(b) {}
	Point(Point a, Point b): x(b.x - a.x), y(b.y - a.y) {}
	Point operator + (const Point &b) {
		return Point(x + b.x, y + b.y);
	}
	Point operator - (const Point &b) {
		return Point(x - b.x, y - b.y);
	}
	int operator * (const Point &b) {
		return x * b.y - y * b.x;
	}
	int operator & (const Point &b) {
		return x * b.x + y * b.y;
	}
	bool operator == (const Point &b) {
		return x == b.x && y == b.y;
	}
};
inline bool cmp1(Point a, Point b) {
	return (a.x < b.x) || (a.x == b.x && a.y < b.y);
}
inline bool cmp2(Point &a, Point &b) {
	return a * b > 0;
}
int n, ans;
Point p[N], p2[N];
signed main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> p[i].x >> p[i].y;
	sort(p + 1, p + n + 1, cmp1); //坐标排序
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for(int j = i + 1; j <= n; j++) p2[++cnt] = p[j] - p[i];
		sort(p2 + 1, p2 + cnt + 1, cmp2); //极角排序
		int sum_x = 0, sum_y = 0;
		for(int j = 1; j <= cnt; j++)
			sum_x += p2[j].x, sum_y += p2[j].y;
		for(int j = 1; j <= cnt; j++) {
			sum_x -= p2[j].x, sum_y -= p2[j].y;
			ans += p2[j] * Point(sum_x, sum_y);
		}
	}
	if(ans & 1) printf("%lld.5\n", ans / 2);
	else printf("%lld.0\n", ans / 2);
	return 0;
}