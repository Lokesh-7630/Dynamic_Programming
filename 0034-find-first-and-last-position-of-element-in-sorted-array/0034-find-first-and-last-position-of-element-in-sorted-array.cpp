class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) {
            return {-1, -1};
        }

        // 1. Find the first occurrence (mini)
        int left = 0, right = n - 1;
        int mini = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2; // Recalculate mid inside loop
            
            if (nums[mid] == target) {
                mini = mid;
                right = mid - 1; // Move left to find the first position
            } else if (nums[mid] < target) { // Compare nums[mid] to target
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        // If target was not found at all, early exit
        if (mini == -1) {
            return {-1, -1};
        }

        // 2. Find the last occurrence (maxi)
        left = 0; 
        right = n - 1;
        int maxi = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2; // Recalculate mid inside loop
            
            if (nums[mid] == target) {
                maxi = mid;
                left = mid + 1; // Move right to find the last position
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return {mini, maxi};
           
    }
};