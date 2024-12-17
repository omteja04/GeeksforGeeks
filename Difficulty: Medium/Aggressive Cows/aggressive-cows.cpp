//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
     int canCows(vector<int>&stalls,int k){
        int prev=stalls[0];
        int cnt=1;
        for(int &curr: stalls){
            if((curr-prev)>=k){
                cnt++;
                prev=curr;
            }
        }
        return cnt;
    }

    int aggressiveCows(vector<int> &stalls, int k) {
        if(k > stalls.size()) return 0;
        // Write your code here
        sort(stalls.begin(),stalls.end());
        int low=0;
        int ans;
        int high= stalls.back()-stalls.front();
        while(low<=high){
            int mid=low+(high - low)/2;
            int cows = canCows(stalls,mid);
            if(cows>=k){
                low=mid+1;
                ans=mid;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends