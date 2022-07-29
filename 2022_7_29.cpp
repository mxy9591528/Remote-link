class Solution {
public:
    //��listģ��˫������˫�������������0λΪƵ�ʣ���1λΪkey����2λΪval
    //Ƶ�ʵ�˫������Ĺ�ϣ��
    unordered_map<int, list<vector<int> > > freq_mp; 
    //key��˫������ڵ�Ĺ�ϣ��
    unordered_map<int, list<vector<int> > ::iterator> mp;
    //��¼��ǰ��СƵ��
    int min_freq = 0; 
    //��¼����ʣ������
    int size = 0; 
    
    vector<int> LFU(vector<vector<int> >& operators, int k) {
        //��¼���
        vector<int> res; 
        size = k; 
        //�������в���
        for(int i = 0; i < operators.size(); i++){
            auto op = operators[i];
            if(op[0] == 1)
                //set����
                set(op[1], op[2]);
            else
                //get����
                res.push_back(get(op[1]));
        }
        return res;
    }
    
    //���ú���ʱ����Ƶ�ʻ���valֵ
    void update(list<vector<int> >::iterator iter, int key, int value) { 
        //�ҵ�Ƶ��
        int freq = (*iter)[0];
        //ԭƵ����ɾ���ýڵ�
        freq_mp[freq].erase(iter); 
        //��ϣ���и�Ƶ�����޽ڵ㣬ֱ��ɾ��
        if(freq_mp[freq].empty()){ 
            freq_mp.erase(freq);
            //����ǰƵ��Ϊ��С����СƵ�ʼ�1
            if(min_freq == freq) 
                min_freq++;
        }
        //����Ƶ�ʼ�һ��˫�������ͷ�������ж�Ӧ��freq key value
        freq_mp[freq + 1].push_front({freq + 1, key, value}); 
        mp[key] = freq_mp[freq + 1].begin(); 
    }
    
    //set��������
    void set(int key, int value) {
        //�ڹ�ϣ�����ҵ�keyֵ
        auto it = mp.find(key); 
        if(it != mp.end())
            //���ǹ�ϣ�����У������ֵ��Ƶ��
            update(it->second, key, value);
        else{ 
            //��ϣ����û�У���������û��
            if(size == 0){
                //������ȡƵ������������ɾ��
                int oldkey = freq_mp[min_freq].back()[1]; 
                //Ƶ�ʹ�ϣ����ɾ��
                freq_mp[min_freq].pop_back(); 
                if(freq_mp[min_freq].empty()) 
                    freq_mp.erase(min_freq); 
                //�����ϣ����ɾ��
                mp.erase(oldkey); 
            }
            //���п�����ֱ�Ӽ��룬������1
            else 
                size--; 
            //��СƵ����Ϊ1
            min_freq = 1; 
            //��Ƶ��Ϊ1��˫�������ͷ����ü�
            freq_mp[1].push_front({1, key, value}); 
            //��ϣ��keyֵָ�������и�λ��
            mp[key] = freq_mp[1].begin(); 
        }
    }
    
    //get��������
    int get(int key) {
        int res = -1;
        //���ҹ�ϣ��
        auto it = mp.find(key);
        if(it != mp.end()){ 
            auto iter = it->second; 
            //���ݹ�ϣ��ֱ�ӻ�ȡֵ
            res = (*iter)[2];
            //����Ƶ�� 
            update(iter, key, res); 
        }
        return res;
    }
};


