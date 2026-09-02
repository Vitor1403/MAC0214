// Maximum Product Subarray - Leetcode

class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int n = nums.size();
        
        vector<int> largest(n, 1);

        vector<int> smallest(n, 1);

        int maximum = nums[0];

        largest[0] = nums[0];

        smallest[0] = nums[0];

        for (int i=1;i<n;i++){
            largest[i] = max(nums[i]*largest[i-1], nums[i]);
            smallest[i] = min(nums[i]*smallest[i-1], nums[i]);

            if (nums[i] < 0) {
                largest[i] = max(smallest[i-1]*nums[i], largest[i]);
                smallest[i] = min(largest[i-1]*nums[i], smallest[i]);
            }

            maximum = max(maximum, largest[i]);
        }

        return maximum;
    }
};