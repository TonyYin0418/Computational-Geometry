#include <bits/stdc++.h>
#define int long long
using namespace std;
const double eps = 1e-10;
inline int fcmp(double x, double y) { //x>y->1, x=y->0, x<y->-1
	if(fabs(x - y) < eps) return 0;
	else return x > y ? 1 : -1;
}
inline int sign(double x) {
	if(fabs(x) < eps) return 0;
	else return x > 0 ? 1 : -1;
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
	friend Point operator * (const double a, const Point b) {
		return Point(a * b.x, a * b.y);
	}
	friend Point operator * (const Point b, const double a) {
		return Point(a * b.x, a * b.y);
	}
	double operator * (const Point &b) {
		return x * b.y - y * b.x;
	}
	double operator & (const Point &b) {
		return x * b.x + y * b.y;
	}
	bool operator == (const Point &b) {
		return fcmp(x, b.x) == 0 && fcmp(y, b.y) == 0;
	}
	double len() {
		return sqrt(x * x + y * y);
	}
	Point unit() {
		return Point(x / len(), y / len());
	}
};
typedef Point Vec;
inline bool cmp1(Point a, Point b) {
	return (fcmp(a.x, b.x) == -1) ||
		   (!fcmp(a.x, b.x) && fcmp(a.y, b.y) == -1);
}
inline bool cmp2(Point &a, Point &b) {
	return a * b > 0;
}
bool cmp(Point a, Point b) {
    if(atan2(a.y, a.x) - atan2(b.y, b.x) == 0)
        return a.x < b.x;
    return atan2(a.y, a.x) < atan2(b.y, b.x);
}

inline double dis(Point &a, Point &b) {
	return (a - b).len();
}
inline double angle(Point &a, Point &b) {
	return acos((a & b) / a.len() / b.len());
}
inline bool check(Point s1, Point s2, Point p) {
	return Point(s2, s1) * Point(s1, p) > 0;
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
Point p[MAXN], convex[MAXN], P[MAXN];
double Get_Max(int n, Point *ch) {
	ch[n] = ch[0];
	int u = 2, l, r = 2;
	//u是距离AB最远的点；在AB为底时，l和r是两个最靠边的点
	double ret = 1e100, H, L, R, S;
	for(int i = 0; i < n; i++) {
		Point A = ch[i], B = ch[i+1]; Vec AB = B - A, BA = A - B;
		while((AB * Vec(B, ch[u+1])) >= (AB * Vec(B, ch[u])))
			u = (u + 1) % n;
		while((AB & Vec(B, ch[r+1])) >= (AB & Vec(B, ch[r])))
			r = (r + 1) % n;
		if(i == 0) l = r;
		while((AB & Vec(B, ch[l+1])) <= (AB & Vec(B, ch[l])))
			l = (l + 1) % n;
		H = (AB * Vec(B, ch[u])) / AB.len(); //以AB所在直线为底边，矩形的高
		L = (BA & Vec(A, ch[l])) / BA.len(); //A距离左侧顶点的距离
		R = (AB & Vec(B, ch[r])) / AB.len(); //B距离右侧顶点的距离
		S = H * (L + AB.len() + R); //矩形面积
		if(S < ret) { //求矩形顶点坐标
			ret = S;
			P[0] = A + L * BA.unit();
			P[1] = B + R * AB.unit();
			P[2] = P[1] + H * (ch[r]-P[1]).unit();
			P[3] = P[0] + H * (ch[l]-P[0]).unit();
		}
	}
	return ret;
}
signed main() {
	cin >> n;
	for(int i = 0; i < n; i++) cin >> p[i].x >> p[i].y;
	int siz = Convex_hull_2d(n, p, convex);
	double ans = Get_Max(siz, convex);
	printf("%.5lf\n", ans);
	int st = 0;
	for(int i = 1; i < 4; i++)
		if(P[i].y < P[st].y || (P[i].y == P[st].y && P[i].x < P[st].x))
			st = i;
	for(int i = st; i < st + 4; i++) {
		if(!sign(P[i%4].x)) P[i%4].x = 0;
		if(!sign(P[i%4].y)) P[i%4].y = 0;
		printf("%.5lf %.5lf\n", P[i%4].x, P[i%4].y);
	}
	return 0;
}