// Combination Sum IV - Leetcode

class Solution {
public:

    int combinations(vector<int>& memo, int x, vector<int>& nums, int n){
        if (x < 0) return 0;

        if (memo[x] != -1) return memo[x];

        memo[x] = 0;

        for (int i=0;i<n;i++){
            memo[x] += combinations(memo, x - nums[i], nums, n);
        }

        return memo[x]; 
    } 

    int combinationSum4(vector<int>& nums, int target) {

        int n = nums.size();
        vector<int> memo(target+1, -1);
        
        memo[0] = 1;

        combinations(memo, target, nums, n);

        return memo[target];
        
    }
};