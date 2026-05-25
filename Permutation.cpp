class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;

        //step 1. find break point
        while(i >= 0 && nums[i] >= nums[i+1]) {
            i--;
        }
        if(i >= 0) {
            int j = n - 1;

            //step 2. find just greater element
            while(nums[j] <= nums[i]) {
                j--;
            }
            swap(nums[i] , nums[j]);
        }
        //step 3. reverse remaining
        reverse(nums.begin() + i + 1, nums.end());
    }
};
