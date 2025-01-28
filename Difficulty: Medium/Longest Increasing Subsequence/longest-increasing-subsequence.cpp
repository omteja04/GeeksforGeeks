//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to find length of longest increasing subsequence., int
    int dp[10010];
    int rec(vector<int> &arr, int level) {
        if(level < 0) return 0;
        int ans = 1;
        if(dp[level] != -1) return dp[level];
        for(int prev = 0; prev < level; prev++) {
            if(arr[prev] < arr[level]) {
                ans = max(ans, 1 + rec(arr, prev));
            }
        }
        return dp[level] = ans;
        
    }
    int lis(vector<int>& arr) {
        // code here
        memset(dp, -1, sizeof(dp));
        int ans = 0;
        for(int i = 0; i  <arr.size(); i++) {
            ans = max(rec(arr, i), ans);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input

    while (t--) {
        int n;
        vector<int> arr;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            arr.push_back(num);

        Solution obj;
        cout << obj.lis(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends