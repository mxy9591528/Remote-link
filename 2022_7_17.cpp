class Solution {
public:
    /**
     * 
     * @param root TreeNode�� 
     * @param o1 int���� 
     * @param o2 int���� 
     * @return int����
     */
    int lowestCommonAncestor(TreeNode* root, int o1, int o2) {
        // write code here
        if(root==NULL)
            return -1;
        if(root->val==o1||root->val==o2)//ƥ�䷵��
            return root->val;
        int left=lowestCommonAncestor(root->left, o1, o2),
        right=lowestCommonAncestor(root->right, o1, o2);
        if(left==-1)//�����������
            return right;
        if(right==-1)
            return left;
        return root->val;//���򡤸�Ϊ��ǰ�ڵ�
    }
};
