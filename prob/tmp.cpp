#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int N = 2e5+10;
const double eps = 1e-8;
int n,l,r,cnt,top;
double ans1,ans2;
struct point
{
    double x,y;
    point(){}
    point(double a,double b){x = a, y = b;}
}p[N],sta[N],Ans[N];
typedef point Vector;
struct line
{
    point x,v;
    double ang;
    line(){}
    line(point a,point b)
    {
        x = a; v = b;
        ang = atan2(b.y,b.x);
    }
}L[N],q[N];
int dcmp(double x)
{
    if(fabs(x) < eps) return 0;
    return x > 0 ? 1 : -1;
}
point operator + (point a,point b){return point(a.x+b.x,a.y+b.y);}
point operator - (point a,point b){return point(a.x-b.x,a.y-b.y);}
point operator * (point a,double k){return point(a.x*k,a.y*k);}
double Dot(point a,point b){return a.x*b.x+a.y*b.y;}
double Cro(point a,point b){return a.x*b.y-a.y*b.x;}
double dis(point a,point b){return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));}
bool OnRight(point p,line s){return dcmp(Cro(p-s.x,s.v)) >= 0;}
point Root_LL(line a,line b)
{
    Vector v = a.v, u = b.v, w = a.x-b.x;
    double t = Cro(w,u) / Cro(u,v);
    return a.x + v * t;
}
bool comp(line a,line b)
{
    if(dcmp(a.ang-b.ang) == 0) return OnRight(b.x,a);
    return a.ang < b.ang;
}
void HPI()
{
    sort(L+1,L+cnt+1,comp);
    l = 1, r = 1, q[1] = L[1];
    for(int i = 2; i <= cnt; i++)
    {
        if(dcmp(L[i].ang-L[i-1].ang) == 0) continue;
        while(l < r && OnRight(sta[r-1],L[i])) r--;
        while(l < r && OnRight(sta[l],L[i])) l++;
        q[++r] = L[i];
        if(l < r) sta[r-1] = Root_LL(q[r],q[r-1]);
    }
    while(l < r && OnRight(sta[r-1],q[l])) r--;
    while(l < r && OnRight(sta[l],q[r])) l++;
    sta[r] = Root_LL(q[l],q[r]);
    for(int i = l; i <= r; i++) Ans[++top] = sta[i];
}
int main()
{
    scanf("%d",&n);
    for(int i = 0; i < n; i++) scanf("%lf%lf",&p[i].x,&p[i].y);
    for(int i = 1; i < n; i++) ans1 += Cro(p[i]-p[0],p[(i+1)%n]-p[0]);
    for(int i = 0; i < n; i++) L[++cnt] = line(p[i],p[(i+1)%n]-p[i]);
    for(int i = 1; i < n; i++)
    {
        int t = (i+1) % n;
        double A = p[0].y - p[1].y - p[i].y + p[t].y;
        double B = p[1].x - p[0].x - p[t].x + p[i].x;
        double C = p[0].x * p[1].y - p[1].x * p[0].y + p[t].x * p[i].y - p[i].x * p[t].y;
        cout <<A << " " << B << " " << C << endl;
		if(dcmp(B) == 0) L[++cnt] = line(point(-C/A,0),point(-B,A));
        else L[++cnt] = line(point(0,-C/B),point(-B,A));
    }
    HPI();
    for(int i = 2; i < top; i++) ans2 += Cro(Ans[i]-Ans[1],Ans[i+1]-Ans[1]);
    printf("%.4lf\n",ans2/ans1);
    return 0;
}