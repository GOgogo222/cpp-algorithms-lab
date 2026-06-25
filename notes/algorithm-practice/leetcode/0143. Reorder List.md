# [143. Reorder List](https://leetcode.cn/problems/reorder-list/)



## 题目



You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln

_Reorder the list to be on the following form:_

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …

You may not modify the values in the list's nodes. Only nodes themselves may be changed.



Example:



```
Input: head = [1,2,3,4]
Output: [1,4,2,3]



Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]
```





## 题目大意



改变链表的排序顺序



## 解题思路



先把链表“一分为二”，完全颠倒后半截链表的顺序，然后将节点交错连接，类似于“五指相扣”


