#include "LnkList.h"
#include <iostream>

using namespace std;

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next){return head;}

        ListNode* fast = head;
        ListNode* prev = nullptr;
        while(fast&&fast->next){
            ListNode* NextIter = fast->next->next;
            
            swap(head,prev, fast, fast->next, NextIter);
            prev = fast;
            fast = NextIter;
        }
        return head;
    }
private:
    void swap(ListNode*& head, ListNode* Prev, ListNode* Node1, ListNode* Node2, ListNode* Next){
        if(Prev){Prev->next = Node2;}
        if(!Prev){head = Node2;}
        Node2->next = Node1;
        Node1->next = Next;
    }
};

