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
vector<vector<int>> levelOrder(TreeNode* root){
    vector<vector<int>> ans;
    if(root==NULL) return ans;
    vector<int> currentLevel;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int currentLSize=q.size();
        for(int i=0;i<currentLSize;i++){
            TreeNode* currentNode=q.front();
            q.pop();
            if(currentNode->left!=NULL)q.push(currentNode->left);
            if(currentNode->right!=NULL)q.push(currentNode->right);
            currentLevel.push_back(currentNode->val);
        }
        ans.push_back(currentLevel);
        currentLevel.clear();
    }
    return ans;
}

};
int main(){
    Solution sol;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3); 
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<vector<int>> result = sol.levelOrder(root);
    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}