class Solution {
public:
  
    vector<int> twoSum(vector<int>& numbers, int target) {
        // write code here
        int n=numbers.size();
        vector<int>tmp;
        if(!n)
            return tmp;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(numbers[i]+numbers[j]==target)
                {
                    tmp.push_back(i+1);
                    tmp.push_back(j+1);
                    return tmp;
                }
            }
        }
        return tmp;
    }
};
