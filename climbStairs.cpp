class Solution {
public:
    int DP[47];
    int rec(int n){
        if(n<0) return 0;
        if(n==0 or n==1) return 1;
        if(DP[n]!=-1) return DP[n];
        int ans = rec(n-1) + rec(n-2);
        return DP[n] = ans;
    }
    int climbStairs(int n) {
        //Bottom Up
        // int arr[n+1];
        // arr[0] = 1;
        // arr[1] = 1;
        // for(int i = 2; i<=n; i++){
        //     arr[i] = arr[i-1] + arr[i-2];
        // }
        // return arr[n];
        
        //Top bottom
        for(int i = 0; i<47; i++) DP[i] = -1;
        int ans = rec(n);
        return ans;
    }
};
