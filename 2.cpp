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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* p = head;
        int c = 0;
        while (l1 && l2)
        {
            p->next = new ListNode((l1->val + l2->val + c) % 10);
            p = p->next;

            c = (l1->val + l2->val + c) / 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1)
        {
            p->next = new ListNode((l1->val + c) % 10);
            p = p->next;
            
            c = (l1->val + c) / 10;
            l1 = l1->next;
        }
        while (l2)
        {
            p->next = new ListNode((l2->val + c) % 10);
            p = p->next;
            
            c = (l2->val + c) / 10;
            l2 = l2->next;
        }
        if (c)
        {
            p->next = new ListNode((c) % 10);
            p = p->next;
        }
        
        return head->next;
    }
};