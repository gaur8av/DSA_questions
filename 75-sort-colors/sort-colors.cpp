class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt1 = 0;
        int cnt2 = 0;
        int cnt3 = 0;

        for(int n : nums){
            if (n == 0) cnt1++;
            else if ( n ==1 ) cnt2++;
            else cnt3++;
        }

        for(int i = 0; i<cnt1; i++){
            nums[i] = 0;
        }
        for(int i = cnt1; i<(cnt1+cnt2); i++){
            nums[i] = 1;
        }
        for(int i = (cnt1+cnt2); i<nums.size(); i++){
            nums[i] = 2;
        }
    }
};