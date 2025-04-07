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
        ListNode* h;
        ListNode* sortList(ListNode* head) {
            if(head == nullptr || head -> next == nullptr) return head;
            ListNode* fast = head;
            ListNode* slow = head;
            ListNode* prev = nullptr;
            while(fast != nullptr && fast -> next != nullptr){
                prev = slow;
                fast = fast -> next -> next;
                slow = slow -> next;
            }
            //needs to end it to split
            prev -> next = nullptr;
            ListNode node = ListNode();
            ListNode* temp = &node; 
            ListNode* cur = temp;
            ListNode* first = sortList(head);
            ListNode* second = sortList(slow);
            while(first != nullptr && second != nullptr){
                if(first -> val < second -> val){
                    cur -> next = first;
                    first = first -> next;
                } else {
                    cur -> next = second;
                    second = second -> next;
                }
                cur = cur -> next;
            }
            if(first) cur -> next = first;
            else cur -> next = second;
            return temp -> next;
            
        }
    };