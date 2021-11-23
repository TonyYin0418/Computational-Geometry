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

map<int, int> top, down;
bool check_top(int x, int y) {
	// map<int, int>::iterator it = top.lower_bound(x);
	auto it = top.lower_bound(x);
	if(it == top.end())
		return false;
	if(it -> first == x)
		return y <= it -> second;
	
}
bool check_down(int x, int y) {

}
bool insert_top(int x, int y) {

}
bool insert_down(int x, int y) {

}
bool check_top(int x, int y) {

}
bool check_down(int x, int y) {

}

int q;
int main() {
	scanf("%d", &q);
	while(q--) {
		int opt, x, y; scanf("%d%d%d", &opt, &x, &y);
		if(opt == 1) {
			insert_top(x, y);
			insert_down(x, y);
		} else {
			bool ok = check_top(x, y) & check_down(x, y);
			if(ok) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}