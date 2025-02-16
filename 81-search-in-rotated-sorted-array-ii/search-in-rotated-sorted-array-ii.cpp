class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;  // Avoid overflow

            if (nums[mid] == target) return true;

            // Handle duplicates by shifting bounds
            while (low < mid && nums[low] == nums[mid]) low++;
            while (high > mid && nums[high] == nums[mid]) high--;

            // Left half is sorted
            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1; // Search in left half
                } else {
                    low = mid + 1;  // Search in right half
                }
            } 
            // Right half is sorted
            else {
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;  // Search in right half
                } else {
                    high = mid - 1; // Search in left half
                }
            }
        }
        return false; // Target not found
   }
};