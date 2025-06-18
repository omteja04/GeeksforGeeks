class Solution {
  public:
    vector<int> topologicalSort(int V, vector<vector<int>> &adj) {
    vector<int> inDegree(V, 0);
    for(int i = 0; i < V; i++) {
        for(auto &neighbour: adj[i]) {
            inDegree[neighbour]++;
        }
    }
    queue<int> q;
    for(int i = 0; i < V; i++) {
        if(inDegree[i] == 0) {
            q.push(i);
        }
    }
    vector<int> res;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        res.push_back(node);
        for(auto &neighbour: adj[node]) {
            if(--inDegree[neighbour] == 0) {
                q.push(neighbour);
            }
        }
    }
    return (res.size() == V) ? res : vector<int> {};
}
string findOrder(vector<string> &words) {
    vector<bool> letters(26, false);
    for(auto &word: words) {
        for(auto &ch: word) {
            letters[ch - 'a'] = 1;
        }
    }
    vector<vector<int>> adj(26);
    for(int i = 0; i < words.size() - 1; i++) {
        string a = words[i];
        string b = words[i + 1];
        int len = min(a.length(), b.length());
        bool found = false;
        for(int i = 0; i < len; i++) {
            if(a[i] != b[i]) {
                adj[a[i] - 'a'].push_back(b[i] - 'a');
                found = true;
                break;
            }
        }
        if(!found && (a.size() > b.size())) {
            return "";
        }
    }

    vector<int> res = topologicalSort(26, adj);
    if(res.empty()) {
        return "";
    }
    string ans = "";
    for(auto &it: res) {
        if(letters[it]) {
            ans += (char) (it + 'a');
        }
    }
    return ans;
}
};