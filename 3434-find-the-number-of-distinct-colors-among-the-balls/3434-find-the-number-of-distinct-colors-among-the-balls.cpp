class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        unordered_map<int, int> color_freq;  // Frequency of colors
        unordered_map<int, int> ball_color;  // Ball -> Color mapping
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            int ball = queries[i][0];
            int color = queries[i][1];
            
            // Remove a color if the chosen ball is already painted
            if (ball_color.count(ball)) {
                int old_color = ball_color[ball];
                
                // Decrease the frequency of the old color
                color_freq[old_color]--;
                if (color_freq[old_color] == 0)
                    color_freq.erase(old_color);
            }
            
            // Paint the ball with a new color
            ball_color[ball] = color;
            
            // Increase the frequency of the new color
            color_freq[color]++;
            
            // Store the number of distinct colors
            ans[i] = color_freq.size();
        }

        return ans;
    }
};
