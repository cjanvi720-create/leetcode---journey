class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(0, nums, curr, ans);
        return ans;
    }
    void backtrack(int i, vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans) {
        if (i == nums.size()) {
            ans.push_back(curr);
            return;
        }
        // include nums[i]
        curr.push_back(nums[i]);
        backtrack(i + 1, nums, curr, ans);

        curr.pop_back();
        backtrack(i + 1, nums, curr, ans);
    }
};
