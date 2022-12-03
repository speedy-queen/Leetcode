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
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next) return head;
        ListNode* head1 = new ListNode(-1), *tail1 = head1, *temp = head, *head2=new ListNode(-1), *tail2=head2;
        while(temp!=NULL)
        {
            if(temp->val < x){
                ListNode* newN = new ListNode(temp->val);
                tail1->next = newN;
                tail1 = newN;
            }
            temp=temp->next;
        }
        tail1->next=NULL;
        temp=head;
        while(temp!=NULL)
        {
            if(temp->val >= x){
                ListNode* newN = new ListNode(temp->val);
                tail2->next = newN;
                tail2 = newN;
            }
            temp=temp->next;
        }
        if(head1->next==NULL)
            return head2->next;
        head1=head1->next;
        tail1->next=head2->next;
        return head1;
    }
};