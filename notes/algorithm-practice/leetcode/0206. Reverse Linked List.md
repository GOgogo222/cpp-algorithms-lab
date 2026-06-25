# [206. Reverse Linked List](https://leetcode.cn/problems/reverse-linked-list/)



## 题目



Given the `head` of a singly linked list, reverse the list, and return _the reversed list_.



Example:



```
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]


Input: head = [1,2]
Output: [2,1]
```







## 题目大意



翻转整个链表



## 解题思路



头插法，把节点总是插在一个新链表的头结点上

- 第一轮循环结束后，得到链表 1。

- 第二轮循环结束后，得到链表 2→1。

- 第三轮循环结束后，得到链表 3→2→1。


