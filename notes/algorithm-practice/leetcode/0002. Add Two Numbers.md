# [2. Add Two Numbers](https://leetcode.cn/problems/add-two-numbers/)



## 题目



You are given two **non-empty** linked lists representing two non-negative integers. The digits are stored in **reverse order**, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.



Example:



```
Input:l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]


Explanation: 342 + 465 = 807.


Input:l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output:[8,9,9,9,0,0,0,1]
```







## 题目大意



两个链表表示两个数，一个节点表示一个位数，两个数相加



## 解题思路



迭代



循环即遍历链表 l1 和 l2​ ，每次把两个节点值 l1​.val, l2​.val 与进位值 carry 相加，**除以 10 的余数**即为当前节点需要保存的数位，**除以 10 的商**即为新的进位值。