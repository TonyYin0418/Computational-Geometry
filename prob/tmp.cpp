#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define debug(a) cout << #a << " " << a << endl
#define de(a) cout << a << " "
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())
#define PII pair<int, int>
#define fi first
#define se second
const int maxn = 3000;
const int maxp = 3000;
const int N = 1e6 + 7, M = N * 2;
const int inf = 0x3f3f3f3f;
const long long INF = 0xFFFFFFFFFF;
const long long mod = 1e9 + 7;
const double eps = 1e-8;

inline long long read();

/*
 * 将所有凸包拆开,求凸包的面积交相当于所有求半平面交
 */

int sgn(double x) {
    if (fabs(x) < eps)return 0;
    if (x < 0)return -1;
    else return 1;
}

struct Point {
    double x, y;

    Point() {}

    Point(double _x, double _y) {
        x = _x;
        y = _y;
    }

    Point operator-(const Point &b) const {
        return Point(x - b.x, y - b.y);
    }

    double operator^(const Point &b) const {
        return x * b.y - y * b.x;
    }
};

struct Line {
    Point s, e;

    //`求两直线的交点`
    //`要保证两直线不平行或重合`
    Point crosspoint(Line v) {
        double a1 = (v.e - v.s) ^ (s - v.s);
        double a2 = (v.e - v.s) ^ (e - v.s);
        return Point((s.x * a2 - e.x * a1) / (a2 - a1), (s.y * a2 - e.y * a1) / (a2 - a1));
    }

    //`两向量平行(对应直线平行或重合)`
    bool parallel(Line v) {
        return sgn((e - s) ^ (v.e - v.s)) == 0;
    }
};

struct polygon {
    int n;
    Point p[maxp];
    Line l[maxp];

    //`得到面积`
    double getarea() {
        double sum = 0;
        for (int i = 0; i < n; i++) {
            sum += (p[i] ^ p[(i + 1) % n]);
        }
        return fabs(sum) / 2;
    }
};

struct halfplane : public Line {
    double angle;

    halfplane() {}

    //`表示向量s->e逆时针(左侧)的半平面`
    halfplane(Point _s, Point _e) {
        s = _s;
        e = _e;
    }

    halfplane(Line v) {
        s = v.s;
        e = v.e;
    }

    void calcangle() {
        angle = atan2(e.y - s.y, e.x - s.x);
    }

    bool operator<(const halfplane &b) const {
        return angle < b.angle;
    }


};


struct halfplanes {
    int n;
    halfplane hp[maxp];
    Point p[maxp];
    int que[maxp];
    int st, ed;

    void push(halfplane tmp) {
        hp[n++] = tmp;
    }

    //去重
    void unique() {
        int m = 1;
        for (int i = 1; i < n; i++) {
            if (sgn(hp[i].angle - hp[i - 1].angle) != 0)
                hp[m++] = hp[i];
            else if (sgn((hp[m - 1].e - hp[m - 1].s) ^ (hp[i].s - hp[m - 1].s)) > 0)
                hp[m - 1] = hp[i];
        }
        n = m;
    }

    bool halfplaneinsert() {
        for (int i = 0; i < n; i++)hp[i].calcangle();
        sort(hp, hp + n);
        unique();
		cout << "L[]: \n";
		for(int i = 0; i < 10; i++) {
			printf("(%.2lf, %.2lf) -> (%.2lf, %.2lf)\n", hp[i].s.x, hp[i].s.y, hp[i].e.x, hp[i].e.y);
		}
        que[st = 0] = 0;
        que[ed = 1] = 1;
        p[1] = hp[0].crosspoint(hp[1]);
        for (int i = 2; i < n; i++) {
            while (st < ed && sgn((hp[i].e - hp[i].s) ^ (p[ed] - hp[i].s)) < 0)ed--;
            while (st < ed && sgn((hp[i].e - hp[i].s) ^ (p[st + 1] - hp[i].s)) < 0)st++;
            que[++ed] = i;
            if (hp[i].parallel(hp[que[ed - 1]]))return false;
            p[ed] = hp[i].crosspoint(hp[que[ed - 1]]);
        }
        while (st < ed && sgn((hp[que[st]].e - hp[que[st]].s) ^ (p[ed] - hp[que[st]].s)) < 0)ed--;
        while (st < ed && sgn((hp[que[ed]].e - hp[que[ed]].s) ^ (p[st + 1] - hp[que[ed]].s)) < 0)st++;
        if (st + 1 >= ed)return false;
        return true;
    }

    //`得到最后半平面交得到的凸多边形`
    //`需要先调用halfplaneinsert() 且返回true`
    void getconvex(polygon &con) {
        p[st] = hp[que[st]].crosspoint(hp[que[ed]]);
        con.n = ed - st + 1;
        for (int j = st, i = 0; j <= ed; i++, j++)
            con.p[i] = p[j];
    }
};

int n, m;
Line line;
halfplanes hfs;
polygon poly;

void solve() {
    scanf("%d", &n);
    int cnt = 0;
    Point point[maxp];
    for (int cas = 1; cas <= n; cas++) {
        scanf("%d", &m);
        double x, y;
        //读入逆时针方向输入的点
        for (int i = 1; i <= m; i++) {
            scanf("%lf%lf", &x, &y);
            point[i] = Point(x, y);
        }
        //构成直线
        for (int i = 1; i <= m; i++) {
            Point s, e;
            s = point[i];
            if (i == m) e = point[1];
            else e = point[i + 1];
            Line line = {s, e};
            halfplane hf = halfplane(line);
            hfs.push(hf);
        }
    }
//    hfs.unique();
    if (hfs.halfplaneinsert()) {
		cout << "p[]: \n";
		for(int i = hfs.st + 1; i <= hfs.ed; i++) {
			cout << hfs.p[i].x << " " << hfs.p[i].y << endl;
		}
        hfs.getconvex(poly);
        printf("%.3lf", poly.getarea());
    }
    else {
        printf("0.000");
    }


}

int main() {
#ifdef LOCAL
    int begin_time = clock();
    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);
#endif

//	ios::sync_with_stdio(false); //使用read和cout时不能解除流同步
    int T = 1;
//    T = read();
    for (int cas = 1; cas <= T; cas++) {
#ifdef LOCAL
        printf("Case #%d: \n", cas);
#endif
        solve();
    }

#ifdef LOCAL
    int end_time = clock();
    printf("\nRun time: %.2lf ms", (double) (end_time - begin_time) / CLOCKS_PER_SEC * 1000);
#endif

    return 0;
}

/*
数组开够了吗
初始化了吗
*/

inline long long read() {
    char ch_read = getchar();
    long long p_read = 1, data_read = 0;
    while (ch_read < '0' || ch_read > '9') {
        if (ch_read == '-') p_read = -1;
        ch_read = getchar();
    }
    while (ch_read >= '0' && ch_read <= '9') {
        data_read = data_read * 10 + (ch_read ^ 48);
        ch_read = getchar();
    }
    return p_read * data_read;
}