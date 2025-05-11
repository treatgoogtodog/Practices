/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    public:
        int getTotal(ListNode* head){
            int index = 0;
            ListNode* curr = head;
            while(curr->next){index++; curr = curr->next;}
            return index;
        }
    
        ListNode* rotateRight(ListNode* head, int k) {
            ListNode *curr = head;
            ListNode *ToRotate = NULL;
            ListNode *NewEnd = NULL;
            int RealRotationI = k%this->getTotal(head);
            for(int i = 0; i < RealRotationI; i++){
                while(curr->next){
                    if(curr->next->next == NULL){NewEnd = curr;}
                    curr = curr->next; 
                }
                ToRotate = curr;
                NewEnd->next = NULL;
                ToRotate->next = head;
                head = ToRotate;
            }
            return head;
        }
    };