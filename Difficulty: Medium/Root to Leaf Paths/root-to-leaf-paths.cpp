/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  private:
    void preTraversal(Node* curr, vector<int> path, vector<vector<int>>& paths) {
        if (curr == nullptr) return;
        path.push_back(curr -> data);
        // leaf node
        if (curr -> left == nullptr && curr -> right == nullptr) {
            paths.push_back(path);
            return;
        }
        preTraversal(curr -> left, path, paths);
        preTraversal(curr -> right, path, paths);
    }
  public:
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> paths;
        vector<int> path;
        preTraversal(root, path, paths);
        return paths;
    }
};