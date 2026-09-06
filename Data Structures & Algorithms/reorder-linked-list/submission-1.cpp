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
    ListNode* reverse(ListNode* head) {
        ListNode* rev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* temp = curr->next;
            curr->next = rev;
            rev = curr;
            curr = temp;
        }
        return rev;
    }

    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        if (head && head->next) fast = head->next;
        else return;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* rev = reverse(slow->next);
        slow->next = nullptr;
        ListNode* temp = head;
        while (temp && rev) {
            ListNode* dummy = temp->next;
            temp->next = rev;
            rev = rev->next;
            temp->next->next = dummy;
            temp = dummy;
        }
    }
};
