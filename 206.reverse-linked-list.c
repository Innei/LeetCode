/*
 * @lc app=leetcode id=206 lang=c
 *
 * [206] Reverse Linked List
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *reverseList(struct ListNode *head)
{
    /*
    反转一个单链表。

    思路:
    建立三个指针, 分别指向 前一个pre 当前这个cur 后一个节点next.
    原先前一个指向NULL,当前这个指向第一个,后一个指向第二个
    如果当前这个不为NULL,把next = cur->next ,同时把cur->next = pre,然后只要把cur = next;pre = cur; 然后重复步骤直到cur==NULL
    也就是说, 只要每次一开始把next往后移一个节点,最后把他给cur就行,这样就不会丢失后面的节点.
    
    */

    struct ListNode *pHead = (struct ListNode *)malloc(sizeof(struct ListNode));
    pHead->next = head;

    struct ListNode *cur = head;
    struct ListNode *pre = NULL;
    struct ListNode *next;

    while (cur)
    {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}
