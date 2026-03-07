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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == nullptr || head->next == nullptr)
            return head;

        if(left == right)
            return head;

        ListNode* temp = head;
        ListNode* before = nullptr;
        int pos = 1;
        while(pos < left){
            before = temp;
            temp = temp->next;
            pos++;
        }

        ListNode* curr = temp;
        ListNode* prev = nullptr;
        int count = right-left+1;
        while(count--){
            ListNode* next = curr->next;

            curr->next = prev;
            prev = curr;
            curr = next;
        }

        temp->next = curr;
        if(before){
            before->next = prev;
            return head;
        }
        return prev;
    }
};