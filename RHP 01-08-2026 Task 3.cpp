class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int R=nums1.size(),C=nums2.size(),maxLen=0;
        int dp[R+1][C+1];
        for(int r=0;r<=R;r++){
            for(int c=0;c<=C;c++){
                dp[r][c]=0;
            }
        }
        for(int i=1;i<=R;i++){
            for(int j=1;j<=C;j++){
                if(nums1[i-1]==nums2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    maxLen=max(maxLen,dp[i][j]);
                }
            }
        }
        return maxLen;
    }
};