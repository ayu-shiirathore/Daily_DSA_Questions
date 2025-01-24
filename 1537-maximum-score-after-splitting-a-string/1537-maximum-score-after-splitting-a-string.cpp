class Solution {
public:
    int maxScore(string s) {
        int ones = 0, zeros = 0, max_score = 0;

        // Count the total number of 1's in the string
        for (char c : s) {
            if (c == '1') ones++;
        }

        // Traverse the string and compute the score for each split
        int left_zeros = 0, right_ones = ones;
        
        for (int i = 0; i < s.size() - 1; i++) { // we exclude the last character as right part must be non-empty
            if (s[i] == '0') {
                left_zeros++;
            } else {
                right_ones--;
            }

            // Calculate the score for this split (left_zeros + right_ones)
            max_score = max(max_score, left_zeros + right_ones);
        }

        return max_score;
   
    }
};