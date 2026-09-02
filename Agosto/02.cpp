// Word Break - Leetcode

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();

        vector<bool> dp(n, false);

        unordered_map<string, bool> inDict;

        for (string word : wordDict) {
            inDict[word] = true;
            if (word == string(1, s[0])) dp[0] = true;
        }

        for (int i=1;i<n;i++){
            string newWord = "";

            for (int j=i;j>=0 && i-j+1 <= 1000;j--){
                newWord = s[j] + newWord;
                if ((j == 0 || dp[j-1]) && inDict[newWord]) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n-1];
    }
};