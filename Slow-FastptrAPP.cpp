#include <iostream>
#include <fstream>

using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int val) : val(val), next(nullptr) {};
};

class Solution1{
    public:
        Node* ApplySlowFast(Node* head){
            Node* slow = head;
            Node* fast = head;
            Node* lastEnd = nullptr;
            while(fast && fast->next) {
                lastEnd = slow;
                slow = slow->next;
                fast = fast->next->next;
            }
            Node* second_head = slow;
            lastEnd->next = nullptr;
            Node* first_head = head;

            Node* curr1 = first_head;
            Node* curr2 = second_head;
            
            while(curr2){
                Node* sav_next1 = curr1->next;
                Node* sav_next2 = curr2->next;
                curr1->next = curr2;
                curr2->next = sav_next;
                curr1 = curr1->next;
                curr2 = sav_next2;
            }
            return head;
        }
};
