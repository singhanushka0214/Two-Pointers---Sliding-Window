class Solution {
public:
    int func(vector<int> &nums, int k){
        if (k < 0) return 0;
        int l = 0, r = 0; 
        int sum = 0;      
        int count = 0;   
        while (r < nums.size()) {
            sum += (nums[r] % 2); 
            while (sum > k) {
                sum -= (nums[l] % 2);  
                l++;            
            }
            count += (r - l + 1);
            r++; 
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return func(nums, k) - func(nums, k-1);
    }
};
