// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        31 Dec 2021
//  @Detail  :        Subsets II (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    void getAllSubSet(int idx, vector<int> temp, vector<int> &nums, vector<vector<int>> &result)
    {
        result.push_back(temp);
        for(int i = idx; i < nums.size(); i++)
        {
            if(i != idx && nums[i] == nums[i - 1])
                continue;
            temp.push_back(nums[i]);
            getAllSubSet(i + 1, temp, nums, result);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> temp;
        getAllSubSet(0, temp, nums, result);
        return result;
    }
};
