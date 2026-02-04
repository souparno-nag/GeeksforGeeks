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
    void leftMostTraversal(Node* node, int level, vector<int>& result) {
        if (node == NULL) return;
        if (result.size() == level) result.push_back(node -> data);
        if (node -> left) leftMostTraversal(node -> left, level+1, result);
        if (node -> right) leftMostTraversal(node -> right, level+1, result);
        return;
    }
    vector<int> leftView(Node *root) {
        // code here
        vector<int> result;
        if (root == NULL) return result;
        leftMostTraversal(root, 0, result);
        return result;
    }
};