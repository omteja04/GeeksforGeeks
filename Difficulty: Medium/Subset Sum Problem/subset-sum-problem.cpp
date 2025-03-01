//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// User function template for C++

class Solution {
  public:
    bool backtrack(int i, vector<int> &arr, int target, vector<vector<int>> &dp) {
        if(i == 0) {
            if(target == arr[i]) return true;
            else return false;
        }
        if(target == arr[i]) {
            return true;
        }
        if(dp[i][target] != -1) {
            return dp[i][target];
        }
        bool take = false, notTake = false;
        if(target >= arr[i]) {
            take = backtrack(i - 1, arr, target - arr[i], dp);
        }
        notTake = backtrack(i - 1, arr, target, dp);
        
        return dp[i][target] = take || notTake;
    }
    bool isSubsetSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return backtrack(n - 1, arr, target, dp);
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