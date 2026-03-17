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
    ListNode* reverse(ListNode* head, int times){
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while(times--){
            ListNode* nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        return prev;
    }
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;

        ListNode* left = head;
        ListNode* prevLeft = nullptr;
        ListNode* newHead = nullptr;
        
        while(left && left->next){
            ListNode* right = left->next;
            ListNode* nextLeft = right->next;
        
            ListNode* temp = reverse(left, 2);

            if(!newHead)
                newHead = temp;
            
            if(prevLeft)
                prevLeft->next = temp;
            
            prevLeft = left;

            left->next = nextLeft;
            left = nextLeft;
        }
        
        if(prevLeft && left)
            prevLeft->next = left;
            
        return newHead;
    }
};