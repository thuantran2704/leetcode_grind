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
    ListNode* swapPairs(ListNode* head) {
        ListNode* cur = head;
        if(!cur || !cur -> next) return head;
        ListNode* newh = head -> next;
        ListNode* prev = nullptr;
        while(cur && cur -> next){
            ListNode* ne = cur -> next;
            cur -> next = ne -> next;
            ne -> next = cur;
            if(prev) prev -> next = ne;
            prev = cur;
            cur = cur -> next;
        }
        return newh;
    }
};