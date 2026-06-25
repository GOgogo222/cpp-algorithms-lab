# [3. Longest Substring Without Repeating Characters](https://leetcode.cn/problems/longest-substring-without-repeating-characters/)



## 题目



Given a string `s`, find the length of the **longest** **substring** without duplicate characters.



Example:



```
Input: s = "abcabcbb"
Output: 3


Explanation:The answer is "abc", with the length of 3. Note that `"bca"` and `"cab"` are also correct answers.


Input: s = "bbbbb"
Output: 1


Explanation:The answer is "b", with the length of 1.


Input: s = "pwwkew"
Output: 3


Explanation:The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
```







## 题目大意



给定一个字符串，找到最长不带重复字符的子字符串，并返回其长度



## 解题思路



“滑动窗口”的思想



滑动窗口的右边界在没有重复字符的条件下不断右移；一旦出现了重复字符，就删除左边界，直到把重复的字符从左边界移出为止，这时可以继续移动右边界。



向右移动时要计算当前长度，并判断是否更新最大长度。



返回最大长度





