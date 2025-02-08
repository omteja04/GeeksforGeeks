//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
        unordered_map<int, vector<string>> dp;
        vector<string> dfs(int idx, string s, unordered_set<string> &st) {
            if(dp.count(idx)) return dp[idx];
            if(idx >= s.length()) return {""};
            vector<string> res;
            for(int i = idx; i< s.length(); i++) {
                string word = s.substr(idx, i - idx + 1);
                if(st.count(word)) {
                    vector<string> suffixes = dfs(i + 1, s, st);
                    for(auto suffix : suffixes) {
                        res.push_back(word + (suffix.empty() ? "" : " ") + suffix);
                    }
                }
            }
            return dp[idx] =  res;
        }
  public:
    
    vector<string> wordBreak(vector<string>& dict, string s) {
        // code here
        unordered_set<string> st(dict.begin(), dict.end());
        return dfs(0, s, st);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> dict;
        string s;
        string line;
        getline(cin, line);
        stringstream ss(line);
        while (ss >> s) {
            dict.push_back(s);
        }
        cin >> s;
        cin.ignore();
        Solution ob;
        vector<string> ans = ob.wordBreak(dict, s);
        if (ans.size() == 0)
            cout << "Empty\n";
        else {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++)
                cout << "(" << ans[i] << ")";
            cout << endl;
        }
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends