class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ds;
        vector<vector<int>> ans;
        helper(0,candidates, ans, ds,target);
        return ans;
    }

    void helper(int index, vector<int>& candidates, vector<vector<int>>& ans, vector<int>& ds, int target){
        if(index==candidates.size()) return;

        if(target==0){
            ans.push_back(ds);
            return;
        }

        if(candidates[index]<=target){
            ds.push_back(candidates[index]);
            helper(index, candidates, ans, ds, target-candidates[index]);
            ds.pop_back();
        }

        helper(index+1, candidates, ans, ds, target);
    }
};