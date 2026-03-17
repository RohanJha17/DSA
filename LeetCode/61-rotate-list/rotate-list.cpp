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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr)
            return head;

        ListNode* last = head;
        int n = 1;
        while(last->next){
            n++;
            last = last->next;
        }

        k = k%n;
        if(k == 0)
            return head;

        ListNode* temp = head;
        int count = 1;
        while(temp){
            if(count == n-k)
                break;
            
            count++;
            temp = temp->next;
        }

        last->next = head;
        ListNode* newHead = temp->next;
        temp->next = nullptr;

        return  newHead;
    }
};