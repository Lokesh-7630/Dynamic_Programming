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
    bool hasCycle(ListNode *head) {
       if (head == nullptr || head->next == nullptr) {
            return false;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            // 1. MOVE FIRST
            slow = slow->next;          
            fast = fast->next->next;    

            // 2. CHECK AFTER MOVING
            if (slow == fast) {
                return true; 
            }
        }

        return false;
    }
};