//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        // Your code here
        int maxArea = 0;
        stack<pair<int, int>> st;
        arr.push_back(0);
        int n = arr.size();
        for(int i = 0; i < n; i++) {
            int start = i;
            while(!st.empty() && st.top().second > arr[i]) {
                auto it = st.top();
                int idx = it.first;
                int height = it.second;
                st.pop();
                maxArea = max(maxArea, height * (i - idx));
                start = idx;
            }
            st.push({start, arr[i]});
        }
        return maxArea;
        
    }
};



//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends