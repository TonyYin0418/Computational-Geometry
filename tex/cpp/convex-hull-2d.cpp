inline bool check(Point s1, Point s2, Point p) {
	return Vec(s2, s1) * Vec(s1, p) > 0;
}
int Convex_hull_2d(int n, Point *p, Point *ret) {
	sort(p, p + n, less_cmp);
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
double Convex_hull_2d_L(int n, Point *p) {
	Point convex[N];
	int siz = Convex_hull_2d(n, p, convex);
	double ans = dis(convex[0], convex[siz - 1]);
	for (int i = 1; i < siz; i++)
		ans += dis(convex[i - 1], convex[i]);
	return ans;
}
double Convex_hull_2d_S(int n, Point *p) {
	Point convex[N];
	int siz = Convex_hull_2d(n, p, convex);
	double ans = 0;
	for (int i = 2; i < siz; i++)
		ans += area(convex[0], convex[i - 1], convex[i]);
	return ans;
}
