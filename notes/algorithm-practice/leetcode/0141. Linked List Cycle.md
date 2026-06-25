# [141. Linked List Cycle](https://leetcode.cn/problems/linked-list-cycle/)



## 题目



Given `head`, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the `next` pointer. Internally, `pos` is used to denote the index of the node that tail's `next` pointer is connected to. **Note that `pos` is not passed as a parameter**.

Return `true` _if there is a cycle in the linked list_. Otherwise, return `false`.



Example:



```
Input: head = [3,2,0,-4], pos = 1
Output: true


Explanation:There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).


Input: head = [1,2], pos = 0
Output: true


Explanation:There is a cycle in the linked list, where the tail connects to the 0th node.
```







## 题目大意



判断链表中是否有环



## 解题思路



创建快慢指针，若是有环，指针必能相遇


