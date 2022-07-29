class Solution {
public:
    //用list模拟双向链表，双向链表中数组第0位为频率，第1位为key，第2位为val
    //频率到双向链表的哈希表
    unordered_map<int, list<vector<int> > > freq_mp; 
    //key到双向链表节点的哈希表
    unordered_map<int, list<vector<int> > ::iterator> mp;
    //记录当前最小频次
    int min_freq = 0; 
    //记录缓存剩余容量
    int size = 0; 
    
    vector<int> LFU(vector<vector<int> >& operators, int k) {
        //记录输出
        vector<int> res; 
        size = k; 
        //遍历所有操作
        for(int i = 0; i < operators.size(); i++){
            auto op = operators[i];
            if(op[0] == 1)
                //set操作
                set(op[1], op[2]);
            else
                //get操作
                res.push_back(get(op[1]));
        }
        return res;
    }
    
    //调用函数时更新频率或者val值
    void update(list<vector<int> >::iterator iter, int key, int value) { 
        //找到频率
        int freq = (*iter)[0];
        //原频率中删除该节点
        freq_mp[freq].erase(iter); 
        //哈希表中该频率已无节点，直接删除
        if(freq_mp[freq].empty()){ 
            freq_mp.erase(freq);
            //若当前频率为最小，最小频率加1
            if(min_freq == freq) 
                min_freq++;
        }
        //插入频率加一的双向链表表头，链表中对应：freq key value
        freq_mp[freq + 1].push_front({freq + 1, key, value}); 
        mp[key] = freq_mp[freq + 1].begin(); 
    }
    
    //set操作函数
    void set(int key, int value) {
        //在哈希表中找到key值
        auto it = mp.find(key); 
        if(it != mp.end())
            //若是哈希表中有，则更新值与频率
            update(it->second, key, value);
        else{ 
            //哈希表中没有，即链表中没有
            if(size == 0){
                //满容量取频率最低且最早的删掉
                int oldkey = freq_mp[min_freq].back()[1]; 
                //频率哈希表中删除
                freq_mp[min_freq].pop_back(); 
                if(freq_mp[min_freq].empty()) 
                    freq_mp.erase(min_freq); 
                //链表哈希表中删除
                mp.erase(oldkey); 
            }
            //若有空闲则直接加入，容量减1
            else 
                size--; 
            //最小频率置为1
            min_freq = 1; 
            //在频率为1的双向链表表头插入该键
            freq_mp[1].push_front({1, key, value}); 
            //哈希表key值指向链表中该位置
            mp[key] = freq_mp[1].begin(); 
        }
    }
    
    //get操作函数
    int get(int key) {
        int res = -1;
        //查找哈希表
        auto it = mp.find(key);
        if(it != mp.end()){ 
            auto iter = it->second; 
            //根据哈希表直接获取值
            res = (*iter)[2];
            //更新频率 
            update(iter, key, res); 
        }
        return res;
    }
};


