# [53.Maximum Subarray](https://leetcode.cn/problems/maximum-subarray/?envType=study-plan-v2&envId=top-100-liked](https://leetcode.cn/problems/maximum-subarray/description/?envType=study-plan-v2&envId=top-100-liked)



## 题目



Given an integer array `nums`, find the subarray with the largest sum, and return _its sum_.



A **subarray** is a contiguous **non-empty** sequence of elements within an array.



**Follow up:** If you have figured out the `O(n)` solution, try coding another solution using the **divide and conquer** approach, which is more subtle.



Example:



```
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation:The subarray [4,-1,2,1] has the largest sum 6.



Input: nums = [1]
Output: 1
Explanation:The subarray [1] has the largest sum 1.



Input: nums = [5,4,-1,7,8]
Output: 23
Explanation:The subarray [5,4,-1,7,8] has the largest sum 23.
```




## 题目大意



给定一个整数数组，找到带有最大和的子数组，并返回这个值



子数组是一个数组中连续的非空元素序列


## 解题思路



若当前指针所指元素之前的和小于0，则丢弃**当前元素之前**的序列


