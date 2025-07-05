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
 int findMaxPathSum(TreeNode* root, int & maxSum){
    if(root==NULL) return 0;
    
    int leftTreeSum= max(0,findMaxPathSum(root->left,maxSum));
    int rightTreeSum=max(0,findMaxPathSum(root->right,maxSum));

    maxSum= max(maxSum,leftTreeSum+rightTreeSum+root->data);

    return max(leftTreeSum, rightTreeSum) + root->data;

 }

public: 
int maxPathSum(TreeNode* root){
    int maxSum=INT_MIN;
    findMaxPathSum(root,maxSum);
    return maxSum;
}

};
int main(){
    Solution sol;

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Max Path Sum: " << sol.maxPathSum(root) << endl;

    return 0;
}