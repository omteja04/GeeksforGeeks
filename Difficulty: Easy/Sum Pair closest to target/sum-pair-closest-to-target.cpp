//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        // code here
        int minDiff = INT_MAX;
        sort(arr.begin(), arr.end());
        vector<int> ans;
        int low = 0;
        int high = arr.size() - 1;
        while(low < high) {
            int sum = arr[low] + arr[high];
            int cDiff = abs(target - sum);
            if(cDiff < minDiff) {
                minDiff = cDiff;
                ans = {arr[low], arr[high]};
            }
            if(sum < target) {
                low++;
            } else if(sum > target) {
                high--;
            } else {
                return ans;
            }
        }
        // if(ans[0] == -1) return ans;
        return ans;
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
        string ks;
        getline(cin, ks);
        int target = stoi(ks);
        Solution ob;
        vector<int> ans = ob.sumClosest(arr, target);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto it : ans) {
                cout << it << " ";
            }
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends