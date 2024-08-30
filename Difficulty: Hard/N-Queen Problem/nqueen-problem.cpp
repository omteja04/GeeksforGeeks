//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool canPlace(int row, int col, vector<int> &s) {
        for(int i = 0 ; i < row;i++) {
            int prevRow = i;
            int prevCol = s[i];
            if(prevCol == col || abs(row - prevRow) == abs(col - prevCol)) {
                return 0;
            }
        }
        return 1;
    }
    void leviRecursion(int level, int n, vector<int> &s, vector<vector<int>> & ans) {
        if(level == n) {
            vector<int>temp = s;
            for(int i = 0; i < n; i++) temp[i]++;
            ans.push_back(temp);
            return;
        }
        for(int col = 0; col < n; col ++) {
            if(canPlace(level, col, s)) {
                s[level] = col;
                leviRecursion(level + 1, n, s, ans);
                s[level] = -1;
            }
        }

    }

    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>>ans;
        vector<int> s(n, -1);
        leviRecursion(0,n,s,ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends