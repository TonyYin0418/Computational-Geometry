凸包与半平面交问题研究

蔡越同，李灏冬，尹玉文东，张钰晨



凸包是平面上能包含所有给定点的最小凸多边形，半平面交是多个半平面的交集。课题将对凸包和半平面交问题的求解方法进行研究，对其在算法竞赛中的应用问题进行分类，
并探究若干典型模型的解法。

凸包；半平面交；计算几何；

# 绪论

随着信息技术的大范围普及，算法竞赛的影响力与日俱增。计算几何在算法竞赛中有着重要应用，凸包和半平面交是计算几何中的经典问题。

计算几何是基于向量运算的体系。相较于解析几何，计算几何能有效控制计算机运算中的浮点数精度问题，更适用于算法竞赛。

本课题组使用c++语言编写了计算几何工具库，并利用其研究了这两类问题的解法，随后分析并提取出部分典型模型。

# 计算几何库及有关说明

本文的研究均在平面下进行，若无特殊说明，两向量叉乘的结果默认代表结果向量的模长。

本文的参考代码可能直接调用库中函数，计算几何库的代码详见附件一。

下面是工具库的功能及部分原理解释。

## 浮点数相关函数

为了避免浮点数运算造成的精度问题，编写了相关函数用于控制精度。

包含功能：判断一个数的正负、比较两个数的大小。

## 向量类

向量类用于解决二维向量的相关运算问题，包含下列功能。

1. 向量的加法、减法、数乘、点积、叉积（仅求模长）；
2. 求向量的模长；
3. 求两向量之间的夹角；
4. 对一组向量按照字典序（坐标序）或极角排序

## 直线类

对于直线上任意两点 $A(x_a, y_a)$，$B(x_b, y_b)$，构造坐标对应的向量 $\vec s=(x_a, y_a)$，$\vec t=(x_b, y_b)$，直线类利用向量类，记录这两个向量 $\vec s$ 和 $\vec t$。

包含下列功能：

1. 利用直线上两点构造直线；
2. 判断两直线是否平行；
3. 求两直线交点。

## 极角排序的原理

取笛卡尔坐标系中的 $x$ 轴作为极轴，以逆时针方向为正。

利用c语言中的 `std::atan2(double y, double x)` 进行极角排序，函数的返回值为 $(x, y)$ 与 $x$ 轴的极角 $\theta \in(-\pi, \pi]$.

## 求两直线交点的原理



<img src="C:\Users\TonyYin\Desktop\Github\Computational-Geometry\md\md-fig\fig17.svg" style="zoom: 110%;" />

首先判断直线是否平行，若平行则不存在交点。

否则，如图-------，直线 $A$ 为 $(A_s, A_t)$，直线 $B$ 为 $(B_s, B_t)$，求 $A$ 与 $B$ 的交点。

函数只需求出 $t=\dfrac{|A_sP|}{|A_sA_t|}$，则交点 $\overrightarrow P=\overrightarrow{A_s}+t\cdot  \overrightarrow{A_sA_t}$，证明如下。

注意到 $t=\dfrac{|A_sP|}{|A_sA_t|}=\dfrac{|\overrightarrow{B_sB_t}\times \overrightarrow{B_sA_s}|}{|\overrightarrow{B_sB_t}\times \overrightarrow{A_sA_t}|}$，

把 $\overrightarrow{A_sA_t}$ 平移到 $\overrightarrow{B_sC}$ 的位置，则可以把叉乘的模看作平行四边形面积。

记 $S_1=|\overrightarrow{B_sB_t}\times \overrightarrow{B_sA_s}|$，$S_2=|\overrightarrow{B_sB_t}\times \overrightarrow{A_sA_t}|$，因为两个平行四边形同底，所以有 $\dfrac{S_1}{S_2}=\dfrac{|A_sM|}{|CN|}$.

又因为 $\triangle A_sMP\sim \triangle CNB_s$，所以 $\dfrac{S_1}{S_2}=\dfrac{|A_sM|}{|CN|}=\dfrac{|A_sP|}{|CB_s|}=\dfrac{|A_sP|}{|A_sA_t|}$.

# 凸包

## 相关定义

#### 凸包(Convex Hull)

一个子集 $S$ 被称为凸的，当且仅当对于任意两点 $p,q∈S$，线段 $\overline {pq}$ 都完全属于 $S$。

集合 $S$ 的凸包 $\mathcal {CH}(S)$，是包含 $S$ 的最小凸集，也就是包含 $S$ 的所有凸集的交。

如。。图，形象地，凸包是平面上能包含所有给定点的最小凸多边形。

### 求解方式

#### 基础算法

注意到，若线段 $\overline {pq}$ 在凸包上，则 $P$ 中的点均位于直线 $\overline {pq}$ 的同一侧。若我们钦定 $p→q$ 按顺时针方向，则有更强的限制，需要 $P$ 中的点都在直线的右侧。

考虑向量的叉积形式下，点 $t$ 在 $\vec {pq}$ 右侧 $⟺$ $\vec {pt} × \vec {pq} > 0$。于是可以枚举有序点对 $(p,q)∈P×P$，若 $P$ 中的点都在有向线段 $\overline {pq}$ 的右侧，则 $\overline {pq}$ 是 $\mathcal {CH}(P)$ 中的一条边。

此算法时间复杂度为 $$\mathcal{\Theta}(n ^ 3)$$。其中 $n$ 为点数。

#### Andrew 算法

首先把所有点排序，以横坐标为第一关键字，纵坐标为第二关键字。排序后，第一个点和末尾的点，一定在凸包上，容易通过反证法证明。从左往右看，上下凸壳斜率的 单调性相反，即所旋转的方向不同，所以要分开求解。升序枚举求出下凸壳，然后 降序枚举求出上凸壳，这样凸包的每条边都是向逆时针方向旋转的。

设当前枚举到点 $P$，即将把其加入凸包；当前栈顶的点为 $S_1$，栈中第二个点为 $S_2$。求凸包时，若 $P$ 与 $S_1$ 构成的新线段是顺时针旋转的，即叉积满足：$\overrightarrow{S_2S_1}\times \overrightarrow{S_1P}<0$，则弹出栈顶，继续检查，直到 $\overrightarrow{S_2S_1}\times \overrightarrow{S_1P}\ge 0$ 或者栈内仅剩一个元素为止。

记 $n=|P|$，则时间复杂度为 $\mathcal{\Theta}(n\log n)$，瓶颈在排序部分。

相较于基础算法，Andrew 算法的效率大幅提升。

算法的代码实现如下：

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

### 凸包在算法竞赛中的应用

#### 求覆盖点集的最小凸多边形周长

此类问题即可转化为求凸包周长。

先求出按照顺时针排序的，构成凸包的点集 $p$，记 $n=|p|$。再把相邻两点组成的向量的模长求和，即：
$$
l=\sum_{i=1}^n|\overrightarrow{p_{i}p_{i+1}}|+|\overrightarrow{p_{1}p_{n}}|
$$
代码实现如下：

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

#### 求覆盖点集的最小凸边形的面积

此类问题即可转化为求凸包面积。

先求出按照顺时针排序的，构成凸包的点集 $p$，记 $n=|p|$。任取凸包内一点（一般取 $p_1$），则有：
$$
s=\sum_{i=2}^{n-1} \operatorname{area}(p_1, p_i, p_i+1)=\sum_{i=2}^{n-1}\frac{|(p_i-p_1)\times (p_{i+1}-p_1)|}{2}
$$
代码实现如下：

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

#### 维护动态凸包（支持插入点和查询凸包内的点）

用两个 `std::map<int, int>`，其中 $\operatorname{top}$ 记录上凸包，$\operatorname{down}$ 记录下凸包。

若上凸包中存在横坐标为 $x$ 的点，则这个点的纵坐标为 $\operatorname{top}[x]$，$\operatorname{down}$ 同理。

###### 查询操作

若一个点在上凸包之下且在下凸包之上则其在凸包内。

以上凸包为例。$i$ 在上凸包之下，当且仅当 $|\overrightarrow{ik}\times \overrightarrow{ij}|\geq 0$。

代码实现如下：

```c++
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
```

##### 插入操作

把 $p$ 点加入凸包，上下凸包都要尝试。把加入 $p$ 点后，删掉不满足凸性的点。因此可以找到 $p$ 点在上（下）凸壳中的位置，向左右分别删点，直到满足凸性。

代码实现如下：

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

### 凸包在生活中的应用

#### 包围盒算法

其广泛应用于与游戏物理引擎的制作中。

游戏过程中，游戏中的元素有时会发生碰撞，且这些元素的形状通常不规则。如果直接对不规则元素进行彭专检测会使得游戏效率低下，由此产生了一个近似算法，即包围盒算法。

其中包围盒指能完整覆盖元素的矩形。在游戏应用中为了使图形拟合更准确以及更简单地对游戏元素进行操作，通常会将以最小包围盒代替游戏中的不规则元素。

此问题即可转换为凸包问题进行求解。

#### 碰撞检测及避免算法

其广泛应用与 $$\text{3D}$$ 游戏中。这可以使人物在场景中可以平滑移动、遇到一定高度的障碍物可以越过而遇到过高的障碍物则停下、在各种前进方向被挡住的情况下都要尽可能地让人物沿合理的方向滑动而不是被迫停下。在满足这些要求的同时还可以做到足够精确和稳定。

在这个算法中，多维凸包可以用于找出人物轮廓，并简化后续计算及判断过程。

#### 光的传播问题

此类问题指给定若干障碍物，并规定光的传播方向，求哪些障碍物是可见的。

最基础的模型即为所有障碍物均为直线。即若在 $x-y$ 直角坐标平面上有 $n$ 条直线 $L_1,L_2,…L_n$，若在 $y$ 值为正无穷大处往下看，求出所有可见的直线每条直线 $L_i$ 均可表示为 $y=k \times x + b$ 的形式。

这个模型有一个性质，即从上往下看到的图像一定是一个下凸的图像。因此可以转化为凸包可解决的问题，只需求出“下凸壳”即可。

# 半平面交

## 相关定义

### 半平面

半平面是一条直线和直线的一侧，是一个点集。

当点集包含直线时，称为闭半平面；当不包含直线时，称为开半平面。

### 半平面交

半平面交是多个半平面的交集。

半平面交是一个点集，并且是一个凸集。在直角坐标系上是一个区域。

半平面交在代数意义下，是若干个线性约束条件，每个约束条件形如：
$$
a_ix+b_iy\leq c_i
$$
其中 $a_i, b_i, c_i$ 为常数，且 $a_i$ 和 $b_i$ 不都为零。

## 求解方式——Sort-and-Incremental 算法

### 算法思想

S&I 算法利用了性质：半平面交是凸集。

因为半平面交是凸集，所以我们维护凸壳。

若我们把半平面按极角排序，那么在过程中，只可能删除队首或队尾的元素，因此使用双端队列维护。

### 算法流程

1. 把半平面按照极角序排序，需要 $\mathcal{O}(n\log n)$ 的时间。
2. 对每个半平面，执行一次增量过程，每次根据需要弹出双端队列的头部或尾部元素。这是线性的，因为每个半平面只会被增加或删除一次。
3. 最后，通过双端队列中的半平面，在线性时间内求出半平面交（一个凸多边形，用若干顶点描述）。

这样，我们得到了一个时间复杂度为 $\mathcal{O}(n\log n)$ 的算法，瓶颈在于排序。因此，若题目给定的半平面满足极角序，则我们可以在线性的时间内求出半平面交。

### 代码实现

实现过程中，用直线类表示半平面。直线 $(S, T)$ 表示 $ST$ 左侧的半平面。

形式化地，若点 $P$ 位于直线 $(S, T)$ 表示的半平面中，则 $\overrightarrow {ST}\times \overrightarrow {SP}>0$.

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

## 半平面交的应用

### 赛车问题

有一种赛车的获奖方式为若在比赛过程中一辆赛车存在一个时刻处于领跑位置上即可获奖。

为简化问题，视每辆赛车均匀速行驶。则每辆车的 $x-t$ 图像是一条直线。由图像的几何意义，若取每条直线的左侧半平面，再与 $x$ 轴上侧平面、$y$ 轴右侧平面一起求交，则所有凸多边形上的直线可以获奖。问题转化为半平面交问题。

瞭望塔的建设

在国防和军事上，瞭望塔的建设是必不可少的。对于瞭望塔的基本需求是在满足可以观察到整个规定区域的任意位置，且费用尽可能小。

为使费用尽可能小，每座瞭望塔的高度就需尽可能低。不妨用若干条直线来拟合出一个营地的轮廓。把每条线看成一个指向右的向量，它所在直线可以把这个平面分成左右两部分。要想让一条线上每处都被瞭望台看到，需把瞭望台建在其左半平面。这样， $n$  条直线就有 $n$ 个需求，要想全部满足，瞭望台顶端就必须建到这些半平面的交处。

### 道路通行

一些道路会因各种原因无法行走，为节约时间又需要找到最短的一条路径。

此时不妨先用凸包拟合一个地区的形状以及直线拟合每条道路。可以发现沿着可以通行的道路最内侧的道路走一定最短，证明如下：

使用数学归纳法证明。

假设最内侧路径上的点数等于 $n$ (不包括 $2$ 个端点) 时，最内侧路径是最短路径。则有

① 当 $n=0$ 即最内侧路径为一条线段时，命题成立。

② 令当 $n = k$ 时命题成立，当 $n=k+1$ 时，取出最内侧路径和任意一条外侧路径，如下图所示：

![证明图](https://cdn.luogu.com.cn/upload/image_hosting/f0rakpm7.png)

延长 $\text{AE}$ 交 $\text{EG}$ 于点 $I$，有：
$$
AE+EF+FG+GH+HD \ge AI+IG+GH+HD = AB+BI+IG+GH+HD
$$
又因为有：
$$
BI+IG+GH+HD \ge BC+CD
$$
综上，有：
$$
AE+EF+FG+GH+HD \ge AB+BC+CD
$$
则当 $n=k+1$ 时命题成立。

综合-------------可知命题成立。结论成立。

由上述结论最短问题可以转化为半平面交问题。

# 结语

本文对凸包与半平面交两类问题在算法竞赛及生活中的应用进行了研究。除此之外，这两类问题还在其他多个领域有所应用，特别是图像处理相关行业。

对凸包和半平面交问题的典例整理，可以作为他人学习时的参考资料，使人们在应对算法竞赛中的相关问题时，有更灵活的方法。

# 参考文献

[1]Thomas,H.Cormen,Charles,E.Leiserson,Ronald,L.Rivest,Clifford,Stein, 殷建平,徐云,王刚,刘晓光,苏明,邹恒明,王宏志. 算法导论(原书第 3 版)[J]. 计算机教育, 2013(10):1.

[2]林厚从.信息学奥赛之数学一本通[M].南京:东南大学出版 社,2016:203-297. 

[3]人民教育出版社 课程教材研究所 中学数学教材实验研究组.普通 高中教科书 数学（B 版）必修 第二册[M].北京:人民教育出版 社,2019:131-172.
