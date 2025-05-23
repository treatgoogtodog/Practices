#include <iostream>
#include <stdio.h>

#include "LnkList.h"

using namespace std;

int* getPointerToTen();

int main(){

    int n;
    cin >> n;
    int f1;
    cin >> f1;
    ListNode* head = new ListNode(f1);
    int i = 1;
    ListNode* curr = head;
    while (true)
    {
        int tmp;
        cin >> tmp;
        curr->next = new ListNode(tmp);
        curr = curr->next;
        i++;
        if(!(i<n)){break;}
    }
    
    for(ListNode* curr = head; curr; curr = curr->next){
        printf("%d\n", curr->val);
    }

    cout << *getPointerToTen();
}

int* getPointerToTen(){
    return new int(10);
}