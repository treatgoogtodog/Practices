#include "LnkList.h"
#include <iostream>

class Solution1{
public:
    ListNode* oddEvenList(ListNode* head){
        if(!head || !head->next){return head;}
        ListNode* EvenHead = nullptr;
        ListNode* EvenCurr = nullptr;
        ListNode* OddHead = nullptr;
        ListNode* OddCurr = nullptr;

        ListNode* Curr = head;

        int flip_flop = 0;
        while (Curr)
        {
            ListNode* ToAdd = Curr;
            Curr = Curr->next;
            flip_flop = (flip_flop == 0)? 1 : 0;
            if(flip_flop){
                Add(OddHead,OddCurr,ToAdd);
            }else{
                Add(EvenHead,EvenCurr,ToAdd);
            }
        }
        if (OddCurr) OddCurr->next = EvenHead;
        return OddHead ? OddHead : EvenHead;
    }
private:
    void Add(ListNode*& head, ListNode*& curr, ListNode* ToAdd){
        if(!curr){CreateNew(head, curr, ToAdd); return;}
        curr-> next = ToAdd;
        ToAdd->next = nullptr;
        curr = curr->next;
    }
    void CreateNew(ListNode*& head,ListNode*& curr, ListNode* ToAdd){
        head = ToAdd;
        ToAdd->next = nullptr;
        curr = head;
    }    
};

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution1 sol;
    ListNode* result = sol.EvenOddList(head);

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