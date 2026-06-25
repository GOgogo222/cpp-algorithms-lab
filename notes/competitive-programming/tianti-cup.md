
# 3_7


https://wyqz.top/p/870124582.html#toc-heading-2 => C++ STL




**主要浏览vector, set, map和string容器，以及一些可能用得上的函数**


## vector

## sort函数

~~~
vector<int> v = {2,14,5,8,9};
sort(v.begin(),v.end()); // 对第一个到第五个元素排序
sort(v.begin() + 2, v.end()); // 对第三个到第五个元素
~~~



## erase函数



~~~
vector<int> v(n+1);
erase(v.begin() + 1,v.end()); // 从删除(1,n)中的元素
~~~



~~~
erase(remove(v.begin(),v.end(),elem),v.end()); // 删除所有数组中所有跟elem相同的元素
~~~



**不同容器的erase方法不完全相同！！！**



## 访问



~~~~
for (int i = 0; i < 5; ++i) {
	v.push_back(i);
}
for (int i = 0; i < 5; ++i) cout << v[i] << " "
cout << "\n";
~~~~



~~~
for (iterator it = v.begin(); it != v.end(); ++it) {
	cout << *it << " ";
}
~~~



## string



## 二维string数组



~~~
string s[10]; // 构造一个数组，其中元素为string类型
~~~



## 特性

- 支持比较运算符(>,>=,<等)

"aaaa"  < "aaaaa"

"abcd" < "abcde"

- 支持加号运算符(+)

~~~
string s1 = "123";
string s2 = "456";
cout << s1 + s2; // "123456"
~~~


- 使用getline读取

~~~
getline(cin,s);
~~~



## erase

**同时支持迭代器删除和位置删除（常用位置删除）**



~~~
一：
erase(s.begin(),s.end());

二：
for (int i = s.size(); i > 0; --i) {
	if (s[i] == 'a') erase(i,elem);
	//表示从第i个元素删到第elem个元素
}
~~~



## sort

~~~
sort(s.begin(),s.end()); // 按ASCII排序
~~~



## STL函数


## reverse

~~~
vector<int> v = {1,2,3,4};

reverse(v.begin(),v.end());

cout << v[0] << v[1] << v[2] << v[3];//4321
~~~


**注意！注意！注意！**

~~~
int a[] = {1,2,3,4}; // 初始化

reverse(a,a + 4);

cout << a[0] << a[1] << a[2] << a[3];
~~~



## sort


使用第三个参数控制排序规则

~~~
//对数组的[0,n-1]位置从小到大
sort(a, a+n, greater<int>());
//对数组的[0,n-1]位置从大到小
sort(a, a+n, less<int>());

//vector
sort(v.begin(),v.end(),less<int>());
sort(v.begin(),v.end(),greater<int>());

//string
sort(s.begin(),s.end(),less<char>());
sort(s.begin(),s.end(),greater<char>());
~~~



# 3_8


https://www.luogu.com.cn/problem/P2249#ide



方法一：直接使用lower_bound()函数


> [!NOTE] lower_bound函数
> lower_bound(start, end, target):从在start到end区间内查找target，如果找到了，返回一个指针，如果没找到，返回第一个比它大的值的指针。
> 返回的是迭代器


方法二：手搓二分查找


~~~
    while(l < r) {
        int mid = l + (r-l) / 2;
        if(nums[mid] >= x) r = mid;
        else l = mid+1;
    }
~~~


**注意：** 以上均为 **左闭右开** 写法


方法三：二分查找（递归写法）


~~~
#include<bits/stdc++.h>
using namespace std;
int a[1000020];
int findpos(int a[], int l, int r, int k)
{
	if (l == r)
	{
		if (a[l] == k)
			return l;
		else
			return -1;
	}
	int mid = (l + r) / 2;
	if (k <= a[mid])
		findpos(a, l, mid, k);
	else
		findpos(a, mid + 1, r, k);
}
int main()
{
	int n, m, k;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	while (m--)
	{
		cin >> k;
		cout << findpos(a, 1, n, k) << " ";
	}
	return 0;
}
~~~


https://www.luogu.com.cn/problem/P1182 => 略



https://www.luogu.com.cn/problem/P8647



方法一：二分查找（左闭右闭）


~~~
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (mid == 0) break;
        if (check(mid,cakes,k)) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
~~~


https://www.luogu.com.cn/problem/P8662

https://www.luogu.com.cn/problem/P8673

https://www.luogu.com.cn/problem/P9425 =>三道题跳过


https://www.luogu.com.cn/problem/P2367


方法一：差分法

核心逻辑：

~~~
    for (int i = 1; i <= n; ++i) {
        diff[i] = a[i] - a[i-1];
    }
    while(p--) {
        int L, R, score;
        cin >> L >> R >> score;
        diff[L] += score;
        diff[R+1] -= score;
    }
~~~


# 3_9


https://www.luogu.com.cn/problem/P3397




https://www.luogu.com.cn/problem/P13879



https://www.luogu.com.cn/problem/P10903 => 完成了一半，不是很理解



https://www.luogu.com.cn/problem/P8218



https://www.luogu.com.cn/problem/P2004



一些有用的博客：

https://www.lanqiao.cn/courses/2786

https://blog.csdn.net/2401_86619696?type=blog

https://blog.csdn.net/2401_86619696/article/details/156191674

https://blog.csdn.net/perfectgamer/article/details/156204124




# 3_11

https://www.luogu.com.cn/problem/P8649 => 无法理解



https://www.luogu.com.cn/problem/P12134 => 过



https://www.luogu.com.cn/problem/P8772 => 掌握



https://www.luogu.com.cn/problem/P8218 => 掌握



https://www.luogu.com.cn/problem/P2004 => 熟悉



https://www.luogu.com.cn/problem/P10903 => 过



https://blog.csdn.net/2401_86619696/article/details/156191674



https://www.luogu.com.cn/problem/P8780



------>了解一下double类型



# 3_12

https://www.luogu.com.cn/problem/P8780




https://www.luogu.com.cn/problem/P8783 => 熟悉



https://www.luogu.com.cn/problem/P9240 => 熟悉



64



# 3_13


字符串问题：


https://pintia.cn/problem-sets/2015386817518112768/exam/problems/type/7?problemSetProblemId=2015386817990172736



https://pintia.cn/problem-sets/2015386817518112768/exam/problems/type/7?problemSetProblemId=2015386817990172731



总结：对STL的使用没那么熟悉，属于是不会啥就考啥了