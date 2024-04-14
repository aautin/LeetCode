/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode	t_lst;
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    t_lst	*res = l1;
    t_lst	*prev = NULL;

	char	n1, n2;
	while (l1 || l2) {
		if (l1)
			n1 = l1->val;
		else
			n1 = 0;
		if (l2)
			n2 = l2->val;
		else
			n2 = 0;
		if (n1 + n2 > 9) {
			if (l1->next == NULL) {
				l1->next = malloc(sizeof(t_lst));
				l1->next->val = 0;
				l1->next->next = NULL;
			}
			l1->next->val += ((n1 + n2) / 10);
			l1->val = ((n1 + n2) % 10);
		}
		else{
			if (l1 == NULL) {
				l1 = malloc(sizeof(t_lst));
				if (prev)
                    prev->next = l1;
				l1->val = 0;
                l1->next = NULL;
			}
			l1->val = n1 + n2;
		}
        prev = l1;
        l1 = l1->next;
		if (l2)
            l2 = l2->next;
	}
    return (res);
}
