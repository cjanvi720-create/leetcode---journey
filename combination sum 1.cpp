class Solution {
public:
    void solve(int index, vector<int>& candidates, int target, vector <int>& temp, vector<vector<int>>& ans) {
        //base case
        if(target == 0) {
            ans.push_back(temp);
            return;
        }
        if(index >= candidates.size() || target < 0) {
            return;
        }
        //include current element
        temp.push_back(candidates[index]);
        solve(index, candidates, target - candidates[index], temp, ans);

        //backtrack
        temp.pop_back();

        //exclude current element
        solve(index + 1, candidates, target, temp, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;

        solve(0, candidates, target, temp, ans);
        return ans;
    }
};
