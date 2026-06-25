# 12_21

### **从这里开始：** https://www.bilibili.com/video/BV1et411b73Z?t=13.4&p=187

驯服VS Code：按 F6 编译且运行。。。

解决中文乱码问题：将UTF-8该为GBK，再按一下“Ctrl+Z”

**21**

构造函数

vector容器的语法：vector<类名> p；

往容器中插入数据：p.push_back(...);

迭代器遍历容器

函数的参数中的*，&，意味着“改变”

变量中的*，意味着“指针”

->：是专门为指针准备的

**.** 是专门给“类”使用的


### string容器
---

**23**

string的本质是一个类，同时是一个char*型的容器

**24**

注意，string类型的变量（自定义类）之所以能像普通变量那样运算，是因为运算符重载，.assign是更为原始的函数实现方法

**赋值**
.assign(‘'hello world'’,5)：表示在“hello world”中取前五个字符，简述“hello world”中的前五个

.assidn(10,‘a’)：表示把‘a’字符取十个，简述10个‘a’

**25**

**附加**
str.append("game steam")函数方法  等价于=>  str += "game steam" 

**26**

**查找（find）**
.find(“”)：在字符串中查找，返回 **int** 类型值（从0开始）表示位置，没找到返回 **-1**

.rfind(“”)：从右往左找

**替换（replace）**
.replace(1,3,"1111") 表示从1号位置起三个字符 替换为 “1111”

**27**

**比较**
str1.compare(str2) == 0 : str1和str2是否相等

**28**

通过 **[]** 访问单个字符

.at(i) 等价于 => [i]

**29**

**插入**
.insert（1,"111"）在1号位置插入字符“111”

**删除**
.erase（1，3）擦去（删除）从1号位置开始的3个字符

**30**

**获取**
.substr(1,3) 获取从1号位置到3号位置的字串

**查找+获取**
.substr(0,str.find("@")) 一个查找+获取的实用案例

**总结**

来学几个新单词😀：
- 赋值（=）- **assign**
- 附加（+=）- **append**
- 查找（返回int数值）- f**ind / rfind**
- 替换（1,3,""）- **repalce**
- 比较（ = =，<，>） - **compare**
- 插入 - **insert**
- 删除 - **erase**
- 获取字符串 - **substr**

### vector容器
---

**31**

两个关键词 **单端，动态**
- 单端：类似于一个栈
- 动态：扩展是不是在原来的基础上开辟新空间，而是找一块更大的**新空间**

**首地址**
.begin()：第0号位置

**尾地址**
.end()：最后一个位置

**构造方式（已有v1的前提下）**
~~~
// 通过区间构造
vector<int>v2(v1.begin(),v1.end());
// n个elem值构造
vector<int>v2(10,1);
// 拷贝构造
vector<int>v2(v1);
~~~

**32**

**赋值**
~~~
vector<int>v2;
// 通过区间赋值
v2.assign(v1.begin(),v1.end());
// n个elem值赋值
v2.assign(10,1); 
~~~

**33**

判断是否为**空**
.empty()

**容量**
.capacity()

**大小**
.size()

注意区分容量和大小这两个概念（容量>=大小），说明vector容器总是容易有未使用的空间

**重新指定大小**
.resize()

分为重新指定的大小比原来长或短 **两种情况**


**34**

**尾插**
.push_back();

**尾删**
.pop_back()

**插入**
.insert(v1.begin(),100); 表示在第0号位置插入数值100

.insert(v1.begin(),int count,100); 表示在第0号位置插入count个100

**删除**
.erase(v1.begin()); 表示删除第0号位置的数据

.erase(v1.begin(),v1.end()); 区间清空

**插入和删除的参数是迭代器！！！**
**插入和删除的参数是迭代器！！！**
**插入和删除的参数是迭代器！！！**

**35**

**访问**
.at(i)  等价于=>  [i]

.front()  返回第一个元素
.back()  返回最后一个元素

**36**

**交换**
v1.swap(v2);  交换v1和v2

**巧用swap()可以收缩空间，可以避免vector容器过分地扩展容量**

**37**

~~~
// 一种统计vector容器开辟次数的方法
int num = 0;
int * p = NULL;
if(p != v[0])
{
	p = &v[0]; // 取地址
	num++;
}
~~~


**预留空间**

v.reserve(10000);

**reserve一下可以减少开辟空间的次数**

**总结**
- 区分容量和大小
- 了解vector容器新开辟空间的特性，并知道如何缩减空间
- 新的函数方法：empty(),reserve(),erase()

### deque容器（双端队列）
****

**38**

**deque**相比于vector更适用于头部的插入和删除

**vector**访问元素的速度比deque快

**中控器**

使得deque使用是像一片连续的内存空间

**构造**

~~~
deque<int> d1;
// 区间构造
deque<int>d2(d1.begin(),d1.end());
// n个elem值构造
deque<int>d2(10,1);
// 拷贝构造
deque<int>d2(d1);
// 添加数据i
d1.push_back(i);
~~~


**记得包含deque头文件**

**39**

**赋值**

// 区间赋值
.assign(d1.begin(),b1.end());  等价于=>  “=”
// n个elem值赋值
.assign(10,1); 

**40**

**注意，deque容器中没有容量的概念，**

**...是否为空**

.empty()

**大小**

.size()

**重新指定大小**

.resize()

**分为大于和小于原来大小的两种情况**

**41**

**头插**

.push_front(elem);  ---> 前面说了，头插是deque相比于vector的一大优势

**尾插**

.push_back(elem);

**头删**

.pop_front();

**尾删**

.pop_back();

**插入**

.insert(pos,elem);  // 在第pos号位置上插入元素elem

.insert(pos,n,elem); // 在第pos号位置上插入n个elem元素

.insert(pos,beg,end); // 在第pos号位置上插入从beg到end区间的数据

**注意，是左闭右开区间！！！**
**注意，是左闭右开区间！！！**
**注意，是左闭右开区间！！！**

**删除**

.erase(beg,end); // 区间删除

.erase(pos); // 删除某号位置的单个元素

**42**

.at  =  []

.front() 返回第一个元素

.back() 返回最后一个元素

**43**

**sort排序，一个来自algorithm头文件的算法**

algorithm
algorithm
algorithm

sort(d1.begin(),d1.end()); 
- ① 函数参数要用迭代器
- ② 同时支持vector和deque

# 12_30 

### stack容器
*******

**45**

**概念：** stack容器一种先进后出的**数据结构**，它只有一个出口，重申一遍，它是一种数据结构！

**注意**，栈不允许遍历的行为，或者说栈查找元素的过程不符合遍历的概念

**46**

**构造**
~~~
//
stack<type>s;
//拷贝构造函数
stack(const stack &stk); 
~~~

**入栈**
.push()

**出栈**
.pop()

**注意**，这里的push和pop没有带 “ _ ”  ，  说明没有区分front和back

**大小**
.size()

**判断是否为空**
.empty()


### queue容器
*******

**47**

**概念**，一种先进先出的数据结构，相比于stack容器，它有两个出口

**48**

**构造**
~~~
//
queue<type> que;
//拷贝构造
queue(const queue &que)
~~~

**入队**
.push(elem) ---》 队尾插入

**出队**
.pop() ---》队头弹出

**返回值**
.back() ---》返回队尾
.front() ---》返回队头

**大小操作**
.empty() ---》大小是否为零（是否为空）
.size() ---》返回队列的大小

**总结**
- 队列有两个端口，而栈只有一个
- 队列的两个端口一个用于出队，另一个用于入队
- 栈只有一个端口，出栈和入栈都在一个端口
- 队列和栈的特性使其在访问数据元素的时候不满足**遍历**的条件
最后，队列和栈都是一种思维模型，方便解决各类问题


### list容器
*******

**49**

链表，在物理存储上不连续，在逻辑顺序上连续

**注意**，STL中的链表是一个**双向链表**

链表由一个个节点构成，节点里包含数据域和指针域

**为什么链表的占用空间比数组大？**
答：简单来说，链表占用空间更大的主要原因在于，它存储的不仅仅是数据本身，还要存储额外的“指针”（或引用），用来维护元素之间的逻辑关系。
https://chat.deepseek.com/share/j68loh1z8sye2ymnmi

list使用的迭代器是**双向迭代器**，只支持前移和后移，就是说只能一个一个地访问，而不像数组的迭代器那样能跳跃式地访问

“那么下节课我们再去介绍这个list容器的一些常用的API接口”
这里的**API接口**指的是像.push  .pop这样的函数

链表其实就是用时间（遍历）和空间（指针域）换取了数组的那些缺点

**50**

迭代器遍历的语法
~~~
for(Container<type>::const_iterator it = X.begin(); it != X.end(); it++)
{
	cout << *it << " ";
}
//container表示容器 type表示数值类型 需要注意的是const_iterator的写法
~~~

**构造**
~~~
//
list<int>L1;
//区间&拷贝构造
list<int>L2(L1.begin(),L1.end());
//拷贝构造
list<int>L2(L1);
//n个elem值构造
list<int>L2(n,elem);
~~~

**51**

**赋值**
~~~
//构造
list<int>L1;
list<int>L2;
//operator "=" 赋值
L2 = L1;
//函数方法".assign()"赋值
L2.assign(L1.begin(),L1.end());

L2.assgin(n,elem);
~~~

**交换**
~~~
L1.swap(L2);
~~~

**52**

**大小操作**
~~~
list<int>L1;
//元素的个数
L1.size();
//判断是否为空
L1.empty();
//重新指定大小（默认值填充）
L1.resize(num);
//重新指定大小（elem值填充）
L1.resize(num,elem);
~~~

**53**

**插入**
~~~
//参数只能是迭代器的限制
//在begin的后面插入1000
list<int>::iterator it = L.begin();
L.insert(it++,1000);
~~~

**删除**
~~~
//删除begin后面的数据（1000）
it = L.begin();
L.erase(it++);
~~~

**it变量已声明！**
**it变量已声明！**
**it变量已声明！**

**移除**
~~~
//移除所有的1000
L.remove(1000);
~~~

**注意**，移除就是，删除容器中所有与elem值匹配的元素

**54**

list容器完全不支持at和[]下标，因为list的下标是不连续的存储

**具体的体现：**
~~~
L[0]; //❌
L.at(0); //❌
it = it+1; //❌不支持跳跃式访问
~~~

**55**

**反转**
.reverse()

**排序**

**注意**，若容器的迭代器不支持随机访问，则不允许使用algorithm里的算法，同时，不支持随机访问的容器自身会提供一些额外的算法以弥补不足
**所以**
//错误写法：
sort(L.begin,L.end);
//正确写法：
L.sort();

**56**

使用sort排序的小技巧
~~~
bool compare(int a,int b)
{
	return a < b;
}
L.sort(compare); // 注意这里的compare是不带()的
~~~

这一节讲的主要是基于自定义数据类型的sort排序，要求你必须指定排序规则，否则报错

### set/multiset容器
****

**57**

**特点**
set和multiset容器在插入元素时会**自动排序**

**本质**
set和multiset属于**关联式容器**，底层实现思想是二叉树

**区别**
set允许重复的元素
而multiset不允许有重复的元素

**构造**
~~~
//
set<Type> s;
//拷贝构造
set<Type>s2(s1);
//赋值构造
set<Type>s2;
s2 = s1;
~~~

**插入**
~~~
s.insert(elem);
~~~

**set容器只有insert!**
**set容器只有insert!**
**set容器只有insert!**

**58**

set容器的插入反而不能指定位置，毕竟会自动排序

**大小**
.empty()
.size()

**交换**
s1.swap(s2);

**59**

**删除**
~~~
//迭代器删除
s1.erase(s1.begin());
//重载版本删除（指定数值删除）
s1.erase(30);
//清空（区间删除）
s1.erase(s1.begin(),s1.end());

s1.clear()
~~~

**60**

**查找**
s1.find(elem) ---> 若找到elem值则返回其迭代器（位置）
~~~
//示例
set<int>::iterator pos = s1.find(30);
if(pos != s1.end())
{
	cout << *pos << endl;
} else {
	cout << "Not Found!" << endl;
}
~~~

set特色
**统计**
s1.count(elem); //统计elem的个数
~~~
//示例
int num = s1.count(30); //返回30的个数
cout << num << " 个" << endl;
~~~

对于set而言，count统计的结果要么是0，要么是1

**61**

用pair对组解释了set容器和multiset容器能否插入重复的数据

**62**

对组pair，一个变量名，两种数据类型

**构造**
~~~
//示例
//一
pair<string,int>p("Tom",20);
cout << "name：" << p.first << " age:" << p.second << endl;
//二
pair<string,int>p2 = make_pair("Jerry",20);
...
~~~

==63==

这一节很有意思，涉及**仿函数**，**数据类型**，**类**，**int/float**等相通的概念

**改变排序规则**
~~~
//示例
class MyCompare
{
public:
	bool operator()(int v1,int v2)     //"（）（）"典型的仿函数
	{
		return v1 > v2;
	}
}

set<int,MyCompare>s2;
~~~

从上述示例可以看出<>中，只能放数据类型，不能是变量名，也不能是函数名

**仿函数**，是一个类或结构体，它重载了函数调用运算符
[深入理解仿函数（Functors）](https://blog.csdn.net/2302_80836956/article/details/147892182)



到这里，回顾一下list和set容器，list的特点是它的迭代器（只能向左或向右一步一步地移动），而set的特点则是其自带一个从小到大的排序算法；另外，这两个容器在排序算法（algorithm sort）上很有特点，list由于其迭代器的限制，无法使用algorithm的函数，而是“内嵌”有一个排序函数，二者在使用方法上略有不同。。。set容器可能是因为自带排序函数，则在插入数据元素上有所限制（只能使用insert插入）。
此外，两个容器都有为改变sort的排序方式提供相应途径，list通过一个compare函数，set通过仿函数重载（operator（）），这一点有些高深，需要好好理解



# 1_2
### map容器

**65**

**简介**
map中的所有元素都是pair，一个key（键值），一个vaule（实值）；根据键值自动排序，multimap允许有重复的键值

**本质**
map/multimap属于关联式容器，底层是二叉树

**构造**
~~~
//
map<int,int>m;
//拷贝构造
map<int,int>m2(m);
//赋值构造
m2 = m;
~~~

**插入**
pair被当作是一种数据类型，map的每一个数据元素都被要求是pair类型，故有：
~~~
m.insert(pair<int,int>(1,10));
~~~

**66**

**大小**
.size(); ---》返回的是vaule**或**key的个数

.empty(); ---》判断是否为空

**交换**
m.swap(m2);

**67**

**插入**
有四，五种插入方式，这里主要说明两种：
~~~
//一
m.insert(pair<int,int>(1,10));
//二
m.insert(make_pair(2,20));
~~~

当有也有下面这种非常简明的插入方式：
~~~
m[4] = 40;
~~~
这里的“4”指的是key值

**删除**
~~~
//迭代器删除
m.erase(m.begin());
//key值删除(删除key值为elem的元素)
m.erase(3);
//迭代器+区间删除
m.erase(m.begin(),m.end());
~~~

**68**

**查找**
**注意**，查找失败返回.end()迭代器
.find(3) ---》查找key值为3的vaule，并返回一个迭代器（无论查找成功还是失败）

**统计**
这是set容器和map容器的**特色**，显然在map（而不是multimap）中返回值的结果只能是1或0
.count(elem); ---》找key值为elem的元素

**69**

**排序**
像set和map这种自带排序算法（从小到大）的容器，我们更需要了解如何去改变其排序规则
~~~
class MyCompare
{
public:
	bool operator()(int v1,int v2)
	{
		return v1 > v2;
	}
};

map<int,int,MyCompare> m;
//这样就得到了一个自动降序的map容器
~~~



