class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        while(l+1<r){
            int m=(l+r)/2;
            if(nums[m]<target) l=m;
            else r=m;
        }
        return nums[l]==target?l:nums[r]==target?r:-1;
    }
};