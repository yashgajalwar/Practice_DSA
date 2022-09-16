//{ Driver Code Starts
// Initial Template for C++



// Rod Cutting Problem
// Q link : https://practice.geeksforgeeks.org/problems/rod-cutting0840/0


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int func(int price[],int n,int profit,int len,int pos,vector<vector<int>>& dp){
        if(len>n){
            return 0;
        }
        if(pos>=n){
            dp[pos][len]=profit;
            return dp[pos][len];
        }
        if(dp[pos][len]!=-1){
            return dp[pos][len];
        }
        
        dp[pos][len]= max(func(price,n,profit,len,pos+1,dp),
            func(price,n,profit+price[pos],len+pos+1,pos,dp));
            return dp[pos][len];
    }
  
    int cutRod(int price[], int n) {
        //code here
        //int dp[n+1][n+1];
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        
        //memset(dp,-1,sizeof(dp));
        for(int i=0;i<n+1;i++){
            dp[0][i]=0;
            dp[i][0]=0;
        }
        //memoisation approach
        //  func(price,n,0,0,0,dp);
        //  return dp[n][n];
        
        //bottom up approach
        for(int i=1;i<n+1;i++){
            for(int j=1;j<n+1;j++){
                if(j<i){
                    dp[i][j]=dp[i-1][j];
                }
                else {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-i]+price[i-1]);
                }
            }
        }
        // for(int i=0;i<n+1;i++){
        //     for(int j=0;j<n+1;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        return dp[n][n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
