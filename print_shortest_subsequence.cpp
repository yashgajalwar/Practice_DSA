class Solution {
public:
    
//     string func(string str1,string str2,int n,int m,string s){
//         if(n==0){
//             while(m!=0){
//                 s.push_back(str2[m-1]);
//                 m--;
//             }
//             return s;
//         }
//         if(m==0){
//             while(n!=0){
//                 s.push_back(str1[n-1]);
//                 n--;
//             }
//             return s;
//         }
//         if(str1[n-1]==str2[m-1]){
//             return func(str1,str2,n--,m--,s.push_back(str1[n-1]));
//         }
//         else{
            
//             if(func(str1,str2,n--,m,s.append(str1[n-1])).length() < func(str1,str2,n,m--,s.append(str2[m-1])).length()){
//                 return    func(str1,str2,n--,m,s.push_back(str1[n-1]));
//             }
//             else{
//                 return func(str1,str2,n,m--,s.push_back(str2[m-1]));
//             }
            
//         }
        
//     }
    
    // string func(string s1,string s2,int n,int m,string s){
    //     vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    //     for(int i=0;i<n+1;i++){
    //         dp[i][0]=i;
    //     }
    //     for(int j=0;j<m+1;j++){
    //         dp[0][j]=j;
    //     }
    //     for(int i=0;i<n+1;i++){
    //         for(int j=0;j<m+1;j++){
    //             if(s1[i-1]==s2[j-1]){
    //                 dp[i][j]=1+dp[i-1][j-1];
    //             }
    //             else{
    //                 dp[i][j]=1+min(dp[i-1][j],dp[i][j-1]);
    //             }
    //         }
    //     }
    //     int i=n, j=m;
    //     int cur=dp[n][m];
    //     while(i>0 && j>0 && cur>0){
    //         if(s1[i]==s2[j]){
    //            // s.push_back(s1[i-1]);
    //             i--;
    //             j--;
    //         }
    //         else{
    //             if(dp[i-1][j] < dp[i][j-1]){
    //                 //s.push_back(s1[i-1]);
    //                 i--;
    //             }
    //             else{
    //                // s.push_back(s2[j-1]);
    //                 j--;
    //             }
    //         }
    //         cur--;
    //     }
    //     return s;
    // }
    string func(string s,string t){
        int n=s.length();
        int m=t.length();
        string ans;
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<n+1;i++){
            dp[i][0]=i;
        }
        for(int j=0;j<m+1;j++){
            dp[0][j]=j;
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=1+min(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int i=n,j=m;
        while(i>0 && j>0){
            if(s[i-1]==t[j-1]){
                ans.push_back(s[i-1]);
                i--;
                j--;
            }
            else if(dp[i-1][j] < dp[i][j-1]){
                ans.push_back(s[i-1]);
                i--;
            }
            else{
                ans.push_back(t[j-1]);
                j--;
            }
        } 
        while(i>0){
            ans.push_back(s[i-1]);
            i--;
        }
        while(j>0){
            ans.push_back(t[j-1]);
            j--;
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    string shortestCommonSupersequence(string str1, string str2) {
       //  int n=str1.length();
       //  int m=str2.length();
       //  string s;
       //  string ans=func(str1,str2,n,m,s);
       // // reverse(ans.begin(),ans.end());
       //  return ans;
        
        return func(str1,str2);
        
    }
};