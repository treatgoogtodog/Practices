#include "LnkList.h"

#include <iostream>

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || !head->next)
            return head;
        if (left >= right)
            return head;

        ListNode* REVprev = nullptr;
        ListNode* REVbegin = nullptr;
        ListNode* REVend = nullptr;
        ListNode* REVnext = nullptr;
        unsigned int i = 1;
        for (ListNode *iter = head, *prev = nullptr; iter;
             prev = iter, iter = iter->next, i++) {
            if (i == left) {
                REVprev = prev;
                REVbegin = iter;
            }
            if (i == right) {
                REVnext = iter->next;
                REVend = iter;
            }
        }

        return reverse(head, REVprev, REVbegin, REVend, REVnext);
    }

private:
    ListNode* reverse(ListNode*& head, ListNode* prev, ListNode* begin,
                      ListNode* end, ListNode* next) {
        ListNode* Iterate = begin;
        ListNode* Iterate_Prev = nullptr;
        while (Iterate != end->next && Iterate) {
            ListNode* Iterate_Next = Iterate->next;
            Iterate->next = Iterate_Prev;
            Iterate_Prev = Iterate;
            Iterate = Iterate_Next;
        }

        if (!prev) {
            head = end;
        }
        if (prev) {
            prev->next = end;
        }
        begin->next = next;
        return head;
    }
};


int main() {
    // Create linked list: 1->2->3->4->5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int left = 2, right = 4;

    Solution sol;
    ListNode* result = sol.reverseBetween(head, left, right);

    // Print the result
    ListNode* curr = result;
    while (curr) {
        std::cout << curr->val;
        if (curr->next) std::cout << "->";
        curr = curr->next;
    }
    std::cout << std::endl;

    // Free memory
    curr = result;
    while (curr) {
        ListNode* tmp = curr;
        curr = curr->next;
        delete tmp;
    }

    return 0;
}