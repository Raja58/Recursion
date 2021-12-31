// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        31 Dec 2021
//  @Detail  :        Combination Sum II (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    void getAllCombi(int idx, int target, vector<int> temp, vector<int> &nums, vector<vector<int>> &result)
    {
        if(target == 0)
        {
            result.push_back(temp);
            return;
        }
        if(idx == nums.size())
            return;
        
        for(int i = idx; i < nums.size(); i++)
        {
            if(i != idx && nums[i] == nums[i - 1] || target - nums[i] < 0)
                continue;
            temp.push_back(nums[i]);
            getAllCombi(i + 1, target - nums[i], temp, nums, result);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> temp;
        getAllCombi(0, target, temp, nums, result);
        return result;
    }
};
