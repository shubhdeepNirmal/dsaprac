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
    int findHeight(TreeNode* root,int &currentDiameter){
        if(root==NULL) return 0;
        int leftTreeHeight(findHeight(root->left,currentDiameter));
        int rightTreeHeight=findHeight(root->right,currentDiameter);
        currentDiameter=max(currentDiameter,leftTreeHeight+rightTreeHeight);
        return 1+max(leftTreeHeight,rightTreeHeight);
    }
public: 
int diameterOfBinaryTree(TreeNode* root){
     int currentDiameter=0;
     findHeight(root,currentDiameter);
     return currentDiameter;
}
};
int main(){
    Solution sol;
     TreeNode* root = new TreeNode(1);
     root->left = new TreeNode(2);
     root->right = new TreeNode(3);
     root->left->left = new TreeNode(4);
     root->left->right = new TreeNode(5);
     cout << sol.diameterOfBinaryTree(root) << endl; // Output: 3
    return 0;
}