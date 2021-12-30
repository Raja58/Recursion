// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        30 Dec 2021
//  @Detail  :        Numbers With Same Consecutive Differences (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    void getNum(int cur, int idx, int &n, int &k, vector<int> &result)
    {
        int lastDig = cur % 10;
        if(lastDig + k < 10)
        {
            if(idx == n - 1)
                result.push_back(cur * 10 + lastDig + k);
            else
                getNum(cur * 10 + lastDig + k, idx + 1, n, k, result);
        }
        
        if(k != 0 && lastDig - k >= 0)
        {
            if(idx == n - 1)
                result.push_back(cur * 10 + lastDig - k);
            else
                getNum(cur * 10 + lastDig - k, idx + 1, n, k, result);
        }
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> result;
        for(int i = 1; i <= 9; i++)
            getNum(i, 1, n, k, result);
        return result;
    }
};
