

// Scrambled String Problem
//Qlink : https://leetcode.com/problems/scramble-string/






class Solution {
public:
    bool func(string s1,string s2,map<string,bool>& mp){
        if(s1.length()!=s2.length()) return false;
        if(s1.length()==0) return true;
        
        if(s1==s2) return true;
        
        string copys1=s1;
        string copys2=s2;
        sort(copys1.begin(),copys1.end());
        sort(copys2.begin(),copys2.end());
        if(copys1!=copys2) return false;
        
        string key = s1+" "+s2;
        for(auto it: mp){
            if(it.first ==key){
                return it.second;
            }
        }
        bool flag=false;
        
        int n=s1.length();
        for(int i=1;i<n;i++){
            if(func(s1.substr(0,i),s2.substr(0,i),mp) &&
               func(s1.substr(i,n-i),s2.substr(i,n-i),mp)){
                flag=true;
                return true;
            }
            if(func(s1.substr(0,i),s2.substr(n-i,i),mp) &&
               func(s1.substr(i,n-i),s2.substr(0,n-i),mp)){
                flag=true;
                return true;
            }
        }
        mp[key] =false;
        return false;
    }
    
    bool isScramble(string s1, string s2) {
        
        map<string,bool> mp;
        if(func(s1,s2,mp)) return true;
        return false;
        
    }
};
