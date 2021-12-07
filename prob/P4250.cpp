#include <bits/stdc++.h>
using namespace std;
const int MAXN = 30000;
const double pi = 3.1415926535898;
const double eps = 1e-8;
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
struct Line{
	Point s, t;
	Line() {};
	Line(Point a, Point b) : s(a), t(b) {}
	double ang() { return atan2((t - s).y, (t - s).x); };
	Line(double A, double B, double C) { //ax + by + c = 0
        if(sgn(B) == 0) s = Point(-C/A,0), t = Point(-C/A-B,A);
        else s = Point(0, -C/B), t = Point(-B,-C/B+A);
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
	//极角相等时，位置靠右的排在前面
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
int Get_convex_hull(Line *hp, Point *p, Point *ch) {
	Calc_intersection(hp[que[st]], hp[que[ed]], p[st]);
	for(int i = 0, j = st; j <= ed; i++, j++) ch[i] = p[j];
	return ed - st + 1;
}
double Calc_area(int n, Point *ch) {
	double ans = 0;
	for (int i = 2; i < n; i++)
		ans += area(ch[0], ch[i - 1], ch[i]);
	return ans;
}
int main() {
	int n, N = 0;
	double Area;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> in[i].x >> in[i].y;
	in[n] = in[0];
	for(int i = 0; i < n; i++) {
		L[N++] = Line(in[i], in[i + 1] - in[i]);
		Area += in[i] * in[i + 1];
	}
	for(int i = 1; i < n; i++) { //ax + by = c;
		double a = in[0].y - in[1].y - in[i].y + in[i + 1].y;
		double b = in[1].x - in[0].x + in[i].x - in[i + 1].x;
		double c = in[0].x * in[1].y - in[i].x * in[i + 1].y
				  -in[1].x * in[0].y + in[i + 1].x * in[i].y;
		cout << a << " " << b << " " << c << endl;
		L[N++] = Line(a, b, c);
	}
	for(int i = 0; i < N; i++) {
		cout << L[i].s.x << " " << L[i].s.y << ", " << L[i].t.x << " " << L[i].t.y << endl;
	}
	// if(Halfplane_intersection(N, L, p)) {
		int siz = Get_convex_hull(L, p, convex);
		// double Area2 = Calc_area(siz, convex);
		printf("%.3lf\n", Calc_area(siz, convex));
	// } else {
	// 	printf("0.000\n");
	// }
	return 0;
}