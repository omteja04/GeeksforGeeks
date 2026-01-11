/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:
    void rec(map<int, vector<int>> &mp, Node* root, int level){
        if(!root) return;
        mp[level].push_back(root->data);
        rec(mp, root->left, level + 1);
        rec(mp, root->right, level);
    }
    
    vector<int> diagonal(Node *root) {
        // code here
        map<int, vector<int>> mp;
        rec(mp, root, 0);
        vector<int> res;
        for(auto &[_, arr] : mp) {
            res.insert(res.end(), arr.begin(), arr.end());
        }
        return res;
    }
};