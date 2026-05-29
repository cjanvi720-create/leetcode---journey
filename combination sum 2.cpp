class Solution {
public:
    vector<vector<int>> result;
    void backtrack(int start, int target, vector<int>& candidates, vector<int>& curr) {

        if(target == 0) {
            result.push_back(curr);
            return;
        }
        for(int i = start; i < candidates.size(); i++) {
            //skip duplicates
            if(i > start && candidates[i] == candidates[i-1]) continue;

            //pruning
            if(candidates[i] > target) break;

            curr.push_back(candidates[i]);

            //move to next element ; element reuse nhi hoga
            backtrack(i+1, target - candidates[i], candidates, curr);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(), candidates.end());

        vector<int> curr;
        backtrack(0, target, candidates, curr);

        return result;
    }
};
