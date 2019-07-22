/*
## 数数和说数

### 题目描述

```
The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.

 

Example 1:

Input: 1
Output: "1"
Example 2:

Input: 4
Output: "1211"
```

### 简要描述

给定一个序号，返回该序号的规律字符串。

规律：

1. 第一个永远是 "1"
1. 第二个是第一个的描述后的数字，例如第一个的"1", 可以这么说，一个 1，所以一个表示成 1, 1 表示成 1，所以结果是`11`
1. 那么第三个就是在第二个的基础上，也就是`21`，因为是 2 个 1.

### 思想

这里，我想的有点复杂了，所以时间和空间复杂度很高。

首先，他是从第一个开始到第 n 个的循环，每次算出上一个的结果。

`n == 1, res = "1"`

从第二个开始，每次循环中，提取出当前的 res 再来一个循环，记录 res 中前一个数字和当前遍历到的数字是否相同，`bPostion == j ? count ++ `。如果不相同，则把当前的记录的 `count` 和 `bPostion` 合并为字符串，push 到一个 临时数组中，当最外层循环结束后，把临时数组中的每一个字符串合并入 res，并且清空临时数组。对其他变量进行初始化。进行下一次循环。
*/
var countAndSay = function(n) {
  let res = "1"
  let bPostion = ''
  let count = 0
  let temp = []
  for (let i = 2; i <= n ; i++ ){
    rt = res + '!'
    for(let j of rt) {
      if ((bPostion || j) == j) {
        count++;
      }
      else {
        temp.push(String(count || 1) + (bPostion || j))
        count = 1
      }
      bPostion = j
    }
    if(temp.length) {
      res = ''
      for (let i of temp){
        res += i
      }
    }
    bPostion = ''
    temp = []
    count = 0
  }

  return res;
};

