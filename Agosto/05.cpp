// Longest Increasing Path in a Matrix - Leetcode

class Solution {
public:
    void dfs(vector<vector<int>>& matrix, vector<vector<int>>& longest,vector<vector<bool>>& visited, int i, int j){
        if (visited[i][j]) return;
        
        visited[i][j] = true;

        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        int length = 1;

        for (int k=0; k<4;k++){
            int nx = i + dx[k];
            int ny = j + dy[k];

            if (nx >= 0 && ny >= 0 && nx < m && ny < n && matrix[nx][ny] > matrix[i][j]){
                dfs(matrix, longest, visited, nx, ny);
                longest[i][j] = max(longest[i][j], longest[nx][ny]+1);
            }
        }


    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> longest(m, vector<int>(n, 1));

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int length = 1;

        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (!visited[i][j]){
                    dfs(matrix, longest, visited, i, j);
                    length = max(length, longest[i][j]);
                }
                
            }
        }

        return length;
    }
};