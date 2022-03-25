/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA=0, lenB=0;
        ListNode *tempA = headA, *tempB = headB;
        while(tempA != NULL) {
            lenA++;
            tempA = tempA->next;
        }
        while(tempB != NULL) {
            lenB++;
            tempB = tempB->next;
        }
        tempA = headA, tempB = headB;
        while(lenA > 0 && lenB > 0) {
            if(lenA > lenB) {
                tempA = tempA->next;
                lenA--;
            } else if(lenA < lenB) {
                tempB = tempB->next;
                lenB--;
            } else {
                if(tempA == tempB) {
                    return tempA;
                }
                tempA = tempA->next;
                tempB = tempB->next;
                lenA--;
                lenB--;
            }
        }
        return NULL;
    }
};