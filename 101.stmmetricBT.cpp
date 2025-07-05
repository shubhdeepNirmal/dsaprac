#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
};
class Solution {

    private:
    bool isTreeSymmetric(TreeNode* left, TreeNode* right){
        if( left==NULL&&right==NULL) return true;
        if(left==NULL||right==NULL) return false;
        if(left->data!=right->data) return false;
        return isTreeSymmetric(left->left,right->right)&&isTreeSymmetric(left->right,right->left);
    }
public: 
bool isSymmetric(TreeNode* root){
    if(root==NULL) return true;
    return isTreeSymmetric(root->left,root->right);
}
  
};
int main(){
    Solution sol;

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(4);

    cout<< "Is the tree symmetric? " << (sol.isSymmetric(root)?"Yes":"No") << endl;

    return 0;
}