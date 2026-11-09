class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int q_len = queries.size();
        vector<int> result(q_len);
        
        // Pair queries with their original indices: {queries[i], i}
        vector<pair<int, int>> sorted_queries(q_len);
        for (int i = 0; i < q_len; ++i) {
            sorted_queries[i] = {queries[i], i};
        }
        
        // Sort logs by time: logs[i][1]
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        // Sort queries by query time
        sort(sorted_queries.begin(), sorted_queries.end());
        
        unordered_map<int, int> server_count;
        int unique_servers = 0;
        int left = 0, right = 0;
        int logs_len = logs.size();
        
        for (const auto& [q_time, original_index] : sorted_queries) {
            int start_time = q_time - x;
            int end_time = q_time;
            
            // Expand right boundary: add logs where time <= end_time
            while (right < logs_len && logs[right][1] <= end_time) {
                int server_id = logs[right][0];
                if (server_count[server_id] == 0) {
                    unique_servers++;
                }
                server_count[server_id]++;
                right++;
            }
            
            // Shrink left boundary: remove logs where time < start_time
            while (left < logs_len && logs[left][1] < start_time) {
                int server_id = logs[left][0];
                server_count[server_id]--;
                if (server_count[server_id] == 0) {
                    unique_servers--;
                }
                left++;
            }
            
            // Servers with zero requests = Total servers - Active servers in range
            result[original_index] = n - unique_servers;
        }
        
        return result;
    }
};