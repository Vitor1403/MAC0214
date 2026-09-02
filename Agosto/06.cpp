// Distinct Subsequences - Leetcode

class Solution {
public:

    vector<vector<long long>> memo;

    long long rec(const string& s, const string& t, int i, int j){
        if (j < 0) return 1;
        if (i < 0) return 0;

        if (memo[i][j] != -1) return memo[i][j];

        memo[i][j] = rec(s, t, i-1, j);

        if (s[i] == t[j]) memo[i][j] += rec(s, t, i-1, j-1);

        return memo[i][j];
    }

    long long numDistinct(string s, string t) {
        if (t.size() > s.size()) return 0;

        vector<vector<long long>> dp(s.size(), vector<long long>(t.size(), -1));

        memo = dp;

        return rec(s, t, s.size()-1, t.size()-1);
        
    }
};