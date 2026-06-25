# [283.Move Zeroes](https://leetcode.cn/problems/move-zeroes/)


## 题目



Given an integer array `nums`, move all `0`'s to the end of it while maintaining the relative order of the non-zero elements.



**Note** that you must do this in-place without making a copy of the array.



Example:



```

Input: nums = [0,1,0,3,12]
Output:       [1,3,12,0,0]


Input: nums = [0]
Output:       [0]

```







## 题目大意



给定一个整数数组，把数组中的0元素都移到数组的后面并保持其他元素的位置



~~注意，不可复制该数组~~



## 解题思路



这道题最优的做法时间复杂度是 O(n)。



顺序扫描数组，对每一个元素，在 map 中找能组合给定值的另一半数字，如果找到了，直接返回 2 个数字的下标即可。如果找不到，就把这个数字存入 map 中，等待扫到“另一半”数字的时候，再取出来返回结果。

