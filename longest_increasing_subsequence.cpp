

// Longest Increasing Subsequence

// Q link: https://leetcode.com/problems/longest-common-subsequence/






class Solution {
public:
    // int func(string text1,string text2,int n,int m){
    //     if(m==0 || n==0){
    //         return 0;
    //     }
    //     if(text1[n-1]==text2[m-1]){
    //         return 1+func(text1,text2,n-1,m-1);
    //     }
    //     else{
    //         return max(func(text1,text2,n-1,m),func(text1,text2,n,m-1));
    //     }
    // }
//     int memoize(string text1,string text2,int n,int m,vector<vector<int>>& dp){
//         if(n==0 || m==0){
//             dp[n][m]=0;
//             return dp[n][m];
//         }
//         if(dp[n][m]!=-1){
//             return dp[n][m];
//         }
//         if(text1[n-1]==text2[m-1]){
//             dp[n][m]=1+memoize(text1,text2,n-1,m-1,dp);
//         }
//         else{
//             dp[n][m]=max(memoize(text1,text2,n-1,m,dp),
//                          memoize(text1,text2,n,m-1,dp));
//         }
//         return dp[n][m];
        
//     }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length();
        int m=text2.length();
        // func is using recursive code 
        //return func(text1,text2,n,m);
        
        //memeoized code
//         vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
//         //memset(dp,-1,sizeof(dp));
        
//         for(int i=0;i<n+1;i++){
//             dp[i][0]=0;
//         }
//         for(int j=0;j<m+1;j++){
//             dp[0][j]=0;
//         }
//         memoize(text1,text2,n,m,dp);
//         return dp[n][m];
        
        // top down approach
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<n+1;i++){
            dp[i][0]=0;
        }
        for(int j=0;j<m+1;j++){
            dp[0][j]=0;
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};
