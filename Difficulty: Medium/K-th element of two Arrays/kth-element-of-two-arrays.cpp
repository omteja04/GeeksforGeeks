//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(vector<int>& arr1, vector<int>& arr2, int k) {
        // code here
        int i = 0, j = 0;
        int ans = 0;
        while(k) {
            if(i >= arr1.size()) {
                ans = arr2[j];
                j++;
            } else if(j >= arr2.size()) {
                ans = arr1[i];
                i++;
            } else if (arr1[i] > arr2[j]) {
                ans = arr2[j];
                j++;
            } else {
                ans = arr1[i];
                i++;
            }
            k--;
        }
        return ans;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> a, b;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            b.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(a, b, k) << endl << "~\n";
    }
    return 0;
}
// } Driver Code Ends