// Integer Break - Leetcode

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 1);

        for (int i=2;i<=n;i++){
            for (int j=1;j<=i && j < n;j++){
                dp[i] = max(dp[i], j*dp[i-j]);
            }
        }

        return dp[n];
        
    }
};