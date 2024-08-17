//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    
    int tabulation(int n,int x,int y, int z) {
        int dp[10001];
        memset(dp,-1,sizeof(dp));
        dp[0] = 0;
        for(int i = 1; i <= n; i ++) {
            if(i - x >= 0 && dp[i -x] != -1) {
                dp[i] =  max(dp[i], dp[i-x] + 1);
            }
            if(i - y >= 0 && dp[i - y] != -1) {
                dp[i] =   max(dp[i], dp[i-y] + 1);
            }
            if(i - z >= 0 && dp[ i-z] != -1) {
                dp[i] =  max(dp[i], dp[i-z]  + 1);
            }
        }
        return dp[n];
    }
    
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        // memset(dp,INT_MIN, sizeof(dp));
        
        int ans = tabulation(n,x,y,z);
        
        if(ans < 0) return 0;
        return ans;
        
    }
    
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends