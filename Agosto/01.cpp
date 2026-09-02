// Longest Palindromic Substring - Leetcode

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        vector<vector<int>> table(n, vector<int>(n, 0));

        int greaterLeft = 0;
        int greaterRight = 0;

        for (int i=0;i<n;i++){
            table[i][i] = 1;
        }

        for (int j=1;j<n;j++){
            for (int i=0;i<n-j;i++){
                if (j == 1) {
                    table[i][j+i] = s[i] == s[j+i] ? 2 : 1;
                } else if (table[i+1][i+j-1] == j-1){
                    table[i][i+j] = s[i] == s[i+j] ? j+1 : j-1;
                } else {
                    table[i][i+j] = table[i+1][i+j-1];
                }

                if (table[i][i+j] > greaterRight - greaterLeft + 1) {
                    greaterRight = i+j;
                    greaterLeft = i;
                }
            }
        }

        string palindrome = "";

        for (int i=greaterLeft; i<=greaterRight;i++){
            palindrome += s[i];
        }

        return palindrome;
    }
};