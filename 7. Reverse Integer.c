/*
## 反转整数

### 题目描述

```
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
```

## 简要描述

输入一个32 位的整数[−2^31,  2^31 − 1], 输出它的反转后的值，如果溢出范围，则输出 0.

## 思路

注意判断是否溢出。

*/



#include <limits.h>
int reverse(int x) {
	long long temp, res = 0;
	while (x) {
		temp = x % 10;
		x /= 10;
		res = (res * 10) + temp;
	}
	return (res < INT_MIN || res > INT_MAX) ? 0 : res;
}

// 使用 `limit.h` 中的 `INT_MIN` `INT_MAX`常量判断是否溢出。
