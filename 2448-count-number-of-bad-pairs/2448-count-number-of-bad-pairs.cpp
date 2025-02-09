class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
      int n = nums.size();
        long long goodPairs = 0;
        unordered_map<int, int> hashMap; // stores diff->count
        // pair (i, j) is a bad pair if i < j and j - i != nums[j] - nums[i]
        // rephrame: nums[i] - i != nums[j] - j
        for (int i = 0; i < n; i++) {
            int diff = nums[i] - i;
            goodPairs +=
                hashMap[diff]; // when both diff[i]==diff[j] then good pair
            hashMap[diff]++;
        }
        long long totalPairs =  ((1LL *n * (n - 1)) / 2);
        long long badPairs = 1LL * (totalPairs - goodPairs);
        return badPairs;  
    }
};