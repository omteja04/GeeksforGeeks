/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> postOrder(Node* root) {
        // code here
        vector<int>traverse;
        if(root!=NULL) {
            vector<int>left=postOrder(root->left); 
            vector<int>right=postOrder(root->right);
            traverse.insert(traverse.end(),left.begin(),left.end());
            traverse.insert(traverse.end(),right.begin(),right.end());
            traverse.push_back(root->data);
        }
        return traverse;
    }
};