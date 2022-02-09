class Solution {
public:
    int dp[105][105];
    bool rec(string &s1,string &s2,string &s3,int i,int j,int k,int n,int m,int mn){
        if(k>=mn) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        bool ans = 0;
        if(i<n && s1[i] == s3[k])
            ans = ans | rec(s1,s2,s3,i+1,j,k+1,n,m,mn);
        if(j<m  && s2[j] == s3[k])
            ans = ans | rec(s1,s2,s3,i,j+1,k+1,n,m,mn);  
        return  dp[i][j] =  ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n =s1.length();
        int m = s2.length();
        int mn = s3.length();
        if(m+n!=mn) return false;
        if(m==0) return s1==s3;
        if(n==0) return s2==s3;
        for(int i = 0; i<105; i++){
            for(int j = 0; j<105; j++){
                dp[i][j] = -1;
            }
        }
        bool ans = rec(s1, s2, s3, 0, 0, 0, n, m, mn);
        return ans;
    }
    
};
