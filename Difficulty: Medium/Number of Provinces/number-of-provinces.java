//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            int V = Integer.parseInt(read.readLine());
            
            ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
            
            for(int i=0; i<V; i++)
            {
                String S[] = read.readLine().split(" ");
                ArrayList<Integer> temp = new ArrayList<>();
                for(int j=0; j<V; j++)
                    temp.add(Integer.parseInt(S[j]));
                adj.add(temp);
            }

            Solution ob = new Solution();
            System.out.println(ob.numProvinces(adj,V));
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution {
     public static void rec(int node, ArrayList<ArrayList<Integer>> adj, boolean vis[]) {
        // dfs.add(node);
        vis[node] = true;
        for(Integer num : adj.get(node)) {
            if(!vis[num]) {
                rec(num, adj, vis);
            }
        }
    }
    static int numProvinces(ArrayList<ArrayList<Integer>> adj, int V) {
        // code here
        int cnt = 0;
        ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
        int n = adj.size();
        for(int i = 0; i < n; i ++) {
            graph.add(new ArrayList<>());
        }
        for(int i = 0 ; i < n; i++) {
            for(int j = 0;  j < n; j++) {
                if(i == j) continue;
                if(adj.get(i).get(j) == 1) {
                    graph.get(i).add(j);
                    graph.get(j).add(i);
                }
            }
        }
        boolean[] vis = new boolean[n];
        for(int i = 0 ; i < n; i ++) {
            if(vis[i] == false) {
                cnt++;
                rec(i, graph, vis);
            }
        }
        return cnt;
    }
};