/*
## 判断回文数

## 题目描述

```
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.
```

## 简要描述

判断回文数，经常做的。

*/
bool isPalindrome(int x){
    if (x < 0) return false;
    long long r = 0;long long t = x;
    int temp;

    while(x) {
        temp = x % 10;
        x /= 10;
        r = r * 10 + temp;
    }
    return r == t? true : false;
}
