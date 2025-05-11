#include <iostream>
#include "LnkList.h"

using namespace std;

// 1->2->3->2

class Solution {
    public:
        ListNode* partition(ListNode* head, int x) {
            ListNode* curr = head;
            ListNode* prev = nullptr;
            ListNode* head1 = head;
            ListNode* tail1 = nullptr;
            ListNode* head2 = nullptr;            
            ListNode* tail2 = nullptr;

            while(curr){
                if(curr->val == x){prev->next = nullptr; head2 = curr; tail1 = prev;}
                prev = curr;
                curr = curr->next;
            }
            if(head2 == nullptr){return head;}
            tail2 = prev;
            //Seperate the list into 2 part: Smaller than X and Greater than X(including X)
            ListNode* currhead = head1;
            curr = currhead;
            while(curr||currhead == head1){
                if((curr == nullptr) && (currhead == head1)){curr = head2; currhead == head2;}
                //Jump to list 2
                if(currhead == head1){
                    if(curr->val >= x )
                }
            }
            
        }
    };