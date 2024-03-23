/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode*    head;
    struct ListNode*    merge;
    if (!list1) return list2;
    if (!list2) return list1;

    if (list1->val <= list2->val) {
        merge = list1;
        list1 = list1->next;
    } else {
        merge = list2;
        list2 = list2->next;
    }
	head = merge;
    while (list1 && list2) {
        if (list1->val <= list2->val) {
            merge->next = list1;
            list1 = list1->next;
        }
        else if (list2->val <= list1->val) {
            merge->next = list2;
            list2 = list2->next;
        }
        merge = merge->next;
    }
	if (list1)
		merge->next = list1;
	else if (list2)
		merge->next = list2;
    return head; 
}
