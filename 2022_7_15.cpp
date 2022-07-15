/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @param sum int整型 
     * @return bool布尔型
     */
    bool hasPathSum(TreeNode* root, int sum) {
        // write code here
        if(root==NULL)
            return false;
        stack<pair<TreeNode*,int>>s;
        s.push({root,root->val});
        while(!s.empty())
        {
            auto tmp=s.top();
            s.pop();
            if(tmp.first->left==NULL&&tmp.first->right==NULL&&tmp.second==sum)
                return true;
            if(tmp.first->left)
                s.push({tmp.first->left,tmp.second+tmp.first->left->val});
            if(tmp.first->right)
                s.push({tmp.first->right,tmp.second+tmp.first->right->val});
        }
        return false;
    }
};
