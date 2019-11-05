/**
  * Leetcode 19: Remove Nth Node From End of List
  * Author: Weiqi Feng
  * Email: fengweiqi@sjtu.edu.cn
  * Date: November 5, 2019
  * Copyright 2019 Vic
  */ 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create two pointers
        ListNode* ptr1 = head;
        ListNode* ptr2 = head;
        // Keep second pointer n distance with the first pointer
        while (n > 0 && ptr2 != nullptr) {
            ptr2 = ptr2->next;
            n--;
        }
        // Check edge case: remove the head
        if (ptr2 == nullptr) {
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
            return head;
        }
        // Normal case
        while (ptr2 -> next != nullptr) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        ListNode* tmp = (ptr1->next)->next;
        delete ptr1->next;
        ptr1->next = tmp;
        // Return head pointer
        return head;
    }
};
