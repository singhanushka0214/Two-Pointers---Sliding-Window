class Solution {
public:
    int kDistinctChar(string& s, int k) {
        int n = s.size();  
        int maxLen = 0;  
        unordered_map<char, int> mpp;
        int l = 0, r = 0;
        
        while(r < n){
            mpp[s[r]]++;
            while(mpp.size() > k){
                mpp[s[l]]--;
                if(mpp[s[l]] == 0){
                    mpp.erase(s[l]);
                }
                l++;
            }
            if(mpp.size() <= k){
                maxLen = max(maxLen, r - l + 1);
            }
            
            r++;
        }
        return maxLen;
    }
};
