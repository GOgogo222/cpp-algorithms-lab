# [643. Maximum Average Subarray I](https://leetcode.cn/problems/maximum-average-subarray-i/)



## 题目



You are given an integer array `nums` consisting of `n` elements, and an integer `k`.

Find a contiguous subarray whose **length is equal to** `k` that has the maximum average value and return _this value_. Any answer with a calculation error less than `10-5` will be accepted.



Example:



```
Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000


Explanation:Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75


Input: nums = [5], k = 1
Output: 5.00000
```







## 题目大意



给定一个n个元素的整数数组和一个整数k，找一个长度为k且带有最大平均值的子数组，



## 解题思路



入-更新-出



入：下标为 i 的元素进入窗口



更新：使用max函数找到最大和




出：下标为 i−k+1 的元素离开窗口，窗口元素和 s 减少 nums[i−k+1]。