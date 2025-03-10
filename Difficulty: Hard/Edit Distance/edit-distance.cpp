//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to compute the edit distance between two strings
    vector<vector<int>> dp;
    int memo(string& str1, string& str2, int m, int n) {
        if (m == 0 || n == 0)
            return max(m, n);
        if (dp[m][n] != -1)
            return dp[m][n];
        if (str1[m - 1] == str2[n - 1])
            return memo(str1, str2, m - 1, n - 1);
        int replace = memo(str1, str2, m - 1, n - 1);
        int insert = memo(str1, str2, m, n - 1);
        int del = memo(str1, str2, m - 1, n);
        return dp[m][n] = 1 + min(replace, min(insert, del));
    }
    int editDistance(string& s1, string& s2) {
        // code here
        int m = s1.length(), n = s2.length();
        dp.resize(m + 1, vector<int>(n + 1,  INT_MAX));
        for (int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }
        for (int i = 0; i <= n; i++) {
            dp[0][i] = i;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    int insert = dp[i][j - 1];
                    int del = dp[i - 1][j];
                    int replace = dp[i - 1][j - 1];
                    dp[i][j] = 1 + min(insert, min(replace, del));
                }
            }
        }
        return dp[m][n];
    }
};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string s1;
        getline(cin, s1);
        string s2;
        getline(cin, s2);
        Solution ob;
        int ans = ob.editDistance(s1, s2);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends