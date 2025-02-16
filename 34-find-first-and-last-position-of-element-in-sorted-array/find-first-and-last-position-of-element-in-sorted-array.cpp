class Solution {
public:

    int lasttoccurrence(vector<int>& nums , int target , int size){
        int low = 0 , high = size - 1;
        int second = -1;

        while(low <= high){
            int mid = (low + high) / 2;

            if(nums[mid] == target){
                second = mid ;
                low = mid + 1;
            }
            else if(nums[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return second;
    }

    int firstoccurrence(vector<int>& nums , int target , int size){
        int low = 0 , high = size - 1;
        int first = -1;

        while(low <= high){
            int mid = (low + high) / 2;

            if(nums[mid] == target){
                first = mid ;
                 high = mid - 1;
            }
            else if(nums[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return first;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
         int n = nums.size();
         int first = firstoccurrence(nums , target , n);
         int last = lasttoccurrence(nums , target , n);

         return {first , last};
    }
};