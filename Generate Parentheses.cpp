// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        12 Nov 2021
//  @Detail  :        Generate Parentheses (LeetCode)
//  ============================
//  -->

class Solution {
public:
    void getAll(int open, int close, int &n, string cur, vector<string> &result)
    {
        if(open == n && close == n)
        {
            result.push_back(cur);
            return;
        }
        if(open < n)
            getAll(open + 1, close, n, cur + '(', result);
        if(close < open)
            getAll(open, close + 1, n, cur + ')', result);
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        getAll(0, 0, n, "", result);
        return result;
    }
};
