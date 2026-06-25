# [189 Rotate Array](https://leetcode.cn/problems/rotate-array/description/?envType=study-plan-v2&envId=top-100-liked)



## 题目



Given an integer array `nums`, rotate the array to the right by `k` steps, where `k` is non-negative.



**Follow up:**

- Try to come up with as many solutions as you can. There are at least **three** different ways to solve this problem.
- Could you do it in-place with `O(1)` extra space?



Example:



```
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]


Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation:rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
```




## 题目大意



旋转数组，将数组向右旋转k步，其中k是非负数


## 解题思路



公式：newArr[(i+k)%n] = nums[i];


二：翻转三次数组，如下

nums = "----->-->"; k =3

result = "-->----->";

reverse "----->-->" we can get "<--<-----"

reverse "<--" we can get "--><-----"

reverse "<-----" we can get "-->----->"

原地址：https://leetcode.com/problems/rotate-array/solutions/54250/Easy-to-read-Java-solution/



