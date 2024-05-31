/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct s_lst {
	struct s_lst	*next;
	int				val;
}	t_lst;
void	push(t_lst **lst, int val) {
	if (*lst != NULL) {
		t_lst	*new = malloc(sizeof(t_lst));
		new->val = val;
		new->next = *lst;
		*lst = new;
	}
	else {
		*lst = malloc(sizeof(t_lst));
		(*lst)->val = val;
		(*lst)->next = NULL;
	}
}
int	pop(t_lst **lst, int val) {
	if (*lst == NULL)
		return 0;
	if ((*lst)->val == val) {
		*lst = (*lst)->next;
		return 1;
	}
	t_lst	*head = *lst;
	while ((*lst)->next) {
		if ((*lst)->next->val == val) {
			(*lst)->next = (*lst)->next->next;
			*lst = head;
			return 1;
		}
		*lst = (*lst)->next;
	}
	*lst = head;
	return 0;
}

int* singleNumber(int* nums, int numsSize, int* returnSize) {
	t_lst	*history = NULL;
	while (numsSize--) {
		if (!pop(&history, nums[numsSize]))
			push(&history, nums[numsSize]);
	}
	nums[0] = history->val;
	nums[1] = history->next->val;
    *returnSize = 2;
    return nums;
}