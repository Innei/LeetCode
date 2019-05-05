"""
Runtime: 36 ms, faster than 87.97% of Python3 online submissions for Valid Parentheses.
Memory Usage: 13.3 MB, less than 5.22% of Python3 online submissions for Valid Parentheses.

思路: 
        创建一个栈, 如果后进来的元素与栈中最后一个元素成对就出栈, 如果最后栈为空, 返回真
        如果输入只有一个字符, 直接返回假
        还有一个情况, 如果遍历到当前字符刚好与栈中元素不成对, 直接返回假

"""




class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        lst = list(s)
        if len(s) == 1:
            return False
        for i in lst:
            if i == '[' or i == '(' or i == '{':
                stack.append(i)
            if i == ']' or i == '}' or i == ')':
                try:
                    if i == ']' and stack[-1] != '[':
                        return False
                    elif i == '}' and stack[-1] != '{':
                        return False
                    elif i == ')' and stack[-1] != '(':
                        return False
                except IndexError:
                    return False
                if stack:

                    if i == ']' and stack[-1] == '[':
                        stack.pop()
                    elif i == '}' and stack[-1] == '{':
                        stack.pop()
                    elif i == ')' and stack[-1] == '(':
                        stack.pop()

        if len(stack) != 0:
            return False

        return True
