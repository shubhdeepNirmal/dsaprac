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
public:
int maxDepth(TreeNode* root){
    if(root==NULL) return 0;
    int leftDepth=maxDepth(root->left);
    int rightDepth=maxDepth(root->right);
    return 1+max(leftDepth, rightDepth);
}
    
};
int main(){
    Solution sol;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    cout << "Maximum depth of the binary tree: " << sol.maxDepth(root) << endl;
    return 0;
}
