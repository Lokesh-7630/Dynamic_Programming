class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        std::unordered_map<char, int> counts;
        for (char t : tasks) {
            counts[t]++;
        }

        // Step 2: Push frequencies into Max-Heap
        std::priority_queue<int> maxHeap;
        for (auto& [task, count] : counts) {
            maxHeap.push(count);
        }

        // Queue stores pairs of {remainingCount, availableTime}
        std::queue<std::pair<int, int>> coolDownQueue;
        int time = 0;

        // Step 3: Simulate CPU cycles
        while (!maxHeap.empty() || !coolDownQueue.empty()) {
            time++;

            // 1. Check if any task finished its cooldown
            if (!coolDownQueue.empty() && coolDownQueue.front().second == time) {
                maxHeap.push(coolDownQueue.front().first);
                coolDownQueue.pop();
            }

            // 2. Pick the most frequent task available
            if (!maxHeap.empty()) {
                int count = maxHeap.top() - 1; // Execute task
                maxHeap.pop();

                if (count > 0) {
                    // Task can be executed again at current_time + n + 1
                    coolDownQueue.push({count, time + n + 1});
                }
            }
        }

        return time;
        
    }
};