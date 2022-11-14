// class Solution {
// public:
//     int findPeakElement(vector<int>& nums) {
        
//         int ans=0;
//         for(int i=1; i<nums.size(); i++){
//             if((nums[i] > nums[i-1]) && (nums[i] > nums[i+1]) || i==nums.size()-1){
//                 ans=i;
//                 break;
//             }
               
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1)
            return 0;
        int ans=0,s=0,e=nums.size()-1;
        while(s<e)
        {
            int mid = s+(e-s)/2;
            if(nums[mid] > nums[mid+1]){
                e=mid;
                // break;
            }
            else
                s=mid+1;
        }
        
        return s;
    }
};