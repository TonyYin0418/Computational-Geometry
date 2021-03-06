# 向量

## 平面向量

**向量：** 既有大小又有方向的量称为向量，记作 $\vec {a}$ 或 $\boldsymbol a$。

**有向线段：** 带方向的线段。用有向线段来直观地表示向量。起点为 $A$ 终点为 $B$ 的有向线段表示的向量，用符号简记为 $\overrightarrow{AB}$.

**向量的模：**向量的大小（或长度），用 $|\overrightarrow{AB}|$ 或 $|\boldsymbol{a}|$ 表示。

**零向量**：模为 $0$ 的向量。零向量的方向任意。记为：$\vec 0$ 或 $\boldsymbol{0}$。

**单位向量**：模为 $1$ 的向量称为该方向上的单位向量。

**平行向量**：方向相同或相反的两个 **非零** 向量。规定 $\boldsymbol 0$ 与任意向量平行。$\boldsymbol{a}$ 与 $\boldsymbol{b}$ 平行，记作：$\boldsymbol{a}\parallel \boldsymbol{b}$ 。

**共线向量：**与平行向量的定义相同。任一组平行向量都可以平移到同一直线上。

**向量的夹角**：已知两个非零向量 $\boldsymbol a,\boldsymbol b$，作 $\overrightarrow{OA}=\boldsymbol a,\overrightarrow{OB}=\boldsymbol b$，那么 $\theta=\angle AOB$ 就是向量 $\boldsymbol a$ 与向量 $\boldsymbol b$ 的夹角。记作：$\langle \boldsymbol a,\boldsymbol b\rangle$。当 $\theta=\frac{\pi}{2}$ 时，称这两个向量垂直，记作 $\boldsymbol a\perp \boldsymbol b$。规定 $\theta \in [0,\pi]$。

## 向量的线性运算

### 向量的加法

<img src="md-fig/fig1.svg" style="zoom: 100%;" />

#### 向量加法的三角形法则

对于平面上的任意两个向量 $\boldsymbol{a}$ 和 $\boldsymbol{b}$，在平面内任取一点 $A$，作 $\overrightarrow{AB}=\boldsymbol{a}$，$\overrightarrow{BC}=\boldsymbol{b}$，作向量 $\overrightarrow{AC}$.

称向量 $\overrightarrow{AC}$ 为向量 $\boldsymbol{a}$ 和 $\boldsymbol{b}$ 的 **和向量**，$\overrightarrow{AB}+\overrightarrow{BC}=\overrightarrow{AC}.$



如图1，把向量首尾顺次相连，向量的和为第一个向量的起点指向最后一个向量的终点；

#### 向量加法的平行四边形法则

若要求和的两个向量 **共起点**，那么它们的和向量为以这两个向量为邻边的平行四边形的对角线，起点为两个向量共有的起点，方向沿平行四边形对角线方向。

### 向量的减法

减法可以写成加上相反数的形式，即：$a-b=a+(-b)$，如图1，$b=c-a$，$a=c-b$.

### 向量的数乘

给定一个实数 $\lambda$ 和一个向量 $\boldsymbol a$，规定其乘积为一个向量，记作 $\lambda \boldsymbol a$，其模与方向定义如下：

1. $|\lambda \boldsymbol a|=|\lambda| |\boldsymbol a|$；
2. 当 $\lambda >0$ 时，$\lambda\boldsymbol a$ 与 $\boldsymbol a$ 同向，当 $\lambda =0$ 时，$\lambda \boldsymbol a=\boldsymbol 0$，当 $\lambda<0$ 时，$\lambda \boldsymbol a$ 与 $\boldsymbol a$ 方向相反。

这种运算是向量的数乘运算。

### 坐标表示

$$
\boldsymbol a + \boldsymbol b=(\boldsymbol a_x+\boldsymbol b_x,\;\boldsymbol a_y+\boldsymbol b_y)\\
\boldsymbol a - \boldsymbol b=(\boldsymbol a_x-\boldsymbol b_x,\;\boldsymbol a_y-\boldsymbol b_y)\\
\lambda \boldsymbol a=(\lambda\boldsymbol a_x,\;\lambda\boldsymbol a_y)
$$

## 向量的数量积

已知两个向量 $\boldsymbol a,\boldsymbol b$，它们的夹角为 $\theta$，那么：
$$
\boldsymbol a \cdot \boldsymbol b=|\boldsymbol a||\boldsymbol b|\cos \theta=\boldsymbol a_x\boldsymbol b_x+\boldsymbol a_y\boldsymbol b_y
$$
就是这两个向量的 **数量积**，也叫 **点积** 或 **内积**。其中称 $|\boldsymbol a|\cos \theta$ 为 $\boldsymbol a$ 在 $\boldsymbol b$ 方向上的投影。数量积的几何意义即为：数量积 $\boldsymbol a \cdot \boldsymbol b$ 等于 $\boldsymbol a$ 的模与 $\boldsymbol b$ 在 $\boldsymbol a$ 方向上的投影的乘积。

这种运算得到的结果是一个实数，为标量。

可以方便的计算出 $\cos \theta$，于是有如下应用：

1. $\boldsymbol a \perp \boldsymbol b$ $\iff$ $\boldsymbol a\cdot \boldsymbol b=0$

2. $\boldsymbol a = \lambda \boldsymbol b$ $\iff$ $|\boldsymbol a\cdot \boldsymbol b|=|\boldsymbol a||\boldsymbol b|$

3. $|\boldsymbol a|=\sqrt {m^2+n^2}$
4. $\cos \theta=\cfrac{\boldsymbol a\cdot\boldsymbol b}{|\boldsymbol a||\boldsymbol b|}$

## 向量的向量积

给定两个向量 $\boldsymbol a,\boldsymbol b$，规定其向量积为一个向量，记作 $\boldsymbol a\times \boldsymbol b$，其模与方向定义如下：

1. $|\boldsymbol a\times \boldsymbol b|=|\boldsymbol a||\boldsymbol b|\sin \langle \boldsymbol a,\boldsymbol b\rangle$；

2. $\boldsymbol a\times \boldsymbol b$ 与 $\boldsymbol a,\boldsymbol b$ 都垂直，且 $\boldsymbol a,\boldsymbol b,\boldsymbol a\times \boldsymbol b$ 符合右手法则。

向量积也叫外积，其几何意义是：**$|\boldsymbol a\times \boldsymbol b|$ 是以 $\boldsymbol a,\boldsymbol b$ 为邻边的平行四边形的面积**。

向量积与 $\boldsymbol a,\boldsymbol b$ 所在平面垂直，其竖坐标为 $\boldsymbol a_x\boldsymbol b_y-\boldsymbol a_y\boldsymbol b_x$.

我们根据右手法则可以推断出 $\boldsymbol b$ 相对于 $\boldsymbol a$ 的方向，**逆时针方向竖坐标为正值，反之为负值**。

## 坐标旋转公式

若将向量 $\boldsymbol a=(x,\;y)$ 逆时针旋转 $\alpha$，得到向量 $\boldsymbol b$，则有：
$$
\boldsymbol b=(x\cos \alpha-y\sin \alpha,\;y\cos \alpha+x\sin\alpha)
$$
可以通过三角恒等变换证明。

## 参考代码

```cpp
const double pi = 3.1415926535898;
const double eps = 1e-8;
inline int sgn(double x) {
	if(fabs(x) < eps) return 0;
	else return x > 0 ? 1 : -1;
}
inline int fcmp(double x, double y) {
	if(fabs(x - y) < eps) return 0;
	else return x > y ? 1 : -1;
}
struct Point{
	double x, y;
	Point(){};
	Point(double a, double b): x(a), y(b) {}
	Point(Point a, Point b): x(b.x - a.x), y(b.y - a.y) {}
	friend Point operator + (const Point &a, const Point &b) {
		return Point(a.x + b.x, a.y + b.y);
	}
	friend Point operator - (const Point &a, const Point &b) {
		return Point(a.x - b.x, a.y - b.y);
	}
	friend bool operator == (const Point &a, const Point &b) {
		return fcmp(a.x, b.x) == 0 && fcmp(a.y, b.y == 0);
	}
	friend Point operator * (const double &a, const Point &b) {
		return Point(a * b.x, a * b.y);
	}
	friend Point operator * (const Point &a, const double &b) {
		return Point(a.x * b, a.y * b);
	}
	friend double operator * (const Point &a, const Point &b) {
		return a.x * b.y - a.y * b.x;
	}
	friend double operator & (const Point &a, const Point &b) {
		return a.x * b.x + a.y * b.y;
	}
	friend Point operator / (const Point &a, const double &b) {
		return Point(a.x / b, a.y / b);
	}
	friend bool operator < (const Point &a, const Point &b) {
		return (a.x < b.x) || (a.x == b.x && a.y < b.y);
	}
	inline double len() {
		return sqrt(1.0 * x * x + 1.0 * y * y);
	}
	friend double area(Point &a, Point &b, Point &c) {
		return (b - a) * (c - a) / 2.0;
	}
};
typedef Point Vec;
inline bool cmp1(Vec a, Vec b) {
	return (fcmp(a.x, b.x) == -1) ||
		   (!fcmp(a.x, b.x) && fcmp(a.y, b.y) == -1);
}
inline double dis(Point &a, Point &b) {
	return (a - b).len();
}
inline double angle(Point &a, Point &b) {
	return acos((a & b) / a.len() / b.len());
}
inline Vec rotate(Vec &a, double k) {
	return Vec(a.x * cos(k) - a.y * sin(k), a.x * sin(k) - a.y * cos(k));
}
```

# 平面凸包

## 相关概念

**凸多边形：**所有内角大小都在 $[0,\pi]$ 范围内的 **简单多边形**。

<img src="md-fig/fig2.svg" style="zoom: 200%;" />

**平面凸包：**平面上的一个子集 $S$ 被称为凸的，当且仅当对于任意两点 $p, q\in S$，线段 $\overline{pq}$ 都完全属于 $S$.集合 $S$ 的凸包 $\mathcal{CH}(S)$，是包含 $S$ 的最小凸集，也就是包含 $S$ 的所有凸集的交。

<img src="md-fig/fig3.svg" style="zoom: 200%;" />

如上图，凸包还可以理解为平面上有若干柱子，**用橡皮筋套住所有柱子**，绷紧后形成的多边形即为凸包。

所以有更友好的定义（不一定准确）。

**凸包：**在平面上能包含所有给定点的最小凸多边形叫做凸包。

## 暴力求解

用二维坐标 $(x_i, y_i)$ 的形式给定点集 $P$，考虑如何暴力求解。

<img src="md-fig/fig4.svg" style="zoom: 200%;" />

注意到，若线段 $\overline{pq}$ 在凸包上，则 $P$ 中的点均位于直线 $pq$ 的同一侧。若我们钦定 $p\rightarrow q$ 按顺时针方向，则有更强的限制，需要 $P$ 中的点都在直线的右侧。

于是可以枚举有序点对 $(p, q)\in P\times P$，若 $P$ 中的点都在有向线段 $\overline{pq}$ 的右侧，则 $\overline{pq}$ 是 $\mathcal{CH}(P)$ 中的一条边。

需要用到向量的叉积，点 $t$ 在 $\overrightarrow {pq}$ 右侧 $\Longleftrightarrow$ $\overrightarrow{pt}\times \overrightarrow{pq}>0$.

这样的复杂度是 $\mathcal{O}(n^3)$ 的，有很多可以优化的地方。

## Andrew算法

Andrew 算法是一种递增式算法，流程如下。

> 递增式算法 (incremental algorithm)，在计算几何中常见。算法思想：逐一加入 $P$ 中的点，每增加一个点，都更新一次目前的解，加入最后一个点后，即可得到答案。

首先把所有点 **排序** ，以横坐标为第一关键字，纵坐标为第二关键字。

排序后，第一个点和末尾的点，一定在凸包上，容易通过反证法证明。

从左往右看，上下凸壳斜率的 **单调性相反**，即所旋转的方向不同，所以要分开求。

我们 **升序枚举** 求出下凸壳，然后 **降序枚举** 求出上凸壳，这样凸包的每条边都是向 **逆时针方向** 旋转的。

设当前枚举到点 $P$，即将把其加入凸包；当前栈顶的点为 $S_1$，栈中第二个点为 $S_2$.

求凸包时，若 $P$ 与 $S_1$ 构成的新线段是顺时针旋转的，即叉积满足：$\overrightarrow{S_2S_1}\times \overrightarrow{S_1P}<0$，则弹出栈顶，继续检查，直到 $\overrightarrow{S_2S_1}\times \overrightarrow{S_1P}\ge 0$ 或者栈内仅剩一个元素为止。

<img src="md-fig/fig5.svg" style="zoom: 200%;" />

上图是一个弹栈的例子，$p_i$ 是新加入的点，细线是加入 $p_i$ 之前的凸包状态。

记 $n=|P|$，则时间复杂度为 $\mathcal{O}(n\log n)$，瓶颈在排序部分。

<img src="md-fig/fig6.svg" style="zoom: 200%;" />

如上图，若将弹出栈顶元素的条件改为 $\overrightarrow{S_2S_1}\times \overrightarrow{S_1P}\leq 0$，同时停止条件改为 $\overrightarrow{S_2S_1}\times \overrightarrow{S_1P}> 0$，则求出的凸包中不存在三点共线。可视情况更改。

下面是参考代码。函数返回值为凸包的点数，`Point ret[] `的下标从 $0$ 开始。

```cpp
inline bool check(Point s1, Point s2, Point p) {
	return Vec(s2, s1) * Vec(s1, p) > 0;
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
```

## Graham算法

Andrew 算法是 Graham 算法的改进版本。在 Graham 算法中，点集按照极角序排序。

**极角：**任取一个顶点 $O$ 作为极点，作射线 $OX$，称为极轴。平面上一点 $p$ 的极角，即为向量 $\overrightarrow{Op}$ 与极轴 $OX$ 的夹角。一般地，取 $x$ 轴作为极轴，以逆时针方向为正。

可以利用 `atan2(double y, double x)` 进行极角排序。函数返回值为 $(x, y)$ 与 $x$ 轴的极角，数值 $\in(-\pi, \pi]$.

```cpp
bool cmp(Point a, Point b) {
    if(atan2(a.y, a.x) - atan2(b.y, b.x) == 0)
        return a.x < b.x;
    return atan2(a.y, a.x) < atan2(b.y, b.x);
}
```

另外一种方式是利用叉积排序。

```cpp
bool cmp(Point a, Point b) {
    return a * b > 0;
}
```

注意极角排序时，无论用 `atan2` 还是叉积，精度上都会出现不少问题，尽量避免使用这种方法。

## 平面凸包的周长与面积

先求出**按照顺时针排序**的，构成凸包的点集 $p$，记 $n=|p|$.

**求周长：**把相邻两点组成的向量的模长求和，即：
$$
l=\sum_{i=1}^n|\overrightarrow{p_{i}p_{i+1}}|+|\overrightarrow{p_{1}p_{n}}|
$$

```cpp
double dis(Point a, Point b) {
	return (a - b).len();
}
double Convex_hull_2d_L(int n, Point *p) {
	Point convex[N];
	int siz = Convex_hull_2d(n, p, convex);
	double ans = dis(convex[0], convex[siz - 1]);
	for (int i = 1; i < siz; i++)
		ans += dis(convex[i - 1], convex[i]);
	return ans;
}
```

**求面积：**任取凸包内一点（一般取 $p_1$），则有：
$$
s=\sum_{i=2}^{n-1} \operatorname{area}(p_1, p_i, p_i+1)=\sum_{i=2}^{n-1}\frac{|(p_i-p_1)\times (p_{i+1}-p_1)|}{2}
$$

```cpp
double area(Point a, Point b, Point c) {
	return (b - a) * (c - a) / 2.0;
}
double Convex_hull_2d_S(int n, Point *p) {
	Point convex[N];
	int siz = Convex_hull_2d(n, p, convex);
	double ans = 0;
	for (int i = 2; i < siz; i++)
		ans += area(convex[0], convex[i - 1], convex[i]);
	return ans;
}
```

# 动态凸包（CF70D）

维护一个点集 $S$ 的凸包，需要支持如下操作：

- 询问点 $p$ 是否在当前的凸包中，
- 向 $S$ 中添加点 $p$，

保证坐标均为整数。

## 分析

和 Andrew 算法一样，这里的算法按照坐标字典序排序。相对于极角排序，能够减小精度误差。

用两个 `std::map<int, int>`，用 $\operatorname{top}$ 记录上凸包，$\operatorname{down}$ 记录下凸包。

**存储方法：**若上凸包中存在横坐标为 $x$ 的点，则这个点的纵坐标为 $\operatorname{top}[x]$，$\operatorname{down}$ 同理。

## 询问操作

只需满足：**在上凸包之下**且**在下凸包之上**。

<img src="md-fig/fig7.svg" style="zoom: 100%;" />

以上凸包为例。$i$ 在上凸包之下，当且仅当 $|\overrightarrow{ik}\times \overrightarrow{ij}|\geq 0$.

```cpp
bool check_top(int x, int y) {
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
```

下凸包同理，$i$ 在下凸包之上，当且仅当 $|\overrightarrow{ik}\times \overrightarrow{ij}|\leq 0$

```cpp
bool check_down(int x, int y) {
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
```

## 插入操作

把 $p$ 点加入凸包，上下凸包都要尝试。把加入 $p$ 点后，删掉不满足凸性的点。

<img src="md-fig/fig8.svg" style="zoom: 100%;" />

如上图，这些点一定是分布在 $p_x$ 左右的连续段。

因此找到 $p$ 点在上/下凸壳中的位置，向左右分别删点，直到满足凸性。

注意迭代器的边界问题。如果已经删没了，要及时退出循环，否则会 RE。

```cpp
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
```

下面的函数用于：判断能否删除当前点，若能删，则执行删除操作。

```cpp
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
```

# 三维凸包

## 三维向量类

<img src="md-fig/fig9.svg" style="zoom: 80%;" />

**存储：**用结构体记录三维坐标，方便重载运算符。

```cpp
struct Point3 {
	double x, y, z;
	Point3(){};
	Point3(double a, double b, double c) : x(a), y(b), z(c) {}
};
```

**加法、减法和点乘等操作**：与二维向量类似。

```cpp
Point3 operator + (const Point3 &b) {
    return Point3(x + b.x, y + b.y, z + b.z);
}
Point3 operator - (const Point3 &b) {
    return Point3(x - b.x, y - b.y, z - b.z);
}
Point3 operator * (const Point3 &b) {
    return Point3(y*b.z - z*b.y, z*b.x - x*b.z, x*b.y - y*b.x);
}
bool operator == (const Point3 &b) {
    return fcmp(x, b.x) == 0 && fcmp(y, b.y) == 0 && fcmp(z, b.z) == 0;
}
double len() {
    return sqrt(x * x + y * y + z * z);
}
```

**叉乘：**$\boldsymbol a\times \boldsymbol b$ 的结果为一个三维向量 $\boldsymbol c$，$\boldsymbol c\perp \boldsymbol a$ 且 $\boldsymbol c\perp \boldsymbol b$，结果向量的模长为 $|\boldsymbol a||\boldsymbol b|\sin \langle \boldsymbol a,\boldsymbol b\rangle$，代表以 $\boldsymbol a$、$\boldsymbol b$ 为两边的平行四边形的面积。

<img src="md-fig/fig10.svg" style="zoom: 80%;" />

在三维向量体系中，我们需要用坐标表示结果向量 $\boldsymbol{a}$，推导过程如下。（来源：[叉积 - 维基百科](https://zh.wikipedia.org/wiki/%E5%8F%89%E7%A7%AF)）

右手坐标系中，基向量 $\boldsymbol{i},\boldsymbol{j},\boldsymbol{k}$ 满足以下等式：
$$
\begin{array}{c}
\boldsymbol{i}\times\boldsymbol{j} = \boldsymbol{k}\\
\boldsymbol{j\times i} = -\boldsymbol{k}\\
\boldsymbol{j}\times\boldsymbol{k} = \boldsymbol{i}\\
\boldsymbol{k\times j} = -\boldsymbol{i}\\
\boldsymbol{k}\times\boldsymbol{i} = \boldsymbol{j}\\
\boldsymbol{i\times k} = -\boldsymbol{j}
\end{array}
$$
根据外积的定义可以得出：$\boldsymbol{i}\times\boldsymbol{i} = \boldsymbol{j}\times\boldsymbol{j} = \boldsymbol{k}\times\boldsymbol{k} = \boldsymbol{0}$.

根据以上等式，结合外积的**分配律**，就可以确定任意向量的外积。

任取向量 $\boldsymbol{u}=u_1\boldsymbol{i} + u_2\boldsymbol{j} + u_3\boldsymbol{k} $ 和 $\boldsymbol{v}=v_1\boldsymbol{i} + v_2\boldsymbol{j} + v_3\boldsymbol{k}$，两者的外积 $\boldsymbol{u} \times \boldsymbol{v}$ 可以根据分配率展开：
$$
\begin{align}
\boldsymbol{u}\times\boldsymbol{v} = &(u_1\boldsymbol{i} + u_2\boldsymbol{j} + u_3\boldsymbol{k}) \times (v_1\boldsymbol{i} + v_2\boldsymbol{j} + v_3\boldsymbol{k})\\
= &u_1v_1(\boldsymbol{i} \times \boldsymbol{i}) + u_1v_2(\boldsymbol{i} \times \boldsymbol{j}) + u_1v_3(\boldsymbol{i} \times \boldsymbol{k}) + \\
&u_2v_1(\boldsymbol{j} \times \boldsymbol{i}) + u_2v_2(\boldsymbol{j} \times \boldsymbol{j}) + u_2v_3(\boldsymbol{j} \times \boldsymbol{k}) + \\
&u_3v_1(\boldsymbol{k} \times \boldsymbol{i}) + u_3v_2(\boldsymbol{k} \times \boldsymbol{j}) + u_3v_3(\boldsymbol{k} \times \boldsymbol{k})\\
\end{align}
$$
把前面的 $6$ 个等式代入，则有：
$$
\begin{align}
 \boldsymbol{u}\times\boldsymbol{v} = {} &- u_1v_1\boldsymbol{0} + u_1v_2\boldsymbol{k} - u_1v_3\boldsymbol{j} \\
                                 &- u_2v_1\boldsymbol{k} - u_2v_2\boldsymbol{0} + u_2v_3\boldsymbol{i} \\
                                 &+ u_3v_1\boldsymbol{j} - u_3v_2\boldsymbol{i} - u_3v_3\boldsymbol{0} \\
                            = {} &(u_2v_3 - u_3v_2)\boldsymbol{i} + (u_3v_1 - u_1v_3)\boldsymbol{j} + (u_1v_2 - u_2v_1)\boldsymbol{k}\\
\end{align}
$$
因此结果向量 $\boldsymbol{s} = \boldsymbol{u} \times \boldsymbol{v} = s_1\boldsymbol{i} + s_2\boldsymbol{j} + s_3\boldsymbol{k}$ 的三维坐标为：
$$
\begin{align}
  s_1 &= u_2v_3-u_3v_2\\
  s_2 &= u_3v_1-u_1v_3\\
  s_3 &= u_1v_2-u_2v_1
\end{align}
$$

```cpp
Point3 operator * (const Point3 &b) {
    return Point3(y*b.z - z*b.y, z*b.x - x*b.z, x*b.y - y*b.x);
}
```

## 平面类

用三个向量表示一个三角形的平面。一个多面体可以通过三角剖分，用若干个三角形表示。

为了节省空间，用 `point3 p[N]` 存储所有可能出现的向量，结构体`plane`只记录向量在 `p[]` 中的下标。

记录的三个向量按逆时针首尾相接，这样在判断方向时比较方便。

```cpp
struct plane{
	int v[3]; //逆时针
	plane(){};
	plane(int a, int b, int c) { v[0] = a, v[1] = b, v[2] = c; }
};
```

**平面的法向量：**是指垂直于该平面的三维向量。一个平面具有无限个法向量，这些法向量有两个方向。

根据叉积的性质，将三角形的两条邻边叉乘，得到的向量即为法向量。

```cpp
Point3 normal() {
    return (p[v[1]] - p[v[0]]) * (p[v[2]] - p[v[0]]);
}
```

利用法向量的模长，也可以算出三角形的面积。

```cpp
double area() {
    return normal().len() / 2.0;
}
```

## 三维凸包及性质

由 $n$ 个点构成的凸多面体。

**性质：**根据欧拉公式，任意包含 $n$ 个顶点的凸多面体，所含的边不会超过 $3n-6$ 条，所含的小平面不会超过 $2n-4$ 张。

## 随机增量法

### 算法思想

和 Andrew 算法类似，考虑每次把 $p_r$ 加入到前 $r-1$ 个点的凸包中，也就是将 $\mathcal{CH}(P_{r-1})$ 转化为 $\mathcal{CH}(P_{r})$.

**第一种情况：**$p_r$ 在 $\mathcal{CH}(P_{r-1})$ 的内部或边界上，则 $\mathcal{CH}(P_{r-1})\rightarrow \mathcal{CH}(P_{r})$.

**第二种情况：**$p_r$ 在 $\mathcal{CH}(P_{r-1})$ 外部。设想你站在 $p_r$ 所在的位置，看向 $\mathcal{CH}(P_{r-1})$. $\mathcal{CH}(P_{r-1})$ 中的某些小平面会被看到，其余在背面的平面不会被看到。如下图，从 $p_r$ 可见的平面构成了一片连通的区域。

<img src="md-fig/fig11.svg" style="zoom: 200%;" />

这片区域由一条封闭折线围成，称这条线为 $p_r$ 在 $\mathcal{CH}(P_{r-1})$ 上的**边界线** $(\rm{horizon})$。

根据这条地平线，我们可以判断出，在原先 $\mathcal{CH}(P_{r-1})$ 表面上的哪些部分需要被保留，哪些需要被替换。

显然，不可见的平面在 $\mathcal{CH}(P_{r})$ 中被保留，并且我们用 $p_r$ 与地平线之间连接出新的小平面，来替换所有可见的小平面，如下图。

<img src="md-fig/fig12.svg" style="zoom: 200%;" />

### 判断平面对点的可见性

如何用几何语言表达：一个平面对 $p_r$ 是可见的？

<img src="md-fig/fig13.svg" style="zoom: 200%;" />

对于一个凸包上的小平面，它能将空间分为两半，一侧是凸包外部，一侧是凸包内部。容易发现，如果点 $p$ 位于小平面的外侧，那么这个平面对于 $p$ 点就是可见的，因为凸包上的其它平面都不会有遮挡。

形式化地，记 $a,b,c$ 为平面三角形的三个顶点，从凸包外部看，三点按照逆时针排列。

利用叉乘的性质，记 $\boldsymbol{s}=\overrightarrow{ab}\times \overrightarrow{ac}$，则结果向量 $\boldsymbol{s}$ 是一个平面的法向量，且指向凸包外部。

对于空间内任意一点 $p$，若 $\overrightarrow{ap}\times \boldsymbol{s}>0$，则这个平面对点 $p$ 是可见的。

下面是定义在结构体 `plane` 中的函数，用于判断点 $A$ 是否位于平面的外侧。

```cpp
bool is_above(Point3 A) {
    return (normal() & (A - p[v[0]])) >= 0;
}
```

### 求出边界线

要想把凸包从 $\mathcal{CH}(P_{r-1})$ 转化为 $\mathcal{CH}(P_{r})$，我们需要准确地求出凸包上的哪些边在边界线上。求出边界线之后，才能用 $p$ 与边界线构成的小平面替换需要被删掉的小平面。

定义 `bool g[N][N]`，$g[i][j]$ 表示 $\overrightarrow{p_ip_j}$ 所在的平面是否可见。

若规定平面 $(a,b,c)$ 只包含 $\overrightarrow{ab},\overrightarrow{bc},\overrightarrow{ca}$，则对于任意有序数对 $(i, j)$，向量 $\overrightarrow{p_ip_j}$ 最多被包含在一个平面内。

注意到，位于边界线上的向量 $\overrightarrow{p_ip_j}$ 一定满足 $g[i][j]=1$ 且 $g[j][i]=0$。所以我们只需对每个平面判断其可见性，并更新在 `g[][]` 中对应的数值，即可求出边界线。

### 利用边界线更新凸包

在上一步遍历小平面时，若遇到的小平面是不可见的，则把它加入新的凸包中；若可见，则单独记录。

之后遍历所有可见的小平面，若 $\overrightarrow{p_ip_j}$ 在边界线上，则把 $(p_i, p_j, p_r)$ 加入凸包中。$p_r$ 是新加入凸包的点。这样加入后的三点也满足逆时针排列。

### 参考代码

函数返回值为三维凸包的平面数，`plane ret[] `的下标从 $0$ 开始。

```cpp
int Convex_hull_3d(int n, plane *ret) {
	plane tmp[N];
	bool g[N][N];
	for (int i = 0; i < n; i++) p[i].shake();
	int top = -1;
	ret[++top] = plane(0, 1, 2);
	ret[++top] = plane(0, 2, 1);
	for (int i = 3; i < n; i++) {
		int cnt = -1;
		for (int j = 0; j <= top; j++) {
			bool flag = ret[j].is_above(p[i]);
			if (!flag)
				tmp[++cnt] = ret[j];
			for (int k = 0; k < 3; k++)
				g[ret[j].v[k]][ret[j].v[(k + 1) % 3]] = flag;
		}
		for (int j = 0; j <= top; j++) {
			for (int k = 0; k < 3; k++) {
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
```

# 旋转卡壳

## 概述

旋转卡壳算法用于：在线性时间内，求凸包直径、最小矩形覆盖等于凸包性质相关的问题。线性时间是指求出凸包之后的算法时间复杂度。

## 求凸包直径

> 给定平面上的 $n$ 个点，求所有点对之间的最长距离。$2\leq n\leq 50000, |x|, |y|\leq 10^4$.

首先，求出这 $n$ 个点的凸包，复杂度可以做到为 $\mathcal{O}(n\log n)$，如何求直径？

**暴力做法：**可以遍历每个点对，求出最大距离，复杂度为 $\mathcal{O}(n^2)$.

### 算法流程

可以遍历凸包上的边，对每条边 $(a, b)$，去找距离这条边最远的点 $p$。对于 $p$ 点，距离它最远的点，一定是 $a,b$ 中的一个。

我们发现，若逆时针遍历凸包上的边，那么随着边的转动，对应的最远点也在逆时针旋转。

因此，我们可以在逆时针枚举边的同时，实时维护最远点，利用单调性，复杂度为 $\mathcal{O}(n)$.

<img src="md-fig/fig14.gif" style="zoom: 150%;" />

### 算法实现

求凸包时，若使用 Andrew 算法，则凸包上的点已经按照逆时针排序了。问题在如何判断下一个点到当前边的距离是否更大。

一种方法是用点到直线距离公式，但利用叉积的精度更高，也更方便。

<img src="md-fig/fig15.svg" style="zoom: 120%;" />

```cpp
struct Point{
	int x, y;
    //......
	int sqr_len() { return x * x + y * y; }
};
inline int sqr_dis(Point a, Point b) { return (a - b).sqr_len(); }
int Get_Max(int n, Point *ch) {//传入convex-hull
	int ret = 0;
	ch[n] = ch[0];
	int j = 1;
	for(int i = 0; i < n; i++) {
		while((ch[i] - ch[j+1]) * (ch[i+1] - ch[j+1]) >
			  (ch[i] - ch[j]) * (ch[i+1] - ch[j]))
			j = (j + 1) % n;
		ret = max(ret, max(sqr_dis(ch[i], ch[j]), sqr_dis(ch[i+1], ch[j])));
	}
	return ret;
}
```

## 最小矩形覆盖

### 题意

给定一些点的坐标，求能够覆盖所有点的最小面积的矩形。

求出矩形面积、顶点坐标。$3\leq n\leq 50000$.

### 分析

先求出凸包，之后用旋转卡壳维护三个边界点。

利用叉积和点积，可以求出矩形面积及四个顶点的坐标。

### 实现

<img src="md-fig/fig16.svg" style="zoom: 120%;" />

下面是一种可行的表示方法。

设 $H=|P_0P_3|=\frac{|\overrightarrow{AB}\times \overrightarrow{BU}|}{|AB|}$，$L=\frac{|\overrightarrow{BA}\cdot \overrightarrow{AL}|}{|BA|}$，$R=\frac{|\overrightarrow{AB}\cdot \overrightarrow{BR}|}{|AB|}$.

则矩形面积为：
$$
S=H\times (L+|\overrightarrow{AB}|+R)
$$
顶点坐标为：
$$
\begin{array}{l}
&\overrightarrow{P_0}&=&\overrightarrow A+L\times \frac{\overrightarrow{BA}}{|\overrightarrow{BA}|}\\
&\overrightarrow{P_1}&=&\overrightarrow B+R\times \frac{\overrightarrow{AB}}{|\overrightarrow{AB}|}\\
&\overrightarrow{P_2}&=&\overrightarrow P_1+H\times \frac{\overrightarrow{P_1R}}{|\overrightarrow{P_1R}|}\\
&\overrightarrow{P_3}&=&\overrightarrow P_0+H\times \frac{\overrightarrow{P_0L}}{|\overrightarrow{P_0L}|}
\end{array}
$$
若不需要求出顶点坐标，也可以这样表示矩形面积：
$$
S=\frac{|\overrightarrow{AB}\times \overrightarrow{BU}|\times (|\overrightarrow{AD}\cdot\overrightarrow{AB}|+|\overrightarrow{BC}\cdot\overrightarrow{BA}|-|\overrightarrow{AB}\cdot\overrightarrow{BA}|)}{|\overrightarrow{AB}\cdot\overrightarrow{BA}|}
$$
设 $|\overrightarrow{P_0B}|=m$，$|\overrightarrow{AP_1}|=n$ 后易证。

### 代码

```cpp
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
```

## POJ2079 - Triangle

### 题意

给定平面上的 $n$ 个点，从其中任选三个点作为顶点，求能构成的最大三角形面积。

$1\leq n\leq 50000$.

### 分析

显然，三角形的顶点一定都在这 $n$ 个点的凸包上，所以先求出凸包。

考虑旋转卡壳。

这题中不能固定一条边，再枚举另外两个点，因为三角形的边不一定在凸包上。

因此，先逆时针枚举一个固定点 $i$，再逆时针旋转另外两个顶点 $j$ 和 $k$.·

由于凸包上的一些单峰性，我们旋转 $j$ 时停止的条件是 $S_{\triangle ijk}$ 最大，停止后固定 $j$，以相同停止条件旋转 $k$.

$S_{\triangle ijk}$ 最大，是指 $S_{\triangle i,j\operatorname{\_last},k}<S_{\triangle ijk}$ 且 $S_{\triangle ijk}>S_{\triangle i,j\operatorname{\_next},k}$.

### 代码

注意特判 $n\leq 2$ 以及凸包大小 $\operatorname{siz}\leq 2$ 的情况。用叉积求面积。

```cpp
double Get_Max(int n, Point *ch) {
	double ret = 0;
	ch[n] = ch[0];
	int j = 1, k = 2;
	for(int i = 0; i < n; i++) {
		while(Vec(ch[i], ch[j]) * Vec(ch[i], ch[k]) <
			  Vec(ch[i], ch[j]) * Vec(ch[i], ch[k+1]))
			k = (k + 1) % n;
		while(Vec(ch[i], ch[j]) * Vec(ch[i], ch[k]) <
			  Vec(ch[i], ch[j+1]) * Vec(ch[i], ch[k]))
			j = (j + 1) % n;
		ret = max(ret, Vec(ch[i], ch[j]) * Vec(ch[i], ch[k]));
	}
	return ret;
}
```

# 半平面交

## 半平面

半平面是**一条直线和直线的一侧**，是一个点集。

当点集包含直线时，称为闭半平面；当不包含直线时，称为开半平面。

## 直线类

在计算几何中，用 $(\boldsymbol s, \boldsymbol t)$ 表示直线 ${st}$，一般统一保留向量的左侧半平面。

### 求两直线的交

<img src="md-fig/fig17.svg" style="zoom: 110%;" />

若交点存在，只需求出 $t=\dfrac{|A_sP|}{|A_sA_t|}$，则 $\overrightarrow P=\overrightarrow{A_s}+t\cdot  \overrightarrow{A_sA_t}$.

注意到 $t=\dfrac{|A_sP|}{|A_sA_t|}=\dfrac{|\overrightarrow{B_sB_t}\times \overrightarrow{B_sA_s}|}{|\overrightarrow{B_sB_t}\times \overrightarrow{A_sA_t}|}$，证明也不难。

如上图，把 $\overrightarrow{A_sA_t}$ 平移到 $\overrightarrow{B_sC}$ 的位置，则可以把叉乘的模看作平行四边形面积。

记 $S_1=|\overrightarrow{B_sB_t}\times \overrightarrow{B_sA_s}|$，$S_2=|\overrightarrow{B_sB_t}\times \overrightarrow{A_sA_t}|$，由于两个平行四边形同底，所以有 $\dfrac{S_1}{S_2}=\dfrac{|A_sM|}{|CN|}$.

又因为 $\triangle A_sMP\sim \triangle CNB_s$，所以 $\dfrac{S_1}{S_2}=\dfrac{|A_sM|}{|CN|}=\dfrac{|A_sP|}{|CB_s|}=\dfrac{|A_sP|}{|A_sA_t|}$.

### 参考代码

```cpp
struct Line{
	Point s, t;
	Line() {};
	Line(Point a, Point b) : s(a), t(b) {}
	double ang() { return atan2((t - s).y, (t - s).x); };
	Line(double a, double b, double c) { //ax + by + c = 0
		if(sgn(a) == 0) s = Point(0, -c/b), t = Point(1, -c/b);
		else if(sgn(b) == 0) s = Point(-c/a, 0), t = Point(-c/a, 1);
		else s = Point(0, -c/b), t = Point(1, (-c-a)/b);
	}
	friend bool parallel(const Line &A, const Line &B) {
		return sgn((A.s - A.t) * (B.s - B.t)) == 0;
	}
	friend bool Calc_intersection(const Line &A, const Line &B, Point &res) {
		if(parallel(A, B)) return false;
		double s1 = (B.t - B.s) * (B.s - A.s);
		double s2 = (B.t - B.s) * (A.t - A.s);
		res = A.s + (A.t - A.s) * (s1 / s2);
		return true;
	}
};
```

## 半平面交

半平面交是**多个半平面的交集**。

半平面交是一个点集，并且是一个凸集。在直角坐标系上是一个区域。

半平面交在代数意义下，是若干个线性约束条件，每个约束条件形如：
$$
a_ix+b_iy\leq c_i
$$
其中 $a_i, b_i, c_i$ 为常数，且 $a_i$ 和 $b_i$ 不都为零。

半平面交有下面五种可能情况，每个半平面位于边界直线的阴影一侧。

<img src="md-fig/fig18.svg" style="zoom: 200%;" />

$\rm{(iii)}$ 和 $\rm{(v)}$ 比较特殊，我们一般假设产生的交集总是有界或空的。

## 性质

注意到，位于半平面交边界上的任何一个点，必定来自某张半平面的边界。

并且，因为半平面交是凸集，所以每条边界线最多只能为边界贡献一条边。

因此：**由 $n$ 张半平面相交而成的凸多边形，其边界最多由 $n$ 条边围成**。

## Sort-and-Incremental Algorithm

S&I 算法，排序增量法。

### 算法思想

S&I 算法利用了性质：半平面交是凸集。

因为半平面交是凸集，所以我们**维护凸壳**。

若我们把半平面按极角排序，那么在过程中，**只可能删除队首或队尾的元素**，因此使用**双端队列**维护。

下面是一个例子。

TODO.

### 算法流程

1. 把半平面按照极角序排序，需要 $\mathcal{O}(n\log n)$ 的时间。
2. 对每个半平面，执行一次增量过程，每次根据需要弹出双端队列的头部或尾部元素。这是线性的，因为每个半平面只会被增加或删除一次。
3. 最后，通过双端队列中的半平面，在线性时间内求出半平面交（一个凸多边形，用若干顶点描述）。

这样，我们得到了一个时间复杂度为 $\mathcal{O}(n\log n)$ 的算法，瓶颈在于排序。因此，若题目给定的半平面满足极角序，则我们可以在线性的时间内求出半平面交。

### 极角排序

注意判断不要写成 `<=` 或 `>=`。

```cpp
inline bool cmp(Line A, Line B) {
	//极角相等时，位置靠右的排在前面
	if(!sgn(A.ang - B.ang)) return (A.t - A.s) * (B.t - A.s) > 0;
	return A.ang < B.ang;
}
```

### 求半平面交

```cpp
bool Halfplane_intersection(int n, Line *hp, Point *p) {
	if(n < 3) return false;
	sort(hp, hp + n, cmp);
	Halfplane_unique(n, hp);
	st = 0; ed = 1;
	que[0] = 0; que[1] = 1;
	if(parallel(hp[0], hp[1])) return false;
	Calc_intersection(hp[0], hp[1], p[1]);
	for(int i = 2; i < n; i++) {
		while(st < ed &&
			  sgn((hp[i].t - hp[i].s) * (p[ed] - hp[i].s)) < 0)
			ed--;
		while(st < ed &&
			  sgn((hp[i].t - hp[i].s) * (p[st + 1] - hp[i].s)) < 0)
			st++;
		que[++ed] = i;
		assert(ed >= 1);
		if(parallel(hp[i], hp[que[ed - 1]])) return false;
		Calc_intersection(hp[i], hp[que[ed - 1]], p[ed]);
	}
	while(st < ed &&
		  sgn((hp[que[st]].t - hp[que[st]].s) * (p[ed] - hp[que[st]].s)) < 0)
		ed--;
	while(st < ed &&
		  sgn((hp[que[ed]].t - hp[que[ed]].s) * (p[st + 1] - hp[que[ed]].s)) < 0)
		st++;
	if(st + 1 >= ed) return false;
	return true;
}
```

### 求凸多边形的顶点

```cpp
int Get_convex_hull(Line *hp, Point *p, Point *ch) {
	Calc_intersection(hp[que[st]], hp[que[ed]], p[st]);
	for(int i = 0, j = st; j <= ed; i++, j++) ch[i] = p[j];
	return ed - st + 1;
}
```

### 计算面积

```cpp
double Calc_area(int n, Point *ch) {
	double ans = 0;
	for (int i = 2; i < n; i++)
		ans += area(ch[0], ch[i - 1], ch[i]);
	return ans;
}
```

# P3256 [JLOI2013]赛车

## 题目描述

赛场上一共有 $n$ 辆车，分别称为 $g_1,g_2,...,g_n$.

赛道是一条无限长的直线。最初，$g_i$ 位于距离起跑线前进 $x_i$ 的位置。比赛开始后，车辆 $g_i$ 将会以 $v_i$ 单位每秒的恒定速度行驶。

过程中，如果一辆赛车曾经处于领跑位置的话，即没有其他的赛车跑在他的前面，这辆赛车最后就可以得奖。

求哪些赛车将会得奖。输出赛车编号。

$1\leq n\leq 10^4$，$0\leq x_i\leq 10^9$，$0\leq v_i\leq 10^9$.

## 分析

可以想到，每辆车的 $x-t$ 图像都是一条直线。在平面直角坐标系上画出这些直线。

若取每条直线的左侧半平面，再与 $x$ 轴上侧平面、$y$ 轴右侧平面一起求交，则所有凸多边形上的直线可以获奖。

直接跑排序增量法即可，时间复杂度 $\mathcal{O}(n\log n)$.

注意到这题 $x_i$ 和 $v_i$ 的值域均为 $10^9$，所以运算过程中的数值会达到 $10^9\times 10^9=10^{18}$，

因此需要使用 `long double`，并且需要 `const long double eps = 1e-18`.

## 代码

这道题不能直接去重，因为需要输出获奖车辆的编号，所以用 `std::map` 维护。

同时，还需要在 `Line` 类中存储所有重合直线的编号，用 `std::vector` 维护。

```cpp
struct Line{
	Point s, t;
	vector<int> id;
	Line() {};
	Line(Point a, Point b) : s(a), t(b) {}
	Line(Point a, Point b, vector<int> c) : s(a), t(b), id(c) {}
	//...
};
//...
signed main() {
	int n, x[MAXN], v[MAXN], N = 0;
	map<pair<int, int>, vector<int> > mp;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> x[i];
	for(int i = 1; i <= n; i++) cin >> v[i];

	for(int i = 1; i <= n; i++) mp[make_pair(x[i], v[i])].push_back(i);
	L[N++] = Line(Point(0, 1), Point(0, 0));
	L[N++] = Line(Point(0, 0), Point(1, 0));
	for(auto it = mp.begin(); it != mp.end(); it++) {
		pair<int, int> tmp = it -> first;
		L[N++] = Line(Point(0, tmp.first),
					  Point(1, tmp.first+tmp.second), it -> second);
	}

	Halfplane_intersection(N, L, p);

	int ans[MAXN], cnt_ans = 0;
	for(int i = st + 1; i <= ed; i++) {
		for(int j = 0; j < L[que[i]].id.size(); j++) {
			ans[cnt_ans++] = L[que[i]].id[j];
		}
	}
	sort(ans, ans + cnt_ans);
	cout << cnt_ans << endl;
	for(int i = 0; i < cnt_ans; i++) cout << ans[i] << " "; cout << endl;
	return 0;
}
```

# P4250 [SCOI2015]小凸想跑步

## 题目描述

小凸晚上喜欢到操场跑步，今天他跑完两圈之后，他玩起了这样一个游戏。

操场是个凸 $n$ 边形， $n$ 个顶点**按照逆时针**从 $0$ ∼ $n - 1$ 编号。

现在小凸**随机**站在操场中的某个位置，标记为 $p$ 点。将 $p$ 点与 $n$ 个顶点各连一条边，形成 $n$ 个三角形。

如果这时 $p$ 点， $0$ 号点， $1$ 号点形成的三角形的面积是 $n$ 个三角形中**最小**的一个，则认为这是一次正确站位。

现在小凸想知道他一次站位正确的**概率**是多少。

## 分析

<img src="md-fig/fig19.svg" style="zoom: 90%;" />

推一点式子。

设 $\overrightarrow A=(x_a,y_a)$，$\overrightarrow B=(x_b, y_b)$，$\overrightarrow C=(x_c, y_c)$，$\overrightarrow D=(x_d, y_d)$，$\overrightarrow P=(x, y)$.

由题意，
$$
\begin{array}{rl}
|\overrightarrow {AB}\times \overrightarrow{AP}|&<&|\overrightarrow {CD}\times \overrightarrow{CP}|\\
(x_b-x_a)(y-y_a) - (y_b-y_a)(x-x_a) &<& (x_d-x_c)(y-y_c)-(y_d-y_c)(x-x_c)\\
\end{array}
$$
展开得，
$$
\begin{array}{rl}
\text{左式}&=&(x_b-x_a)y-x_by_a+x_ay_a-(y_b-y_a)x+x_ay_b-x_ay_a\\
\text{右式}&=&(x_d-x_c)y-x_dy_c+x_cy_c-(y_d-y_c)x+x_cy_d-x_cy_c
\end{array}
$$
合并同类项，
$$
\begin{array}{l}
&(x_b - x_a)(y - y_a) - (y_b - y_a)(x - x_a) < (x_d - x_c)(y - y_c) - (y_d - y_c)(x - x_c) \\
\Rightarrow & (x_b - x_a + x_c - x_d)y + (y_a - y_b + y_d - y_c)x + (y_b x_a - x_b y_a - y_d x_c + x_d y_c) < 0
\end{array}
$$
注意到，这是直线解析式的形式，于是转化为了半平面交问题。



# 参考资料



https://cp-algorithms.com/geometry/halfplane-intersection.html

