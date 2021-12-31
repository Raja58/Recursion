// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        31 Dec 2021
//  @Detail  :        Permutations II (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    void getPermu(int idx, vector<int> nums, vector<vector<int>> &result)
    {
        if(idx == nums.size() - 1)
        {
            result.push_back(nums);
            return;
        }
        
        for(int i = idx; i < nums.size(); i++)
        {
            if(i != idx && nums[i] == nums[idx])
                continue;
            swap(nums[i], nums[idx]);
            getPermu(idx + 1, nums, result);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        getPermu(0, nums, result);
        return result;
    }
};
