/***
5264. Find Elements in a Contaminated Binary Tree
***/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 void dfs(TreeNode* root, int value, unordered_set<int>& valSet){
    root->val = value;
    valSet.insert(value);
    if (root->left != NULL){
        dfs(root->left, 2*value + 1, valSet);
    }
    if (root->right != NULL){
        dfs(root->right, 2*value + 2, valSet);
    }
 }
class FindElements {
public:
    unordered_set<int> valSet;
    FindElements(TreeNode* root) {
        dfs(root, 0, valSet);
    }
    
    bool find(int target) {
        if (valSet.count(target) != 0) return true;
        else return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
