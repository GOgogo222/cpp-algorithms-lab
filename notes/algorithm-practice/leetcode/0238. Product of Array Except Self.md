
# [238 Product of Array Except Self](https://leetcode.cn/problems/product-of-array-except-self/?envType=study-plan-v2&envId=top-100-liked)




## 题目



Given an integer array `nums`, return _an array_ `answer` _such that_ `answer[i]` _is equal to the product of all the elements of_ `nums` _except_ `nums[i]`.



The product of any prefix or suffix of `nums` is **guaranteed** to fit in a **32-bit** integer.



You must write an algorithm that runs in `O(n)` time and without using the division operation.



**Follow up:** Can you solve the problem in `O(1)` extra space complexity? (The output array **does not** count as extra space for space complexity analysis.)



Example:



~~~
Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Explanation:


Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
Explanation:
~~~



# 题目大意



给定一个整数数组nums，返回一个新的数组newarr：newarr[i] 等于除 nums[i] 以外所有其他元素之和



# 解题思路



创建前缀和和后缀和数组，分别存储"i之前"和"i之后"元素的乘积，相应元素的前缀 * 后缀就是除自己之外其他所有元素的乘积了