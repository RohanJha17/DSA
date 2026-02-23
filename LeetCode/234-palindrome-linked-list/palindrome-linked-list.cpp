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
    ListNode* reverseList(ListNode* middle){
        ListNode* prev = nullptr;
        ListNode* curr = middle;
        ListNode* temp = nullptr;
        while(curr != nullptr){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return true;

        ListNode* last = head;
        ListNode* middle = head;
        while(last != nullptr && last->next != nullptr){
            middle = middle->next;
            last = last->next->next;
        }

        ListNode* firsthalf = head;
        ListNode* secondhalf = reverseList(middle);
        while(secondhalf != nullptr){
            if(firsthalf->val != secondhalf->val)
                return false;
            
            firsthalf = firsthalf->next;
            secondhalf = secondhalf->next;
        }

        return true;
    }
};