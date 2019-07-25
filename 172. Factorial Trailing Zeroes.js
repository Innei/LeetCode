/*
## 阶乘尾随零的个数

### 题目描述

```
Given an integer n, return the number of trailing zeroes in n!.

Example 1:

Input: 3
Output: 0
Explanation: 3! = 6, no trailing zero.
Example 2:

Input: 5
Output: 1
Explanation: 5! = 120, one trailing zero.
Note: Your solution should be in logarithmic time complexity.
```

### 简要说明

就是找出 n! 尾部的零的个数。

### 思路

我开始是想算出来在去找零的个数，后来证实是不行的，一是到最后数字太多导致溢出了，而是超出了时间复杂度的限制。

结果一波摸索，发现 LeetCode 上的题大多都是考验的是对数学思维的理解，问题的转化。找出尾部的零其实就是找有多少个 10 相乘，一个 10 相乘就多一个 0，10 是有 `2 * 5` 得出的，有一个 5 的同时必定前面出现一个 2，所以就是找有多少个 5。 2n * 5n => 10n (n 为系数), 例如 25 `2*5` 有一个 10.同时 25 中又有两个 5。所以 25 其实不止一个 5，他有两个 5.由此得出，想知道 x 中有几个五其实就是（x 为待阶层数）, x / 5 + x / 5 / 5 + x / 5 / 5 .... 直到 x / 5 ^ m 等于 0 （ / 为整除）

例如：

`5` ==> `1 * 2 * 3 * 4 * 5`  => `120` => 一个0
`25` ==> `1 * 2 * 3 * ... 25 ` => 25 / 5 => 25 = 5 * 5 => 六个0

*/

var trailingZeroes = function(n) {
	return Math.floor(n / 5) == = 0 ? 0 : (Math.floor(n / 5) + trailingZeroes(n / 5))
};

// 注意使用 `Math.floor` 向下取整