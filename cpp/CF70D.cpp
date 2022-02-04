#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1000;
struct Point{
	int x, y;
	Point(){};
	Point(double a, double b): x(a), y(b) {}
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
	int len() {
		return sqrt(x * x + y * y);
	}
};
map<int, int> top, down;
bool check_top(int x, int y) { //是否在上凸包下面
	auto k = top.lower_bound(x);
	if(k == top.end())
		return false;
	if(k -> first == x)
		return y <= k->second;
	if(k == top.begin()) return false;
	auto j = k; j--;
	return Point(k->first - x, k->second - y) *
		   Point(j->first - x, j->second - y) >= 0;
}
bool check_down(int x, int y) { //是否在下凸包上面
	auto k = down.lower_bound(x);
	if(k == down.end())
		return false;
	if(k -> first == x)
		return y >= k->second;
	if(k == down.begin()) return false;
	auto j = k; j--;
	return Point(k->first - x, k->second - y) *
		   Point(j->first - x, j->second - y) <= 0;
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
signed main() {
	scanf("%lld", &q);
	while(q--) {
		int opt, x, y; scanf("%lld%lld%lld", &opt, &x, &y);
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