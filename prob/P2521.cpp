#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 2e5 + 10;
const double eps = 1e-8;
inline int fcmp(double x, double y) { //x>y->1, x=y->0, x<y->-1
	if(fabs(x - y) < eps) return 0;
	else return x > y ? 1 : -1;
}
struct Point{
	int x, y;
	Point(){};
	Point(int a, int b): x(a), y(b) {}
	Point(Point a, Point b): x(b.x - a.x), y(b.y - a.y) {}
	friend Point operator + (const Point &a, const Point &b) {
		return Point(a.x + b.x, a.y + b.y);
	}
	friend Point operator - (const Point &a, const Point &b) {
		return Point(a.x - b.x, a.y - b.y);
	}
	friend bool operator == (const Point &a, const Point &b) {
		return fcmp(a.x, b.x) == 0 && fcmp(a.y, b.y == 0);
	}
	friend Point operator * (const double &a, const Point &b) {
		return Point(a * b.x, a * b.y);
	}
	friend Point operator * (const Point &a, const double &b) {
		return Point(a.x * b, a.y * b);
	}
	friend int operator * (const Point &a, const Point &b) {
		return a.x * b.y - a.y * b.x;
	}
	friend int operator & (const Point &a, const Point &b) {
		return a.x * b.x + a.y * b.y;
	}
	friend bool operator < (const Point &a, const Point &b) {
		return (a.x < b.x) || (a.x == b.x && a.y < b.y);
	}
	inline double len() {
		return sqrt(1.0 * x * x + 1.0 * y * y);
	}
} p[MAXN];
typedef Point Vec;
set<Point> top;
double len;
void insert(Point x) {
	auto r = top.lower_bound(x);
	auto l = r; l--;
	if((*l-x)*(*r-x)<0)return;
	len -= (*r - *l).len();
	while(l != top.begin()) {
		auto l_lst = l; l--;
		if(Vec(*l_lst, *l) * Vec(*l_lst, x) > 0) break;
		len -= (*l_lst - *l).len();
		top.erase(l_lst);
	}
	while(r != top.end()) {
		auto r_lst = r; r++;
		if(r == top.end()) break;
		if(Vec(*r_lst, x) * Vec(*r_lst, *r) > 0) break;
		len -= (*r_lst - *r).len();
		top.erase(r_lst);
	}
	top.insert(x);
	l = r = top.find(x);
	l--; r++;
	len += (x - *l).len() + (x - *r).len();
}

int n, Q;
struct Query{
	int opt, id;
} q[MAXN];
bool book[MAXN];
double ans[MAXN];
signed main() {
	freopen("tmp.in", "r", stdin);
	int a, b, c; scanf("%lld%lld%lld", &a, &b, &c);
	top.insert(Point(0, 0));
	top.insert(Point(a, 0));
	insert(Point(b, c));
	len = Point(b, c).len() + (Point(b, c) - Point(a, 0)).len();
	scanf("%lld", &n);
	for(int i = 1; i <= n; i++) scanf("%lld%lld", &p[i].x, &p[i].y);
	scanf("%lld", &Q);
	for(int i = 1; i <= Q; i++) {
		scanf("%lld", &q[i].opt);
		if(q[i].opt == 1) {
			scanf("%lld", &q[i].id);
			book[q[i].id] = true;
		}
	}
	for(int i = 1; i <= n; i++) if(!book[i]) insert(Point(p[i].x, p[i].y));
	for(int i = Q; i >= 1; i--) {
		if(q[i].opt == 2) {
			ans[i] = len;
		} else
			insert(Point(p[q[i].id].x, p[q[i].id].y));
	}
	for(int i = 1; i <= Q; i++) if(q[i].opt == 2) {
		printf("%.2lf\n", ans[i]);
	}
	return 0;
}