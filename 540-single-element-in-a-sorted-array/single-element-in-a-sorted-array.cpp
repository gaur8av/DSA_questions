class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
       // if(n == 1) return nums[0];
        if((n == 1) or (nums[0] != nums[1])) return nums[0];
        if(nums[n-1] != nums[n-2]) return nums[n-1];

        int low = 1 , high = n - 2;

        while(low <= high){
            int mid = (low + high)/2;

            if((nums[mid-1] != nums[mid]) && (nums[mid+1] != nums[mid])){
                return nums[mid];
            }

            //left elimination condition

            if((mid % 2 == 1 && nums[mid-1] == nums[mid]) or
               (mid % 2 == 0 && nums[mid+1] == nums[mid])){
                low = mid + 1;
               }
            else{
                high = mid - 1;
            }
        } 
        return -1;
    }
};