class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param root TreeNode类 
     * @return bool布尔型
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
                if(node==NULL)//标记第一次遇到空节点
                    flag=true;
                else//后续访问已遇到空节点，说明经过了叶子，若还存在非空节点，直接返回false
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
