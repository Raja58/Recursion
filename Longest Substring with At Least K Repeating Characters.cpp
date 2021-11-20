// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        20 Nov 2021
//  @Detail  :        Longest Substring with At Least K Repeating Characters (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    int getMaxLen(int start, int end, int &k, string &str, vector<vector<int>> &dp)
    {
        if(start > end)
            return 0;
        if(dp[start][end] != -1)
            return dp[start][end];
        vector<int> freq(26);
        for(int i = start; i <= end; i++)
            freq[str[i] - 'a']++;
        for(int i = start; i <= end; i++)
            if(freq[str[i] - 'a'] < k)
                return dp[start][end] = max(getMaxLen(start, i - 1, k, str, dp), getMaxLen(i + 1, end, k, str, dp));
        return dp[start][end] = end - start + 1;
    }
    
    int longestSubstring(string str, int k) {
        if(k == 1)
            return str.size();
        vector<vector<int>> dp(str.size() + 1, vector<int>(str.size() + 1, -1));
        return getMaxLen(0, str.size() - 1, k, str, dp);
    }
};
