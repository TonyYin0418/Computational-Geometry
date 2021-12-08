#include <bits/stdc++.h>
using namespace std;
const double PI = 3.1415926535898;
const double eps = 1e-10;
inline int fcmp(double x, double y) { //x>y->1, x=y->0, x<y->-1
	if(fabs(x - y) < eps) return 0;
	else return x > y ? 1 : -1;
}
struct Point{
	double x, y;
	Point(){};
	Point(double a, double b): x(a), y(b) {}
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
		return !fcmp(x, b.x) && !fcmp(y, b.y);
	}
	double len() {
		return sqrt(x * x + y * y);
	}
};
typedef Point Vec;
inline bool cmp1(Vec a, Vec b) {
	return (fcmp(a.x, b.x) == -1) ||
		   (!fcmp(a.x, b.x) && fcmp(a.y, b.y) == -1);
}
inline double dis(Point a, Point b) {
	return (a - b).len();
}
inline double angle(Vec a, Vec b) {
	return acos((a & b) / a.len() / b.len());
}
inline Vec rotate(Vec a, double rad) {
	return Vec(a.x * cos(rad) - a.y * sin(rad),
			   a.x * sin(rad) + a.y * cos(rad));
}
inline bool check(Point s1, Point s2, Point p) {
	return Vec(s2, s1) * Vec(s1, p) > 0;
}
int Convex_hull_2d(int n, Point *p, Point *ret) {
	sort(p, p + n, cmp1);
	ret[0] = p[0], ret[1] = p[1];
	int top = 1;
	for (int i = 2; i < n; i++) {
		while (top > 0&& !check(ret[top], ret[top - 1], p[i]))
			top--;
		ret[++top] = p[i];
	}
	int k = top;
	ret[++top] = p[n - 2];
	for (int i = n - 3; i >= 0; i--) {
		while (top > k && !check(ret[top], ret[top - 1], p[i]))
			top--;
		ret[++top] = p[i];
	}
	return top;
}
const int MAXN = 10010;
int n;
double a, b, r, x, y, theta;
Point p[MAXN << 2], convex[MAXN << 2];
int main() {
	cin >> n >> a >> b >> r;
	a -= 2 * r, b -= 2 * r;
	double len = sqrt(a * a + b * b) / 2; //从中心到每个圆心的距离
	for(int i = 0; i < n; i++) {
		cin >> x >> y >> theta;
		p[i<<2|0] = Vec(x, y) + rotate(Vec(b/2, a/2), theta);
		p[i<<2|1] = Vec(x, y) + rotate(Vec(-b/2, a/2), theta);
		p[i<<2|2] = Vec(x, y) + rotate(Vec(b/2, -a/2), theta);
		p[i<<2|3] = Vec(x, y) + rotate(Vec(-b/2, -a/2), theta);
	}
	int siz = Convex_hull_2d(n << 2, p, convex);
	double ans = 2 * r * PI;
	for(int i = 1; i < siz; i++)
		ans += dis(convex[i - 1], convex[i]);
	printf("%.2lf\n", ans + dis(convex[0], convex[siz - 1]));
	return 0;
}