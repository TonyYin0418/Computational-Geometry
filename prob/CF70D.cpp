#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
const double pi = 3.1415926535898;
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
		return fcmp(x, b.x) == 0 && fcmp(y, b.y) == 0;
	}
	double len() {
		return sqrt(x * x + y * y);
	}
};
map<int, int> top, down;
bool check_top(int x, int y) {
	auto it = top.lower_bound(x);
	 it = top.lower_bound(x);
	if(it == top.end())
		return false;
	if(it -> first == x)
		return y <= it->second;
	auto jt = it; jt--;
	return Point(x - it->first, y - it->second) *
		   Point(x - jt->first, y - jt->second) >= 0;
}
bool check_down(int x, int y) {
	auto it = down.lower_bound(x);
	if(it == down.end())
		return false;
	if(it -> first == x)
		return y >= it->second;
	auto jt = it; jt--;
	return Point(x - it->first, y - it->second) *
		   Point(x - jt->first, y - jt->second) <= 0;
}
bool remove_top(map<int, int>::iterator it) {
	if(it == top.begin()) return false; //到边界就不删了
	if(++it == top.end()) return false; it--;
	auto jt = it, kt = it;
	jt--; kt++;
	if(Point(it -> first - jt -> first, it->second - jt->second) *
	   Point(it -> first - kt -> first, it->second - kt->second) <= 0) {
		   top.erase(it);
		   return true;
	}
	return false;
}
bool remove_down(map<int, int>::iterator it) {
	if(it == down.begin()) return false;
	if(++it == down.end()) return false; it--;
	auto jt = it, kt = it;
	--jt; ++kt;
	if(Point(it -> first - jt -> first, it->second - jt->second) *
	   Point(it -> first - kt -> first, it->second - kt->second) >= 0) {
		   down.erase(it);
		   return true;
	}
	return false;
}
void insert_top(int x, int y) {
	if(check_top(x, y)) return;
	top[x] = y;
	auto it = top.find(x);
	auto jt = it;
	if(it != top.begin()) { //remove left
		jt--;
		while(remove_top(jt++)) jt--;
	}
	if(++jt != top.end()) { //remove right
		while(remove_top(jt--)) jt++;
	}
}

void insert_down(int x, int y) {
	if(check_down(x, y)) return;
	down[x] = y;
	auto it = down.find(x);
	auto jt = it;
	if(it != down.begin()) { //remove left
		jt--;
		while(remove_down(jt++)) jt--;
	}
	if(++jt != down.end()) { //remove right
		while(remove_down(jt--)) jt++;
	}
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
			bool ok = (check_top(x, y) & check_down(x, y));
			if(ok) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}