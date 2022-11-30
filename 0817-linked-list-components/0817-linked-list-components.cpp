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
    int numComponents(ListNode* head, vector<int>& nums) {
        set<int> s;
        int c=0;
        for(auto i:nums){
            s.insert(i);
        }
        ListNode* temp = head;
        while(temp!=NULL){
            if(s.count(temp->val)){
                c++;
                while(temp!=NULL && s.count(temp->val)){
                    temp = temp->next;
                }
            }
            else{
                temp = temp->next;
            }
        }
        return c;
    }
};