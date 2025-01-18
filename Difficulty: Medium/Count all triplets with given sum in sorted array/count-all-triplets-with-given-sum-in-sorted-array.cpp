//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countTriplets(vector<int> &arr, int target) {
        // Code Here
        int cnt = 0;
        int n = arr.size();
        for(int i = 0; i < n - 2; i++) {
            int p1 = i + 1;
            int p2 = n - 1;
            while(p1 < p2) {
                int sum = arr[p1] + arr[p2] + arr[i];
                if(sum == target) {
                    cnt++;
                    int tp1 = p1 + 1;
                    int tp2 = p2 - 1;
                    while(tp1 < p2 && arr[tp1] == arr[p1]) {
                        tp1++;
                        cnt++;
                    }
                    while(tp2 > p1 && arr[tp2] == arr[p2]) {
                        tp2--;
                        cnt++;
                    }
                    p1++;
                    p2--;
                } else if(sum > target) {
                    p2--;
                } else {
                    p1++;
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

vector<int> lineArray() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> arr;
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }
    return arr;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr = lineArray();
        int target;
        cin >> target;
        cin.ignore();

        Solution ob;
        int res = ob.countTriplets(arr, target);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends