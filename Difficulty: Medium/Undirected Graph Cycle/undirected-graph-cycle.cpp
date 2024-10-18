//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool detect(int src, vector<vector<int>> &adj, bool vis[]) {
        vis[src] = true;
        queue<pair<int, int>> q;
        q.push({src, -1});
        while(!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto adjNode : adj[node]) {
                if(!vis[adjNode]) {
                    q.push({adjNode, node});
                    vis[adjNode] = true;
                } else if(parent != adjNode) {
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(vector<vector<int>> adj) {
        // Code here
        int n = adj.size();
        bool vis[n] = {0};
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
               if(detect(i, adj, vis)) return true;
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