//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool solve(int idx, int sum, vector<int> &arr, vector<vector<int>> &dp) {
        if(idx == 0) {
            if(sum == arr[idx]) return 1;
            return 0;
        }
        if(sum == arr[idx]) return 1;
        if(dp[idx][sum] != -1) return dp[idx][sum];
        
        bool pick = false, nonPick = false;
        
        if(arr[idx] <= sum) {
            pick = solve(idx - 1, sum - arr[idx], arr, dp);
        }
        nonPick = solve(idx - 1, sum, arr, dp);
        return dp[idx][sum] = pick || nonPick;
        
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
        return solve(n - 1, sum, arr, dp);
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends