class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long totalCount = 0;
        long long currentStreak = 0;

        for (int num : nums) {
            if (num == 0) {
                // If we see a zero, the streak of zeros gets longer.
                currentStreak++;
            } else {
                // If we see a non-zero, the streak is broken and resets.
                currentStreak = 0;
            }
            // Add the number of new subarrays that end at the current position.
            totalCount += currentStreak;
        }
        
        return totalCount;
    }
};