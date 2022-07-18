class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        int n=pre.size(),m=vin.size();
        if(n==0||m==0)
            return NULL;
        stack<TreeNode*>s;
        TreeNode*root=new TreeNode(pre[0]);//�������ڵ�
        TreeNode*cur=root;
        for(int i=1,j=0;i<n;i++)
        {
            if(cur->val!=vin[j])//�Ա������������ڵ�
            {
                cur->left=new TreeNode(pre[i]);
                s.push(cur);
                cur=cur->left;
            }
            else//�����������ҽڵ�������ҽڵ�
            {
                j++;
                while(!s.empty()&&s.top()->val==vin[j])//���������ϵ�����
                {
                    cur=s.top();
                    s.pop();
                    j++;
                }
                cur->right=new TreeNode(pre[i]);
                cur=cur->right;
            }
        }
        return root;
    }
};
