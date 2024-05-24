/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode lst;
lst *rotateRight(lst *head, int rotatesTodo) {
    if (head == NULL || rotatesTodo == 0)
        return head;
    unsigned char   len = 1;
    lst *tail = head;
    while (tail->next) {
        tail = tail->next;
        len++;
    }
    rotatesTodo = rotatesTodo % len;
    if (rotatesTodo)
    {
        lst *newTail = head;
        while (++rotatesTodo < len)
            newTail = newTail->next;
        tail->next = head;
        head = newTail->next;
        newTail->next = NULL;
    }
    return head;
}