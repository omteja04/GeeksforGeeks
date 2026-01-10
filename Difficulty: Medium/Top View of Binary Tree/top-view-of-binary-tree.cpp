/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
        vector<int> res;
        if(!root) return res;
        map<int, int> topNodes;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while(!q.empty()) {
            auto [node, dist] = q.front();
            q.pop();
            if(topNodes.find(dist) == topNodes.end()) {
                topNodes[dist] = node->data;
            }
            if(node->left) {
                q.push({node->left, dist - 1});
            }
            if(node->right) {
                q.push({node->right, dist + 1});
            }
        }
        for (auto it : topNodes) {
            res.push_back(it.second);
        }

        return res;
    }
};