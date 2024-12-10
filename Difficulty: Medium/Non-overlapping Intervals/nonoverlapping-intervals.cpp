//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minRemoval(vector<vector<int>> &intervals) {
        // code here
        sort(intervals.begin(), intervals.end(),[](vector<int> &a, vector<int> &b){return a[1] < b[1];});
        int cnt = 0;
        int end = INT_MIN;
        for(auto &interval : intervals) {
            int st = interval[0];
            int e = interval[1];
            if(st < end) {
                cnt++;
            } else { 
                end = e;
            }
        }
        return cnt;
        // [1,2][1,3][2,3][3,4]
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        Solution obj;
        cout << obj.minRemoval(intervals) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends