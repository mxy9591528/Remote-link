class Solution {
public:
    string x = "";
    string y = "";
    //��ȡ�����������
    string ans(int i, int j, vector<vector<int>>& b){ 
        string res = "";
        //�ݹ���ֹ����
        if(i == 0 || j == 0)
            return res;
        //���ݷ�����ǰ�ݹ飬Ȼ����ӱ����ַ�
        if(b[i][j] == 1){
            res += ans(i - 1, j - 1, b);
            res += x[i - 1];
        }
        else if(b[i][j] == 2)
            res += ans(i - 1, j, b);
        else if(b[i][j] == 3)
            res += ans(i,j - 1, b);
        return res;
    }
    string LCS(string s1, string s2) {
        //�������
        if(s1.length() == 0 || s2.length() == 0) 
            return "-1";
        int len1 = s1.length();
        int len2 = s2.length();
        x = s1;
        y = s2;
        //dp[i][j]��ʾ��һ���ַ�������iλ���ڶ����ַ�������jλΪֹ������������г���
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        //��̬�滮������ӵķ���
        vector<vector<int>> b(len1 + 1, vector<int>(len2 + 1, 0));
        //���������ַ���ÿ��λ����������
        for(int i = 1; i <= len1; i++){
            for(int j = 1; j <= len2; j++){
                //���������ַ����
                if(s1[i - 1] == s2[j - 1]){
                    //�����ɶ��߶���ǰһλ
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    //���������Ϸ�
                    b[i][j] = 1;
                }
                //�����������ַ���ͬ
                else{
                    //��ߵ�ѡ����󣬼���һ���ַ�������һλ
                    if(dp[i - 1][j] > dp[i][j - 1]){
                        dp[i][j] = dp[i - 1][j];
                        //��������
                        b[i][j] = 2;
                    }
                    //�ұߵ�ѡ����󣬼��ڶ����ַ�������һλ
                    else{
                        dp[i][j] = dp[i][j - 1];
                        //�������Ϸ�
                        b[i][j] = 3;
                    }
                }
            }
        }
        //��ȡ���ַ���
        string res = ans(len1, len2, b);
        //�����Ƿ�λ��
        return  res != "" ? res : "-1";
    }
};

