// Partition Equal Subset Sum - Leetcode

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n =nums.size();
        int target = 0;

        for (int i=0;i<n;i++){
            target += nums[i];
        }

        if (target%2 == 1) return false;

        target = target/2;

        vector<vector<bool>> dp(target+1, vector<bool>(n+1, false));

        for (int j=0;j<n+1;j++) dp[0][j] = true;

        for (int j=1;j<=n;j++){
            for (int i=1;i<=target;i++){
                if (nums[j-1] > i) dp[i][j] = dp[i][j-1];
                else dp[i][j] = dp[i][j-1] || dp[i-nums[j-1]][j-1];
            }
        }

        return dp[target][n];


    }
};