#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
private:
    void dfs(int i, unordered_map<int, vector<int>>& adj, unordered_map<int, bool>& vis) {
        vis[i] = true;  // Mark the current node as visited
        for (auto it : adj[i]) {  // Iterate over all the adjacent nodes
            if (!vis[it]) {  // If the adjacent node is not visited
                dfs(it, adj, vis);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        
        // Create an adjacency list using unordered_map
        unordered_map<int, vector<int>> adj;
        
        // Build the adjacency list
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);  // Undirected graph
                }
            }
        }

        // Visited map to keep track of visited nodes
        unordered_map<int, bool> vis;
        int count = 0;

        // Traverse all nodes, and perform DFS on unvisited nodes
        for (int i = 0; i < V; i++) {
            if (vis.find(i) == vis.end() || !vis[i]) {
                count++;
                dfs(i, adj, vis);
            }
        }

        return count;
    }
};
