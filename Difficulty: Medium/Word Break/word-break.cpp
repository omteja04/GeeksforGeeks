//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

struct Node {
    
    Node *links[26] = {nullptr};
    bool flag = false;
    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }
    void put(char ch, Node *node) {
        links[ch - 'a'] = node;
    }
    Node *get(char ch) {
        return links[ch - 'a'];
    }
    void setEnd() {
        flag = true;
    }
    bool isEnd() {
        return flag;
    }
};
class Trie {
private:
    Node *root;

public:
    Trie() {
        root = new Node();
    }
    void insert(string &word) {
        Node *node = root;
        for (char &ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }
    bool search(string &word, int start, int end) {
        Node *node = root;
        for (int i = start; i < end; i++) {
            if (!node->containsKey(word[i])) {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }
    
};
class Solution {
  public:
    bool wordBreak(string &s, vector<string> &dictionary) {
        // code here
        // Trie trie;
        set<string> st;
        int maxLen = 0;
        for (auto &word : dictionary) {
            st.insert(word);
            maxLen = max(maxLen, (int)word.size());
        }
        int n = s.size();
        vector<bool>dp(n + 1, false);
        dp[0] = true;
        for(int i = 1; i <= n; i++) {
            for(int j  = i - 1; j >= max(0, i - maxLen); j--) {
                if (dp[j] && st.find(s.substr(j, i - j)) != st.end()) {
                    dp[i] = true;
                    break; 
                }
            }
        }
        return dp[n];
        
    }
};


//{ Driver Code Starts.

vector<string> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    vector<string> res;
    while (ss >> str) {
        res.push_back(str);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        cin >> s;
        cin.ignore();
        vector<string> dictionary = inputLine();

        Solution ob;
        if (ob.wordBreak(s, dictionary)) {
            cout << "true\n";
        } else
            cout << "false\n";
        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends