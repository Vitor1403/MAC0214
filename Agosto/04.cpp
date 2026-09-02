// Burst Balloon - Leetcode

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        nums.push_back(nums[n-1]);
        nums.push_back(1);


        for (int i=1;i<n;i++) {
            swap(nums[0], nums[i]);
        }

        nums[0] = 1;

        nums[0] = 1;

        int l = 1;
        int r = n;

        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));

        for (int i=0;i<n+2;i++){
            dp[i][i] = 0;
        }

        for (int i=0;i<n+2;i++){
            for (int j=0;j+i<n+2;j++){
                for (int k=j+1;k<j+i;k++){
                    dp[j][j+i] = max(dp[j][j+i], dp[j][k] + nums[j]*nums[k]*nums[i+j]+ dp[k][j+i]);
                }
            }
        }

        return dp[0][n+1];
    }
};