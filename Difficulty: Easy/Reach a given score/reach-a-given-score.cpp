//{ Driver Code Starts
// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    // Complete this function
    long long solve(int idx, long long n, vector<int> &v, vector<vector<long long>> &dp) {
        if(n == 0) {
    	    return 1;
    	}
    	if(idx < 0) {
    	    return 0;
    	}
    	if(dp[idx][n] != -1) return dp[idx][n];
    	long long ans = 0;
        if(n >= v[idx]) {
            ans += solve(idx, n - v[idx], v, dp);
        }
        ans += solve(idx - 1, n, v, dp);
        return dp[idx][n] = ans;
    	
    	
    }
    long long int count(long long int n)
    {
    	// Your code here
    	vector<int> v={3,5,10};
    	vector<vector<long long>> dp(3, vector<long long>(n + 1, -1));
    	return solve(2, n, v, dp);
    
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		Solution obj;
		cout<<obj.count(n)<<endl;
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends