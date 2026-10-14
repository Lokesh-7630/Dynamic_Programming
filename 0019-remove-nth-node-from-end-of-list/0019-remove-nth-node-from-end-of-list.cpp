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
    // ListNode* removeFromFront(ListNode* &head, ListNode* nodeToDelete){
    // ListNode* temp=head;
    // while(temp->next != nodeToDelete){
        
    //     temp->next=nodeToDelete->next;
    //     nodeToDelete->next=NULL;
    // }
    
    // }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size=getSize(head);
        ListNode* prev=head;
        if(n==size){
            ListNode* temp=head->next;
            delete head;
            return temp;
        }
        for(int i=1; i<(size-n); i++){
            prev=prev->next;
        }
        ListNode* nodeToDelete=prev->next;
        prev->next=prev->next->next;
        delete nodeToDelete;
        return head;
    }
    int getSize(ListNode* head){
       ListNode* temp=head;
       int sz=0;
       while(temp!=NULL){
        temp=temp->next;
          sz++;


       } 
       return sz;
    }
};