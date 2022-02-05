class Solution {
public:
    int dp[101][101];
    int rec(int m,  int n){
        if(m==0 or n==0) return 1;
        if(dp[m][n]!=-1) return dp[m][n];
        int ans = rec(m, n-1) + rec(m-1, n);
        return dp[m][n] = ans;
    }
    int uniquePaths(int m, int n) {
        for(int i = 0; i<101; i++){
            for(int j = 0; j<101; j++){
                dp[i][j] = -1;
            }
        }
        int ans = rec(m-1,  n-1);
        return ans;
    }
};
