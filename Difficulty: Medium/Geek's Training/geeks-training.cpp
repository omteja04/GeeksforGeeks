//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int fun(int ind, int last, vector<vector<int>>& arr, vector<vector<int>>& dp) {
        if(ind == 0) {
            int maxi = 0;
            for(int i = 0 ; i  <= 2; i++) {
                if(i != last)
                    maxi = max(maxi, arr[0][i]);
            }
            return maxi;
        }
        if(dp[ind][last] != -1) {
            return dp[ind][last];
        }
        int maxi = 0;
        for(int i = 0 ; i  <= 2; i++) {
            if(i != last) {
                int points = arr[ind][i] + fun(ind - 1, i, arr, dp);
                maxi = max(points, maxi);
            }
        }
        return dp[ind][last] = maxi;
    }
    int maximumPoints(vector<vector<int>>& arr, int n) {
        // Code here
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return fun(n - 1, 3, arr, dp);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr, n) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends