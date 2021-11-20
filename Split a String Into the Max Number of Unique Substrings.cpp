// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        20 Nov 2021
//  @Detail  :        Split a String Into the Max Number of Unique Substrings (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    int getUniqueCnt(int idx, string &str, unordered_set<string> cache)
    {
        if(idx == str.size())
            return 0;
        
        int result = 0;
        for(int i = idx; i < str.size(); i++)
        {
            string x = str.substr(idx, i - idx + 1);
            if(cache.find(x) != cache.end())
                continue;
            cache.insert(x);
            int cnt = 1 + getUniqueCnt(i + 1, str, cache);
            if(cnt > result)
                result = cnt;
            cache.erase(x);
        }
        return result;
    }
    
    int maxUniqueSplit(string str) {
        unordered_set<string> cache;
        return getUniqueCnt(0, str, cache);
    }
};
