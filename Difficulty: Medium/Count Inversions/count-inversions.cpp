//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to count inversions in the array.
    int merge(vector<int> &arr, int low, int mid, int high) {
        vector<int> dummy;
        
        int i = low;
        int j = mid + 1;
        int cnt = 0;
        // int k = 0;
        
        while(i <= mid && j <= high) {
            if(arr[i] <= arr[j]) {
                dummy.push_back(arr[i++]);
            } else  {
                dummy.push_back(arr[j++]);
                cnt += (mid - i + 1);
            }
        }
        while(i <= mid) {
            dummy.push_back(arr[i++]);
        }
        while(j <= high) {
            dummy.push_back(arr[j++]);
        }
        
        for(int i = low; i <= high; i++) {
            arr[i] = dummy[i - low];
        }
        return cnt;
    }
    int helper(vector<int> &arr, int low, int high) {
        int cnt = 0;
        if(low >= high) return cnt;
        int mid = (high + low) / 2;
        cnt += helper(arr, low, mid);
        cnt += helper(arr, mid + 1, high);
        cnt += merge(arr, low, mid, high);
        return cnt;
    }
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        return  helper(arr, 0, arr.size() - 1);
        
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends