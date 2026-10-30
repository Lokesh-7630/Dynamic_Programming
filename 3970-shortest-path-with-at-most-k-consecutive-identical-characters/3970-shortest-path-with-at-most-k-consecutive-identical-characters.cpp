class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        //adj[i]=pair(u,wt)
        vector<vector<pair<int,int>>>adj(n);
        for(const auto& edge:edges){
            adj[edge[0]].push_back({edge[1],edge[2]});
        }

        const long long INF=1e9;
        vector<vector<long long>>dist(n,vector<long long>(k+1,INF));
        using Element=tuple<long long ,int,int>;
        priority_queue<Element,vector<Element>,greater<Element>>pq;// Base case: starting at node 0 with consecutive count = 1
        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [d, u, count] = pq.top();
            pq.pop();

            // Early exit if destination node is reached
            if (u == n - 1) return d;

            if (d > dist[u][count]) continue;

            for (const auto& [v, weight] : adj[u]) {
                int next_count = (labels[v] == labels[u]) ? count + 1 : 1;

                if (next_count <= k && d + weight < dist[v][next_count]) {
                    dist[v][next_count] = d + weight;
                    pq.push({dist[v][next_count], v, next_count});
                }
            }
        }

        return -1;
    }
};