class Solution {
  public:
void buildDp(string &str, vector<vector<bool>> &dp) {
    int n = str.size();
    dp.assign(n, vector<bool>(n, false));
    for(int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }
    for(int i = 0; i < n - 1; i++) {
        dp[i][i + 1] = (str[i] == str[i + 1]);
    }
    for(int length = 3; length <= n; length++) {
        for(int i = 0; i <= n - length; i++) {
            int j = i + length - 1;
            dp[i][j] = dp[i + 1][j - 1] && (str[i] == str[j]);
        }
    }
}
void backtrack(string &str, int startIndex, vector<vector<bool>> &dp, vector<string> &curr, vector<vector<string>> &res) {
    if(startIndex >= str.size()) {
        res.push_back(curr);
        return;
    }
    for(int end = startIndex; end < str.size(); end++) {
        if(dp[startIndex][end]) {
            curr.push_back(str.substr(startIndex, end - startIndex + 1));
            backtrack(str, end + 1, dp, curr, res);
            curr.pop_back();
        }
    }
}
vector<vector<string>> palinParts(string &s) {
    vector<vector<bool>> dp;
    buildDp(s, dp);

    vector<vector<string>> result;
    vector<string> current;
    backtrack(s, 0, dp, current, result);
    return result;
}
};