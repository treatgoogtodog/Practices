#include <iostream>
#include "LnkList.h"

using namespace std;

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* NodeL = nullptr;
        ListNode* NodeR = nullptr;
        ListNode* NodeLs = nullptr;
        ListNode* NodeRs = nullptr;
        bool gotL = false;
        bool gotR = false;

        while (curr && curr->next) {
            // Detect start of duplicates
            if ((curr->val == curr->next->val) && !gotL) {
                NodeL = curr;
                NodeLs = prev;
                gotL = true;
            }
            
            // Detect end of duplicates
            if (gotL && ((curr->next->next == nullptr) || 
                (curr->next->val != curr->val))) {
                NodeR = curr->next;
                NodeRs = curr->next->next;
                gotR = true;
            }

            if (gotL && gotR) {
                DeleteLR(NodeL, NodeR);
                LinkLR(head, NodeLs, NodeRs);
                gotL = false;
                gotR = false;
                if (NodeRs) {
                    curr = NodeRs;
                    prev = NodeLs;
                } else {
                    return head;
                }
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }

private:
    void DeleteLR(ListNode* Left, ListNode* Right) {
        if (!Left || Left == Right) return;
        ListNode* curr = Left;
        while (curr && curr != Right) {
            ListNode* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }

    void LinkLR(ListNode*& Head, ListNode* Left, ListNode* Right) {
        if (!Left) {
            Head = Right; // Update head when Left is nullptr
            return;
        }
        if (!Right) {
            Left->next = nullptr;
            return;
        }
        Left->next = Right;
    }
};

void printLnk(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    if (!freopen("d:\\Repo\\Practices\\RemoveDuplicate.inp", "r", stdin)) {
        cerr << "Could not open input file" << endl;
        return 1;
    }
    freopen("RemoveDuplicate.out", "w", stdout);
    int n;
    cin >> n; // Number of elements in the linked list

    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for (int i = 0; i < n; ++i) {
        int data;
        cin >> data;
        ListNode* newNode = new ListNode(data);

        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    Solution solution;
    head = solution.deleteDuplicates(head);

    printLnk(head);

    // Free memory
    ListNode* current = head;
    while (current) {
        ListNode* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}