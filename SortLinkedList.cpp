#include <iostream>
using namespace std;

struct ListNode {
    int data;
    ListNode* next;

    ListNode(int nodeData) {
        data = nodeData;
        next = nullptr;
    }
};

void split(ListNode* head, ListNode** left, ListNode** right){
    ListNode* slow = head;
    ListNode* fast = head->next;
    
    while(fast&&fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    *left = head;
    *right = slow->next;
    slow->next = NULL;
}

ListNode* merge(ListNode* left, ListNode* right){
    if(!left) return right;
    if(!right) return left;
    
    ListNode* res = NULL;
    if(left->data <= right->data){
        res = left;
        res->next = merge(left->next,right);
    }else{
        res = right;
        res->next = merge(left, right->next);
    }
    return res;
}

ListNode* sortList(ListNode* head){
    if(!head || !head->next)return head;

    ListNode* left = NULL;
    ListNode* right = NULL;

    split(head, &left, &right);

    left = sortList(left);
    right = sortList(right);

    return merge(left,right);
}

void printLnk(ListNode* head){
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout << endl;
}

int main(){
    if(!freopen("d:\\Repo\\Practices\\SortLnkList.inp","r",stdin)){cerr<<"Could not open file";};
    freopen("d:\\Repo\\Practices\\SortLnkList.out","w",stdout);

    int n;
    cin >> n;

    ListNode* head = NULL;
    ListNode* tail = NULL;

    for(int i = 0; i < n; ++i){
        int data;
        cin >> data;
        ListNode* newNode = new ListNode(data);

        if(!head){
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    head = sortList(head);
    printLnk(head);

    ListNode* current = head;
    while (current != nullptr) {
        ListNode* next = current->next;
        delete current;
        current = next;
    }
}