class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        if (n == 0 || n == 1) {
            return true;
        }
        
        for (int i = 1; i < n; i++) {
            // Check if one is even and the other is odd
            if (!((nums[i] % 2 == 0 && nums[i - 1] % 2 != 0) || (nums[i] % 2 != 0 && nums[i - 1] % 2 == 0))) {
                return false;
            }
        }
        return true;
    }
};
