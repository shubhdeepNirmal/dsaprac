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
 bool isSameTree(TreeNode* p,TreeNode* q){
    if(p==NULL&&q==NULL) return true;
    if(p==NULL||q==NULL) return false;
    if(p->val!=q->val) return false;
    return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
 }
};
int main(){
    Solution sol;
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);

    cout << sol.isSameTree(root1, root2) << endl;

   return 0;
}
 