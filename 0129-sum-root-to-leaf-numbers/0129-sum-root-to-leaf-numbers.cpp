/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
void find(TreeNode* root,string& temp,int& sum)
{
    if(root==NULL) return;
    if(root->right==NULL && root->left==NULL) 
    {
        temp=temp+ to_string(root->val);
        sum+=stoi(temp);
        temp.pop_back();
        return;
    }
    temp=temp+ to_string(root->val);
    find(root->left,temp,sum);
    find(root->right,temp,sum);
    temp.pop_back();
}
    int sumNumbers(TreeNode* root) {
        if(root==NULL) return 0;
        if(root->right==NULL && root->left==NULL) return root->val;
        int sum=0;
        string temp="";
      find(root,temp,sum);
        
       return sum;
    }
};