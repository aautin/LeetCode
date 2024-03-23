/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode t_lst;

t_lst *getMidNode(t_lst *lst)
{
    t_lst   *slowPtr = lst;

    while (lst && lst->next) {
        lst = lst->next->next;
        if (lst)
            slowPtr = slowPtr->next;
    }
    return (slowPtr);
}

bool    reverseChecking(t_lst *tail, t_lst **head) {
    bool equal;
    if (tail->next) {
        equal = reverseChecking(tail->next, head) && (*head)->val == tail->val;
        return ((*head) = (*head)->next, equal);
    }
    equal = (tail->val == (*head)->val);
    (*head) = (*head)->next;
    return (equal);
}

bool isPalindrome(struct ListNode* head) {
    if (!head->next)
        return (1);

    return (reverseChecking(getMidNode(head)->next, &head));
}
