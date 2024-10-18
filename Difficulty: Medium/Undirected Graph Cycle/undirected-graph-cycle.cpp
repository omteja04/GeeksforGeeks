//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool detect(int src, int parent, vector<vector<int>> &adj, bool vis[]) {
        vis[src] = true;
        for(auto adjNode : adj[src]) {
            if(!vis[adjNode]) {
                vis[adjNode] = true;
                if(detect(adjNode, src, adj, vis))  return true;
            }
            else if(parent != adjNode) return true;
        }
        return false;
    }
    bool isCycle(vector<vector<int>> adj) {
        // Code here
        int n = adj.size();
        bool vis[n] = {0};
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
               if(detect(i, -1, adj, vis)) return true;
            }
        }
        return false;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends