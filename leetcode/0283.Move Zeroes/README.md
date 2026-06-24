# [0283.Move Zeroes](https://leetcode.cn/problems/move-zeroes/)


## 题目



Given an integer array `nums`, move all `0`'s to the end of it while maintaining the relative order of the non-zero elements.



**Note** that you must do this in-place without making a copy of the array.



Example:



```
Input: [0,1,0,3,12]
Output: [1,3,12,0,0]


Input: [0]
Output: [0]
```







## 题目大意



给定一个整数数组，把数组中的0元素都移到数组的后面，同时保持其他元素先后的位置



~~注意，不可复制该数组~~



题目要求不能采用额外的辅助空间



## 解题思路



最优的解法只需要遍历数组一遍，不断地用i和j标记0和非零元素（i先走），然后交换i和j的位置

