/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode t_lst;

t_lst   *getLstMidnext(t_lst *fastPtr) {
    t_lst   *slowPtr = fastPtr;

    while (fastPtr) {
        if (fastPtr->next)
            fastPtr = fastPtr->next->next;
        else
            fastPtr = fastPtr->next;
        slowPtr = slowPtr->next; 
    }
    return (slowPtr);
}

// tail starts from the list's mid->next
// here, mid->next is : [1,2,(3),4] or [1,2,3,(4),5]
void    reconnection(t_lst **head, t_lst *tail) {
    if (tail->next)
        reconnection(head, tail->next);
    tail->next = (*head)->next;
    (*head)->next = tail;
    (*head) = (*head)->next->next;
    if ((*head)->next == tail)
        (*head)->next = NULL;
}

void    reorderList(struct ListNode* head) {
    if (!head->next || !(head->next->next))
        return ;

    reconnection(&head, getLstMidnext(head));
}