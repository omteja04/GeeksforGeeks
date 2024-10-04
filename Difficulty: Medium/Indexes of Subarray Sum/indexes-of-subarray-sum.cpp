//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        // Your code here
        vector<int> vec;
        int i=0;
        if(s==0){
            for(i=0;i<arr.size();i++)
            {
                if(arr[i]==0)
                {
                    vec.push_back(i+1);
                    vec.push_back(i+1);
                    return vec;
                }
            }
            vec.push_back(-1);
            return vec;
        }
        i = 0;
        int j=0,c_sum=0;
        while(j<n){
            c_sum+=arr[j];
            
            while(c_sum>s){
                c_sum-=arr[i];
                i++;
            }
            if(c_sum==s){
                vec.push_back(i+1);
                vec.push_back(j+1);
                return vec;
            }
            j++;
        }
        vec.push_back(-1);
        return vec;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long s;
        cin >> n >> s;
        vector<int> arr(n);
        // int arr[n];
        const int mx = 1e9;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> res;
        res = ob.subarraySum(arr, n, s);

        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends