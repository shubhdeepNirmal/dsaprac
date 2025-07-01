#include <iostream>
#include <vector>
using namespace std;

 struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
    
class Solution {
    private: 
    void help(TreeNode* root, vector<int>& result) {
        if (root == NULL) return;
        help(root->left, result);
        result.push_back(root->val);
        help(root->right, result);
    }
public: 
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        help(root, result);
        return result;
    }

};

int main(){
    TreeNode* root =new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    Solution sol=Solution();
    vector<int> result = sol.inorderTraversal(root);

    for(int val:result) {
        cout << val << " ";
    }
    cout << endl;
   
    return 0;
}