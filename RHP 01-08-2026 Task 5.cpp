class Solution {
public:
    int minDistance(string word1, string word2) {
        int R=word1.size(),C=word2.size();
        int dp[R+1][C+1];
        for(int i=0;i<=R;i++){
            for(int j=0;j<=C;j++){
                dp[i][j]=0;
            }
        }
        for(int row=1;row<=R;row++){
            for(int col=1;col<=C;col++){
                if(word1[row-1]==word2[col-1]){
                    dp[row][col]=1+dp[row-1][col-1];
                }
                else{
                    dp[row][col]=max(dp[row-1][col],dp[row][col-1]);
                }
            }
        }
        return (R-dp[R][C])+(C-dp[R][C]);
    }
};