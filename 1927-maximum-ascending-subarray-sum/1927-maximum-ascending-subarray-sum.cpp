class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        
        int sum = nums[0];  
        int maxSum = sum;
        
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                sum += nums[i]; 
            } else {
                maxSum = max(maxSum, sum);  
                sum = nums[i];  // Reset sum to current element
            }
        }
        
        return max(maxSum, sum); 
    }
};
