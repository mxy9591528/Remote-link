class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @param o1 int整型 
     * @param o2 int整型 
     * @return int整型
     */
    int lowestCommonAncestor(TreeNode* root, int o1, int o2) {
        // write code here
        if(root==NULL)
            return -1;
        if(root->val==o1||root->val==o2)//匹配返回
            return root->val;
        int left=lowestCommonAncestor(root->left, o1, o2),
        right=lowestCommonAncestor(root->right, o1, o2);
        if(left==-1)//不在左就在右
            return right;
        if(right==-1)
            return left;
        return root->val;//否则·根为当前节点
    }
};
