//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find maximum of each subarray of size k.
    vector<int> max_of_subarrays(int k, vector<int> &arr) {
        // your code here
        vector<int>vec;
        int n = arr.size();
        int maxi = *max_element(arr.begin(), arr.begin() + k);
        vec.push_back(maxi);
        
        for(int i = 1;  i <= arr.size() - k;i++) {
            if(arr[i - 1] == maxi) {
                maxi = *max_element(arr.begin() + i, arr.begin()+ i + k);
            }
            else {
                maxi = max(maxi, arr[i + k - 1]);
            }
            
            vec.push_back(maxi);
        }
        return vec;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();

    while (t--) {

        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> res = obj.max_of_subarrays(k, arr);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends