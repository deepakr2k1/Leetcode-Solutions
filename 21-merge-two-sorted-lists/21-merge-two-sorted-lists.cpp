/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp = NULL, *head = NULL;
        while(list1 != NULL || list2 != NULL) {
            if(list1 == NULL) {
                if(temp == NULL) {
                    temp = list2;
                    if(head == NULL) {
                        head = temp;
                    }
                } else {
                    temp->next = list2;
                    temp = temp->next;
                }
                list2 = list2->next;
            } else if(list2 == NULL) {
                if(temp == NULL) {
                    temp = list1;
                    if(head == NULL) {
                        head = temp;
                    }
                } else {
                    temp->next = list1;
                    temp = temp->next;
                }
                list1 = list1->next;
            } else if(list1->val < list2->val) {
                if(temp == NULL) {
                    temp = list1;
                    if(head == NULL) {
                        head = temp;
                    }
                } else {
                    temp->next = list1;
                    temp = temp->next;
                }
                list1 = list1->next;
            } else {
                if(temp == NULL) {
                    temp = list2;
                    if(head == NULL) {
                        head = temp;
                    }
                } else {
                    temp->next = list2;
                    temp = temp->next;
                }
                list2 = list2->next;
            }
        }
        return head;
    }
};