class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
       int N=nums.size(),sum=0;
        long finalV=0,ans=0;
        for(int i=0;i<N;i++){
            sum+=nums[i];
            finalV+=(i*nums[i]);
        }
        ans=finalV;
        for(int li=N-1;li>0;li--){
            finalV=finalV-(nums[li]*(N-1))+(sum-nums[li]);
            ans=max(ans,finalV);
        }
        return (int)ans; 
    }
};