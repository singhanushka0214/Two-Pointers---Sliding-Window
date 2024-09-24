##Brutre Force Solution
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int cnt = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            unordered_map<int, int> mpp;
            for(int j=i; j<n; j++){
                mpp[nums[j]]++;
                if(mpp.size() == k) cnt++;
                else if(mpp.size() > k) break;
            }
        }
        return cnt;
    }
};
