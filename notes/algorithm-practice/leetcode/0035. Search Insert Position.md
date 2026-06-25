# [35.Search Insert Position](https://leetcode.cn/problems/search-insert-position/description/?envType=study-plan-v2&envId=top-100-liked)



## 题目



Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with `O(log n)` runtime complexity.



Example:



```
Input: nums = [1,3,5,6], target = 5
Output: 2


Input: nums = [1,3,5,6], target = 2
Output: 1
```







## 题目大意



给定一个排序的整数数组和一个目标值，若目标值在数组中找到则返回相应下标，否则，返回其应被插入的位置



用时间复杂度为O(logn)的解法



## 解题思路



利用二分法在 O(logn) 的时间内找到是否存在目标值


