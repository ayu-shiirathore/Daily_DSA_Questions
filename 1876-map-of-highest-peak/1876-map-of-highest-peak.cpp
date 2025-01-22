class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        
        // Create a height matrix initialized with -1 (unvisited)
        vector<vector<int>> height(m, vector<int>(n, -1));
        
        // Queue for BFS
        queue<pair<int, int>> q;
        
        // Initialize the BFS with all water cells (height = 0)
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isWater[i][j] == 1) {
                    height[i][j] = 0; // Water cells have height 0
                    q.push({i, j}); // Add water cells to the BFS queue
                }
            }
        }
        
        // Directions for 4 neighbors (up, down, left, right)
        vector<int> dirs = {-1, 0, 1, 0, -1}; // Using pair of directions
        
        // Perform BFS to fill in the heights
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            
            // Explore all four neighbors
            for (int i = 0; i < 4; ++i) {
                int newX = x + dirs[i];
                int newY = y + dirs[i + 1];
                
                // Check if the new coordinates are within bounds and unvisited
                if (newX >= 0 && newX < m && newY >= 0 && newY < n && height[newX][newY] == -1) {
                    height[newX][newY] = height[x][y] + 1; // Set the height
                    q.push({newX, newY}); // Add to the queue for further exploration
                }
            }
        }
        
        return height;
    }
};