# [1290. Convert Binary Number in a Linked List to Integer](https://leetcode.cn/problems/convert-binary-number-in-a-linked-list-to-integer/)



## 题目



Given `head` which is a reference node to a singly-linked list. The value of each node in the linked list is either `0` or `1`. The linked list holds the binary representation of a number.

Return the _decimal value_ of the number in the linked list.

The **most significant bit** is at the head of the linked list.



Example:



```
Input: [1,0,1]
Output: 5


Explanation:(101) in base 2 = (5) in base 10


Input: head = [0]
Output: 0
```







## 题目大意



将链表中的二进制数换算成整数，头结点是最高位



## 解题思路



本题是二进制，比如 1,1,0，目标是得到二进制数 110(2)​。

- 初始化答案为 0。

-  0(2)​×2+1=1(2)​。

- 1(2)​×2+1=11(2)​。乘 2 等价于左移 1。

- 11(2)​×2+0=110(2)​。
