/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* fastPtr) {
    struct ListNode*    slowPtr = fastPtr;

    while (fastPtr->next) {
        fastPtr = fastPtr->next;
        slowPtr = slowPtr->next;
        if (fastPtr->next)
            fastPtr = fastPtr->next;
    }
    return slowPtr;
}