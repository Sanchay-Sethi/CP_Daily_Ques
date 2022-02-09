class Solution {
public:
    int dp[1005][2][105];
    //i  = current index
    int rec(vector<int>& prices, int i, int hold, int tt, int k){
        
        if(tt>=k or i>=prices.size()) return 0;
        
        if(dp[i][hold][tt]!=-1) return dp[i][hold][tt];
        
        if(hold==0){ //kuch nhi kahrida to buy karenge yaa nhi
            int opt1 = rec(prices, i+1, 1, tt, k) - prices[i];
            int opt2 = rec(prices, i+1, 0, tt, k);
            return dp[i][hold][tt] = max(opt1, opt2);
        }
        else if(hold==1){
            int opt1 = rec(prices, i+1, 0, tt+1, k) + prices[i];
            int opt2 = rec(prices, i+1, 1, tt, k);
            
            return dp[i][hold][tt] = max(opt1, opt2);
        }
        return 0;
    }
    int maxProfit(int k, vector<int>& prices) {
        for(int i = 0; i<1005; i++){
            for(int j = 0; j<2; j++){
                for(int k = 0; k<105; k++){
                    dp[i][j][k] = -1;
                }
            }
        }
        int ans = rec(prices, 0, 0, 0, k); //i hold total transaction
        return ans;
    }
};
