class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int R=text1.size(),C=text2.size();
        int dp[R+1][C+1];

        for(int r=0;r<=R;r++){
            for(int c=0;c<=C;c++){
                dp[r][c]=0;
            }
        }
        for(int row=1;row<=R;row++){
            for(int col=1;col<=C;col++){
                if(text1[row-1]==text2[col-1]){
                   dp[row][col]=1+dp[row-1][col-1];
                }
                else{
                    dp[row][col]=max(dp[row][col-1],dp[row-1][col]);
                }

            }
        }
        return dp[R][C];
    }
};