struct Node {
    int value;
    Node *next;
};

Node* deleteBottom(Node* head) {
    if (!head || !head->next) return head;
    Node* prev = nullptr;
    Node* curr = head;

    while (curr->next) {
        if (curr->value < curr->next->value) { 
            if (!prev || prev->value > curr->value) {
                Node* Del = curr;
                if (prev) {
                    prev->next = curr->next;
                } else {
                    head = curr->next;
                }
                delete Del;
                return head;
            }
        }
        prev = curr;
        curr = curr->next;
    }
    return head;
}

#include <iostream>
using namespace std;

void printList(Node* head) {
    while (head) {
        cout << head->value << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;
    int value;
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++){
        cin >> value;
        Node* newNode = new Node{value, nullptr};
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    head = deleteBottom(head);

    printList(head);

    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}