class Solution {
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            if(head == nullptr || head -> next == nullptr) return nullptr;
            ListNode* cur = head;
            ListNode* prev;
            for(int i = 0 ; i < n;i++){
                if(cur == nullptr) break;
                cur = cur -> next;
            }
            prev = head;
            ListNode* superprev = nullptr;
            while(cur){
                superprev = prev;
                prev = prev -> next;
                cur = cur -> next;
            }
            if(superprev == nullptr) return head -> next;
            superprev -> next = prev -> next;
            return head;
        }
    };