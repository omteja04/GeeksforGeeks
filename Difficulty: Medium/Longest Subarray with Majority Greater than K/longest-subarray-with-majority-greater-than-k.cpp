class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        // Code here
        unordered_map<int, int> mp;
        mp[0] = -1;
        int n = arr.size();
        int maxLen = 0;
        int pref = 0;
        for(int i = 0; i  < n; i++) {
            if(arr[i] > k) {
                pref += 1;
            } else {
                pref -= 1;
            }
            if(pref > 0) {
                maxLen = i + 1;
            }
            if(mp.count(pref - 1)) {
                maxLen = max(maxLen, i - mp[pref-1]);
            }
            if(!mp.count(pref)) {
                mp[pref] = i;
            }
        }
        return maxLen;
        
        
    }
};