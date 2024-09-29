class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        int hash[256] = {0};
        int l=0, r=0;
        int minlen = INT_MAX;
        int sidx = -1;
        int cnt = 0;
        for(int i=0; i<m; i++){
            hash[t[i]]++;
        }
        while(r < n){
            if(hash[s[r]] > 0) cnt++;
            hash[s[r]]--;

            while(cnt == m){
                if(r-l+1 < minlen){
                    minlen = r - l + 1;
                    sidx = l;
                }
                hash[s[l]]++;
                if(hash[s[l]] > 0) cnt--;
                l++;
            }
            r = r+1;
        }
        return (sidx == -1) ? "" : s.substr(sidx, minlen);
    }
};
