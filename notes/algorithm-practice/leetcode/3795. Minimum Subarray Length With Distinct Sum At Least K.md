# [3795. Minimum Subarray Length With Distinct Sum At Least K](https://leetcode.cn/problems/minimum-subarray-length-with-distinct-sum-at-least-k/)



## 题目



You are given an integer array `nums` and an integer `k`.

Return the **minimum** length of a **subarray** whose sum of the **distinct** values present in that subarray (each value counted once) is **at least** `k`. If no such subarray exists, return -1.



Example:



```
Input: nums = [2,2,3,1], k = 4
Output: 2


Explanation:The subarray [2, 3] has distinct elements {2, 3} whose sum is 2 + 3 = 5, which is ​​​​​​​at least k = 4. Thus, the answer is 2.


Input: nums = [3,2,3,4], k = 5
Output: 5


Explanation:The subarray [3, 2] has distinct elements {3, 2} whose sum is 3 + 2 = 5, which is ​​​​​​​at least k = 5. Thus, the answer is 2.
```







## 题目大意



找到nums最短的子数组，该数组的元素唯一，返回其元素之和



## 解题思路



用一个哈希表cnt维护窗口每个元素的出现次数

- nums[i] 第一次出现才让它“入”

```
   if (cnt[x] == 1) {
       sum += x;
   }
```

- 统计出现次数

```
    int x = nums[i];
    cnt[x]++;
```

- nums[i] 出现次数为0就让它“出”

```
   if (cnt[out] == 0) {
       sum -= out;
   }
```

- 统计删除次数

```
    int out = nums[left];
    cnt[out]--;
```

**cnt[x]++;** //  多多理解