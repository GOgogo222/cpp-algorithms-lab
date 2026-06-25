# [2962. Count Subarrays Where Max Element Appears at Least K Times](https://leetcode.cn/problems/count-subarrays-where-max-element-appears-at-least-k-times/)



## 题目



You are given an integer array `nums` and a **positive** integer `k`.

Return _the number of subarrays where the **maximum** element of_ `nums` _appears **at least**_ `k` _times in that subarray._

A **subarray** is a contiguous sequence of elements within an array.



Example:



```
Input: nums = [1,3,2,3,3], k = 2
Output: 6


Explanation:The subarrays that contain the element 3 at least 2 times are: [1,3,2,3], [1,3,2,3,3], [3,2,3], [3,2,3,3], [2,3,3] and [3,3].


Input: nums = [1,4,2,1], k = 3
Output: 0


Explanation:No subarray contains the element 4 at least 3 times.
```







## 题目大意



算出含有最大元素不超过k个的子数组



## 解题思路



数组越长，包含的元素越多，越能满足题目的要求，用滑动动窗口解决



越长越好的公式：ans += left 






