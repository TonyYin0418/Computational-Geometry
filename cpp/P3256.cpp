#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
const int MAXN = 1e4 + 10;
const double pi = 3.1415926535898;
const double eps = 1e-18;
inline int sgn(double x) {
	if(fabs(x) < eps) return 0;
	else return x > 0 ? 1 : -1;
}
inline int fcmp(double x, double y) {
	if(fabs(x - y) < eps) return 0;
	else return x > y ? 1 : -1;
}
struct Point{
	double x, y;
	Point(){};
	Point(double a, double b): x(a), y(b) {}
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
	friend double operator * (const Point &a, const Point &b) {
		return a.x * b.y - a.y * b.x;
	}
	friend double operator & (const Point &a, const Point &b) {
		return a.x * b.x + a.y * b.y;
	}
	friend Point operator / (const Point &a, const double &b) {
		return Point(a.x / b, a.y / b);
	}
	friend bool operator < (const Point &a, const Point &b) {
		return (a.x < b.x) || (a.x == b.x && a.y < b.y);
	}
	inline double len() {
		return sqrt(1.0 * x * x + 1.0 * y * y);
	}
	friend double area(Point &a, Point &b, Point &c) {
		return (b - a) * (c - a) / 2.0;
	}
} in[MAXN], p[MAXN], convex[MAXN];
typedef Point Vec;
struct Line{
	Point s, t;
	vector<int> id;
	Line() {};
	Line(Point a, Point b) : s(a), t(b) {}
	Line(Point a, Point b, vector<int> c) : s(a), t(b), id(c) {}
	double ang() { return atan2((t - s).y, (t - s).x); };
	Line(double a, double b, double c) { //ax + by + c = 0
		if(sgn(a) == 0) s = Point(0, -c/b), t = Point(1, -c/b);
		else if(sgn(b) == 0) s = Point(-c/a, 0), t = Point(-c/a, 1);
		else s = Point(0, -c/b), t = Point(1, (-c-a)/b);
	}
	friend bool parallel(const Line &A, const Line &B) {
		return sgn((A.s - A.t) * (B.s - B.t)) == 0;
	}
	friend bool Calc_intersection(const Line &A, const Line &B, Point &res) {
		if(parallel(A, B)) return false;
		double s1 = (B.t - B.s) * (B.s - A.s);
		double s2 = (B.t - B.s) * (A.t - A.s);
		res = A.s + (A.t - A.s) * (s1 / s2);
		return true;
	}
} L[MAXN];
inline bool cmp(Line A, Line B) {
	//?????????????????????????????????????????????
	if(!sgn(A.ang() - B.ang())) return (A.t - A.s) * (B.t - A.s) > 0;
	return A.ang() < B.ang();
}
void Halfplane_unique(int &n, Line *hp) {
	int m = 0;
	for(int i = 0; i < n - 1; i++) {
		if(sgn(hp[i].ang() - hp[i + 1].ang()) == 0) continue;
		hp[m++] = hp[i];
	}
	hp[m++] = hp[n - 1];
	n = m;
}
int que[MAXN], st, ed;
bool Halfplane_intersection(int n, Line *hp, Point *p) {
	if(n < 3) return false;
	sort(hp, hp + n, cmp);
	Halfplane_unique(n, hp);
	st = 0; ed = 1;
	que[0] = 0; que[1] = 1;
	if(parallel(hp[0], hp[1])) return false;
	Calc_intersection(hp[0], hp[1], p[1]);
	for(int i = 2; i < n; i++) {
		while(st < ed &&
			  sgn((hp[i].t - hp[i].s) * (p[ed] - hp[i].s)) < 0)
			ed--;
		while(st < ed &&
			  sgn((hp[i].t - hp[i].s) * (p[st + 1] - hp[i].s)) < 0)
			st++;
		que[++ed] = i;
		if(parallel(hp[i], hp[que[ed - 1]])) return false;
		Calc_intersection(hp[i], hp[que[ed - 1]], p[ed]);
	}
	while(st < ed &&
		  sgn((hp[que[st]].t - hp[que[st]].s) * (p[ed] - hp[que[st]].s)) < 0)
		ed--;
	while(st < ed &&
		  sgn((hp[que[ed]].t - hp[que[ed]].s) * (p[st + 1] - hp[que[ed]].s)) < 0)
		st++;
	if(st + 1 >= ed) return false;
	return true;
}
signed main() {
	int n, x[MAXN], v[MAXN], N = 0;
	map<pair<int, int>, vector<int> > mp;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> x[i];
	for(int i = 1; i <= n; i++) cin >> v[i];

	for(int i = 1; i <= n; i++) mp[make_pair(x[i], v[i])].push_back(i);
	L[N++] = Line(Point(0, 1), Point(0, 0));
	L[N++] = Line(Point(0, 0), Point(1, 0));
	for(auto it = mp.begin(); it != mp.end(); it++) {
		pair<int, int> tmp = it -> first;
		L[N++] = Line(Point(0, tmp.first),
					  Point(1, tmp.first+tmp.second), it -> second);
	}

	Halfplane_intersection(N, L, p);

	int ans[MAXN], cnt_ans = 0;
	for(int i = st + 1; i <= ed; i++) {
		for(int j = 0; j < L[que[i]].id.size(); j++) {
			ans[cnt_ans++] = L[que[i]].id[j];
		}
	}
	sort(ans, ans + cnt_ans);
	cout << cnt_ans << endl;
	for(int i = 0; i < cnt_ans; i++) cout << ans[i] << " "; cout << endl;
	return 0;
}