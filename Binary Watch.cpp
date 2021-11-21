// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        21 Nov 2021
//  @Detail  :        Binary Watch (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    void getTime(int idx, int hour, int min, int cnt, int &x, vector<string> &result)
    {
        if(cnt == x)
        {
            string temp = to_string(hour) + ':' + (min < 10 ? '0' + to_string(min) : to_string(min));
            result.push_back(temp);
            return;
        }
        
        if(idx == 10)
            return;
        
        if(idx < 4)
        {
            if((hour | (1 << idx)) < 12)
                getTime(idx + 1, hour | (1 << idx), min, cnt + 1, x, result);
            getTime(idx + 1, hour, min, cnt, x, result);
        }
        else
        {
            int minIdx = idx - 4;
            if((min | (1 << minIdx)) < 60)
                getTime(idx + 1, hour, min | (1 << minIdx), cnt + 1, x, result);
            getTime(idx + 1, hour, min, cnt, x, result);
        }
    }
    
    vector<string> readBinaryWatch(int x) {
        int hour = 0, min = 0, cnt = 0;
        vector<string> result;
        getTime(0, hour, min, cnt, x, result);
        return result;
    }
};
