
// Minimum number of coins to be chosen to obtain given sum
// Q link : https://practice.geeksforgeeks.org/problems/number-of-coins1824/1


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	
	
	
// 	int func(int coins[],int M,int V,int pos,int cur,int n){
// 	    if(cur==V){
// 	        //checking if we get that required sum
// 	        return n;
// 	    }
// 	    if(pos>=M){
// 	        // if all the elements are traversed then return 
// 	        // here INT_MAX is returned as we require minimum number of coins
// 	        // so whenever this function returns  value it will be compared to
// 	        // and the minimum among those will be choosen.
// 	        return INT_MAX;
// 	    }
// 	    if(cur>V){
// 	        return INT_MAX;
// 	    }
// 	    return min(func(coins,M,V,pos+1,cur,n),func(coins,M,V,pos,cur+coins[pos],n+1));
	    
// 	}
	
	int minCoins(int coins[], int M, int V) 
	{ 
	    // recursive approach 
	    // This will give TLE as recursion will be exponential to the base 2 here.
	   // if(func(coins,M,V,0,0,0) == INT_MAX){
	   //     return -1;
	   // }
	   // return func(coins,M,V,0,0,0);
	   
	   
	   vector<vector<int>> dp(M+1,vector<int>(V+1,INT_MAX-1));
	   // in this question all initialisation are made INT_MAX-1 to avoid the 
	   // range of integer safely
	   for(int i=0;i<V+1;i++){
	       dp[0][i]=INT_MAX-1;
	   }
	   for(int i=1;i<M+1;i++){
	       dp[i][0]=0;
	   }
	   //sort(coins,coins+M,greater<int>());
	   
	   // One more row has to be initialised in this Q 
	   // the first row of matrix is  also initialised 
	   // here we will see that if it is completely divisible by the first coin 
	   // then it will be possible to make 'i' sum using coins[0]
	   // rest is self explanatory
	   for(int i=1;i<V+1;i++){
	       dp[1][i]= i%coins[0]==0 ? (i/coins[0]):INT_MAX-1;
	   }
	   //for(int i=0;i<V+1;i++){
	   //    cout<<dp[1][i]<<" ";
	   //}
	   //cout<<"\n";
	   for(int i=2;i<M+1;i++){
	       for(int j=1;j<V+1;j++){
	           if(coins[i-1]<=j){
	            dp[i][j] = min(dp[i-1][j],1+dp[i][j-coins[i-1]]);
	               
	           }
	           else{
	               dp[i][j]=dp[i-1][j];
	           }
	           //dp[i][j]=dp[i-1][j];
	           //if(dp[i][j-coins[i-1]]!=INT_MAX-1 && dp[i][j]>dp[i][j-coins[i-1]]){
	           //    dp[i][j] = 1+dp[i][j-coins[i-1]];
	           //}
	       }
	   }
	   //for(int i=1;i<2;i++){
	   //    for(int j=0;j<V+1;j++){
	   //        cout<<dp[i][j];
	   //    }
	   //    cout<<"\n";
	   //}
	   return dp[M][V]==INT_MAX-1 ?  -1 :  dp[M][V];
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends