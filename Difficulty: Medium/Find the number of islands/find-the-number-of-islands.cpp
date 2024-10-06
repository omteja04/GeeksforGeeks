//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    int n, m;
    int cnt = 0;
    int dir[8][2] = {{0, 1}, {1, 0}, {1, 1}, {0, -1}, {-1, 0}, {-1, -1}, {1, -1}, {-1, 1}};
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == '0') return;
        
        grid[i][j] = '0';
        
        for(int d = 0; d < 8; d++) {
            int x = i + dir[d][0];
            int y = j + dir[d][1];
            dfs(grid, x, y);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        n = grid.size();
        m = grid[0].size();
        for(int i = 0 ; i < n; i ++) {
            for(int j = 0 ; j  < m; j++) {
                if(grid[i][j] == '1') {
                    dfs(grid, i, j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends