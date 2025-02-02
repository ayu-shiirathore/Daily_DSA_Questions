class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0;  // To count how many "drops" we have (where nums[i] > nums[i+1])

        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1) % n]) {  // Use modulo to wrap around the array
                count++;
            }
        }

        // If there are more than one drop, it's not a rotated sorted array
        return count <= 1;
    }
};
