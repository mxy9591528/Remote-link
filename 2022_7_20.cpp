class Solution {
public:
    #define transfer static_cast<double>
    vector<int>data;
    void Insert(int num) {
        if(data.empty())
            data.push_back(num);
        else{
            auto it=lower_bound(data.begin(),data.end(),num);
            data.insert(it,num);
        }
    }

    double GetMedian() { 
        int n=data.size();
        if(n&1)
            return transfer(data[n>>1]);
        else
            return transfer(data[n>>1]+data[(n-1)>>1])/2;
    }

};
