#include <vector>
#include <queue>
#include <climits>
#include <iostream>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Build adjacency list: graph[node] = list of {neighbor, time}
        vector<vector<pair<int, int>>> graph(n + 1);
        for (auto& time : times) {
            int u = time[0], v = time[1], w = time[2];
            graph[u].push_back({v, w});
        }
        
        // Dijkstra's algorithm: min-heap priority queue {time, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        // Distance array: dist[i] = minimum time to reach node i from k
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        pq.push({0, k});
        
        while (!pq.empty()) {
            auto [currentTime, currentNode] = pq.top();
            pq.pop();
            
            // If we found a better path already, skip processing
            if (currentTime > dist[currentNode]) {
                continue;
            }
            
            // Explore all neighbors
            for (auto& [neighbor, time] : graph[currentNode]) {
                int newTime = currentTime + time;
                
                // If we found a shorter path to the neighbor
                if (newTime < dist[neighbor]) {
                    dist[neighbor] = newTime;
                    pq.push({newTime, neighbor});
                }
            }
        }
        
        // Find the maximum time among all shortest paths
        int maxTime = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) {
                return -1; // Some node is unreachable
            }
            maxTime = max(maxTime, dist[i]);
        }
        
        return maxTime;
    }
};