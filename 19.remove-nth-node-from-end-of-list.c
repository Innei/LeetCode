/*
 * @lc app=leetcode id=19 lang=c
 *
 * [19] Remove Nth Node From End of List
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{

    /*
            思路:
                    一遍遍历
                    首先定义两个指针
                    n是倒数第几个需要删除的节点 === 前面的指针与后面的指针的距离
                    后面的指针开始移动 相差n个单位时 前面的指针跟上
                    后面的指针为NULL时 前面的指针指向的下一个节点是需要删除的节点

            注意:
            LeetCode中头指针为第一个节点, 所以需要建立一个头指针
    */
    struct ListNode *pHead = (struct ListNode *)malloc(sizeof(struct ListNode));   // 建立一个头指针
    pHead->next = head; // 让头指针的下一个节点指向第一个节点

    struct ListNode *before = pHead; // 初始化一个前面的指针
    struct ListNode *after = pHead;  // 初始化一个后面的指针
    struct ListNode *r = NULL;  // 初始化一个临时变量
    int i = 0, j = 0;
    if (!head->next) // 如果只有一个节点,直接返回一个NULL
    {
        return NULL;
    }
    for (; i < n + 1; i++) // 让后面的先走 2个单位
    {
        after = after->next;
    }

    while (after) // 后面的跟上
    {
        before = before->next;
        after = after->next;
    }
    r = before->next;

    before->next = before->next->next;

    free(r);
    return pHead->next;
}
