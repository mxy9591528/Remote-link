class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        int n=pre.size(),m=vin.size();
        if(n==0||m==0)
            return NULL;
        stack<TreeNode*>s;
        TreeNode*root=new TreeNode(pre[0]);//建立根节点
        TreeNode*cur=root;
        for(int i=1,j=0;i<n;i++)
        {
            if(cur->val!=vin[j])//旁边这个是他的左节点
            {
                cur->left=new TreeNode(pre[i]);
                s.push(cur);
                cur=cur->left;
            }
            else//否则是他的右节点或祖先右节点
            {
                j++;
                while(!s.empty()&&s.top()->val==vin[j])//弹出到符合的祖先
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
