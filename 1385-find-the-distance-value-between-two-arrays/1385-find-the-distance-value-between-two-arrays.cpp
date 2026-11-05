class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        std::sort(arr2.begin(), arr2.end());
        int distanceValue = 0;

        for (int x : arr1) {
            // Find the first element in arr2 >= x - d
            auto it = std::lower_bound(arr2.begin(), arr2.end(), x - d);
            
            // If no element in arr2 is >= x - d, or the smallest such element is > x + d,
            // then no element in arr2 satisfies |x - arr2[j]| <= d
            if (it == arr2.end() || *it > x + d) {
                distanceValue++;
            }
        }

        return distanceValue;
    }
};