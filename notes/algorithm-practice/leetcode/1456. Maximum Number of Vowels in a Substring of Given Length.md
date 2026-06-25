# [1456. Maximum Number of Vowels in a Substring of Given Length](https://leetcode.cn/problems/maximum-number-of-vowels-in-a-substring-of-given-length/)



## 题目



Given a string `s` and an integer `k`, return _the maximum number of vowel letters in any substring of_ `s` _with length_ `k`.

**Vowel letters** in English are `'a'`, `'e'`, `'i'`, `'o'`, and `'u'`.



Example:



```
Input: s = "abciiidef", k = 3
Output: 3


Explanation:The substring "iii" contains 3 vowel letters.


Input: s = "aeiou", k = 2
Output: 2



Explanation:Any substring of length 2 contains 2 vowels.
```







## 题目大意



~~给定一个字符串s和整数k，返回字符串 s 中长度为 k 的单个子字符串中可能包含的**最大元音字母数**。~~



我们要计算所有长度**恰好**为 k 的子串中，最多可以包含多少个元音字母。



## 解题思路



字符串 abci，假如我们已经计算出了子串 abc 的元音个数，那么从子串 abc 到子串 bci，只需要考虑移除（离开窗口）的字母 a 是不是元音，以及添加（进入窗口）的字母 i 是不是元音即可，因为中间的字母 b 和 c 都在这两个子串中。

作者：灵茶山艾府
链接：https://leetcode.cn/problems/maximum-number-of-vowels-in-a-substring-of-given-length/solutions/2809359/tao-lu-jiao-ni-jie-jue-ding-chang-hua-ch-fzfo/


