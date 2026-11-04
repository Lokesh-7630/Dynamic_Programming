class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if (arr.empty()) return {};

        // 1. Create a copy of the original array and sort it
        std::vector<int> sortedArr = arr;
        std::sort(sortedArr.begin(), sortedArr.end());

        // 2. Map unique elements to their ranks
        std::unordered_map<int, int> rankMap;
        int rank = 1;

        for (int num : sortedArr) {
            // Assign rank only if the element is seen for the first time
            if (rankMap.find(num) == rankMap.end()) {
                rankMap[num] = rank++;
            }
        }

        // 3. Replace each original element with its rank
        std::vector<int> result(arr.size());
        for (int i = 0; i < arr.size(); ++i) {
            result[i] = rankMap[arr[i]];
        }

        return result;
    }
};