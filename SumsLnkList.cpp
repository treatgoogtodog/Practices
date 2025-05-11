#include "LnkList.h"
#include <iostream>


class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode* Lres = nullptr;
            ListNode* curr1 = l1;
            ListNode* curr2 = l2;
            ListNode* currRes = nullptr;
            int rem = 0;
            if(!curr1&&!curr2){
                Lres = new ListNode();
            }

            while(curr1||curr2){
                int sums = rem;
                if(curr1&&curr2){
                    sums += curr1->val + curr2->val;
                }
                if(!curr1){sums += curr2->val;}
                if(!curr2){sums += curr1->val;}
                rem = sums/10;
                sums = sums%10;
                if(!Lres){Lres = new ListNode(sums);currRes = Lres;}
                else{
                    currRes->next = new ListNode(sums);
                    currRes = currRes->next;
                }
    
                if(curr1){curr1 = curr1->next;}
                if(curr2){curr2 = curr2->next;}
            }
            if(rem > 0){currRes->next = new ListNode(rem);}
            return Lres;
        }
};

using namespace std;

void printLnk(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    if (!freopen("SumsLnkList.inp", "r", stdin)) {
        cerr << "Could not open input file" << endl;
        return 1;
    }
    freopen("SumsLnkList.out", "w", stdout);

    int n1, n2;
    cin >> n1;
    ListNode* l1 = nullptr;
    ListNode* tail1 = nullptr;

    for (int i = 0; i < n1; ++i) {
        int data;
        cin >> data;
        ListNode* newNode = new ListNode(data);

        if (!l1) {
            l1 = newNode;
            tail1 = newNode;
        } else {
            tail1->next = newNode;
            tail1 = newNode;
        }
    }

    cin >> n2; // Number of elements in the second linked list
    ListNode* l2 = nullptr;
    ListNode* tail2 = nullptr;

    for (int i = 0; i < n2; ++i) {
        int data;
        cin >> data;
        ListNode* newNode = new ListNode(data);

        if (!l2) {
            l2 = newNode;
            tail2 = newNode;
        } else {
            tail2->next = newNode;
            tail2 = newNode;
        }
    }

    Solution solution;
    ListNode* result = solution.addTwoNumbers(l1, l2);

    printLnk(result);

 
    ListNode* current = l1;
    while (current) {
        ListNode* next = current->next;
        delete current;
        current = next;
    }

    current = l2;
    while (current) {
        ListNode* next = current->next;
        delete current;
        current = next;
    }

    current = result;
    while (current) {
        ListNode* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}