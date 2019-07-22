/*
## 查找一个值的索引

### 题目描述
```
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:

Input: [1,3,5,6], 5
Output: 2
Example 2:

Input: [1,3,5,6], 2
Output: 1
Example 3:

Input: [1,3,5,6], 7
Output: 4
Example 4:

Input: [1,3,5,6], 0
Output: 0
```

### 简要说明

给定一个排序过后的数组和一个目标值，查找给定目标值在数组中的索引值，若不存在这个值，则返回如果该值存在时的索引值。（注意是，排序过的数组）

思想：

因为是排序过的数组，所以只要一次遍历就可以了。

如果找到该值，则返回当前下标；如果该值在比较时，数组中的值已经大于目标值，则只可能在当前位置上可以按照当前的顺序插入该值，所以也应该返回当前下标。
*/
int searchInsert(int* nums, int numsSize, int target) {
	for (int i = 0; i < numsSize; i++) {
		if (*(nums + i) == target)
			return i;
		else if (*(nums + i) > target)
			return i;
		else {
			continue;
		}
	}
	return numsSize;
}