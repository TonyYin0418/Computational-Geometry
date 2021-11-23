#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
const double pi = 3.1415926535898;
const double eps = 1e-10;
inline int fcmp(double x, double y) { //x>y->1, x=y->0, x<y->-1
	if(fabs(x - y) < eps) return 0;
	else return x > y ? 1 : -1;
}
inline double rd() { return (rand()) % 2 ? eps : -eps; }
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
		return fcmp(x, b.x) == 0 && fcmp(y, b.y) == 0;
	}
	double len() {
		return sqrt(x * x + y * y);
	}
};
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
inline Point rotate(Point &a, double k) {
	return Point(a.x * cos(k) - a.y * sin(k), a.x * sin(k) - a.y * cos(k));
}
inline bool check(Point s1, Point s2, Point p) {
	return Point(s2, s1) * Point(s1, p) > 0;
}

/*
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
}*/

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

struct Point3 {
	double x, y, z;
	Point3(){};
	Point3(double a, double b, double c) : x(a), y(b), z(c) {}
	Point3 operator + (const Point3 &b) {
		return Point3(x + b.x, y + b.y, z + b.z);
	}
	Point3 operator - (const Point3 &b) {
		return Point3(x - b.x, y - b.y, z - b.z);
	}
	Point3 operator * (const Point3 &b) {
		return Point3(y*b.z - z*b.y, z*b.x - x*b.z, x*b.y - y*b.x);
	}
	double operator & (const Point3 &b) {
		return x * b.x + y * b.y + z * b.z;
	}
	bool operator == (const Point3 &b) {
		return fcmp(x, b.x) == 0 && fcmp(y, b.y) == 0 && fcmp(z, b.z) == 0;
	}
	double len() {
		return sqrt(x * x + y * y + z * z);
	}
	void shake() { x += rd(), y += rd(), z += rd(); }
} p[N];
struct plane{
	int v[3]; //逆时针
	plane(){};
	plane(int a, int b, int c) { v[0] = a, v[1] = b, v[2] = c; }
	Point3 normal() {
		return (p[v[1]] - p[v[0]]) * (p[v[2]] - p[v[0]]);
	}
	bool is_above(Point3 A) {
		return (normal() & (A - p[v[0]])) >= 0;
	}
	double area() {
		return normal().len() / 2.0;
	}
};
int Convex_hull_3d(int n, plane *ret) {
	plane tmp[N];
	bool g[N][N];
	for (int i = 0; i < n; i++) p[i].shake();
	int top = -1;
	ret[++top] = plane(0, 1, 2);
	ret[++top] = plane(0, 2, 1);
	for (int i = 3; i < n; i++)
	{
		int cnt = -1;
		for (int j = 0; j <= top; j++)
		{
			bool flag = ret[j].is_above(p[i]);
			if (!flag)
				tmp[++cnt] = ret[j];
			for (int k = 0; k < 3; k++)
				g[ret[j].v[k]][ret[j].v[(k + 1) % 3]] = flag;
		}
		for (int j = 0; j <= top; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				int a = ret[j].v[k], b = ret[j].v[(k + 1) % 3];
				if (g[a][b] && !g[b][a])
					tmp[++cnt] = plane(a, b, i);
			}
		}
		for (int j = 0; j <= cnt; j++) ret[j] = tmp[j];
		top = cnt;
	}
	return (top + 1);
}
double Convex_hull_area(int n) {
	plane convex[N];
	int siz = Convex_hull_3d(n, convex);
	double ret = 0;
	for (int i = 0; i < siz; i++) ret += convex[i].area();
	return ret;
}