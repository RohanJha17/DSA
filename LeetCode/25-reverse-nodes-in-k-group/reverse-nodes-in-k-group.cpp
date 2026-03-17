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
    void reverse(ListNode* head, int times){
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while(times--){
            ListNode* nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        return;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr)
            return head;

        ListNode* left = head;
        ListNode* prevLeft = nullptr;
        ListNode* newHead = nullptr;

        while(true){
            ListNode* right = left;
            for(int i=0; i<k-1; i++){
                if(!right)
                    break;
                
                right = right->next;
            }

            if(right){
                ListNode* nextLeft = right->next;
                reverse(left, k);

                if(prevLeft)
                    prevLeft->next = right;
                prevLeft = left;

                if(!newHead)
                    newHead = right;
                
                left = nextLeft;    
            }
            else{
                if(prevLeft)
                    prevLeft->next = left;
                
                if(!newHead)
                    newHead = left;

                break;
            }
        }
        return newHead;
    }
};