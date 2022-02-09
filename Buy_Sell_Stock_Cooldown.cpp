class Solution {
public:
    int dp[5002][2];
    //i  = current index
    int rec(vector<int>& prices, int i, int hold, int fee){
        
        if(i>=prices.size()) return 0;
        
        if(dp[i][hold]!=-1) return dp[i][hold];
        
        if(hold==0){
            int opt1 = rec(prices, i+1, 1, fee) - prices[i];
            int opt2 = rec(prices, i+1, 0, fee);
            return dp[i][hold] = max(opt1, opt2);
        }
        else if(hold==1){
            int opt1 = rec(prices, i+2, 0, fee) + prices[i]-fee;
            int opt2 = rec(prices, i+1, 1, fee);
            
            return dp[i][hold] = max(opt1, opt2);
        }
        return 0;
    }
    int maxProfit(vector<int>& prices) {
        for(int i = 0; i<5002; i++){
            for(int j = 0; j<2; j++){
                dp[i][j] = -1;
            }
        }
        int ans = rec(prices, 0, 0, 0); //i hold total transaction
        return ans;
    }
};
