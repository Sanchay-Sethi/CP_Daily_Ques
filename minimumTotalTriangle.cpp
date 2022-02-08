class Solution {
public:
    int dp[202][202];
    int rec(vector<vector<int>>& t, int i, int j){
        if(i==t.size()-1) return t[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j] = min(rec(t, i+1, j), rec(t, i+1, j+1)) + t[i][j];
    }
    int minimumTotal(vector<vector<int>>& t) {
        for(int i = 0; i<202; i++){
            for(int j = 0; j<202; j++){
                dp[i][j] = -1;
            }
        }
        int ans = rec(t, 0, 0);
        return ans;
    }
};
