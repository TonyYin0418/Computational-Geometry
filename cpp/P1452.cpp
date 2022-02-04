#include <bits/stdc++.h>
#define int long long
using namespace std;
inline int fcmp(int x, int y) {
	if(abs(x - y) == 0) return 0;
	else return x > y ? 1 : -1;
}
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
		return !fcmp(x, b.x) && !fcmp(y, b.y);
	}
	int len() {
		return sqrt(x * x + y * y);
	}
	int sqr_len() {
		return x * x + y * y;
	}
};
typedef Point Vec;
inline bool cmp1(Vec a, Vec b) {
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}
inline int sqr_dis(Point a, Point b) {
	return (a - b).sqr_len();
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
int Get_Max(int n, Point *ch) {//传入convex-hull
	int ret = 0;
	ch[n] = ch[0];
	int j = 1;
	for(int i = 0; i < n; i++) {
		while((ch[i] - ch[j+1]) * (ch[i+1] - ch[j+1]) >
			  (ch[i] - ch[j  ]) * (ch[i+1] - ch[j  ]))
			j = (j + 1) % n;
		ret = max(ret, max(sqr_dis(ch[i], ch[j]), sqr_dis(ch[i+1], ch[j])));
	}
	return ret;
}
signed main() {
	cin >> n;
	for(int i = 0; i < n; i++) cin >> p[i].x >> p[i].y;
	int siz = Convex_hull_2d(n, p, convex);
	int ans = Get_Max(siz, convex);
	cout << ans << endl;
	return 0;
}