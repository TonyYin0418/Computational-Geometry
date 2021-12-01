#include <bits/stdc++.h>
using namespace std;
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
int Get_Max(int n, Point *ch) {//传入convec-hull
	int ret = 0;
	ch[++n] = ch[0];
	int j = 2;
	for(int i = 0; i < n; i++) {
		while((ch[i] - ch[j+1]) * (ch[i+1] - ch[j+1]) > (ch[i] - ch[j]) * (ch[i+1] - ch[j]))
			j++;
		ret = max(ret, max(dis(ch[i], ch[j]), dis(ch[i + 1], ch[j])));
	}
}
ingt GetMax()//求出直径
{
       rg long long re=0;
       if(top==1)//仅有两个点
          return Dis(S[0],S[1]);
       S[++top]=S[0];//把第一个点放到最后
       int j=2;
       for(int i=0;i<top;++i)//枚举边
       {
                 while(Compare(S[i],S[i+1],S[j])<Compare(S[i],S[i+1],S[j+1]))
                  j=(j+1)%top;
              re=max(re,max(Dis(S[i],S[j]),Dis(S[i+1],S[j])));
       }
       return re;
}
int main() {
	cin >> n;
	for(int i = 0; i < n; i++) cin >> p[i].x >> p[i].y;
	int siz = Convex_hull_2d(n << 2, p, convex);

	return 0;
}