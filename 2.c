/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdlib.h>

struct ListNode* makeNode(void)
{
    struct ListNode* res;
    res = malloc(sizeof(struct ListNode));
    res->next = NULL;
    return (res);
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *head;
    struct ListNode *cursor;
    struct ListNode *new;
    int l1val = l1->val;
    int l2val = l2->val;
    int rest = 0;

    new = makeNode();
    head = new;

    while ((l1 || l2) || rest != 0)
    {
        new->val = (rest + l1val + l2val) % 10;
        rest = (rest + l1val + l2val) / 10;
        cursor = new;

        if (l1)
        {
            l1 = l1->next;
            if (l1)
                l1val = l1->val;
            else
                l1val = 0;
        }
        else
            l1val = 0;
        if (l2)
        {
            l2 = l2->next;
            if (l2)
                l2val = l2->val;
            else
                l2val = 0;
        }
        else
            l2val = 0;
        if ((l1 || l2) || rest != 0)
        {
            new = makeNode();
            cursor->next = new;
        }
    }
    new->next = NULL;
    return (head);
}
