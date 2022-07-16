class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     * 
     * @param root TreeNode�� 
     * @return bool������
     */
    bool isCompleteTree(TreeNode* root) {
        // write code here
        if(root==NULL)
            return true;
        queue<TreeNode*>q;
        q.push(root);
        bool flag=false;
        while(!q.empty())
        {
           int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode*node=q.front();
                q.pop();
                if(node==NULL)//��ǵ�һ�������սڵ�
                    flag=true;
                else//���������������սڵ㣬˵��������Ҷ�ӣ��������ڷǿսڵ㣬ֱ�ӷ���false
                {
                    if(flag)
                        return false;
                    q.push(node->left);
                    q.push(node->right);
                }
            }
        }
        return true;
    }
};
