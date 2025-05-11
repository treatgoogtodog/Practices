#include <iostream>
#include "LnkList.h"

using namespace std;

class Solution {
    public:
        void deleteNode(ListNode* node) {
            node->val = node->next->val;
            ListNode* todelete = node->next;
            node->next = node->next->next;
            delete(todelete);
        }
};