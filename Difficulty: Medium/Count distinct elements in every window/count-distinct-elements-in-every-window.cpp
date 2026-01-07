class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        vector<int> res;
        unordered_map<int, int> mp;
        int j = 0;
        for(int i = 0; i < n; i++) {
            
            if(i >= k) {
                res.push_back(mp.size());
                mp[arr[j]]--;
                if(mp[arr[j]] == 0) {
                    mp.erase(arr[j]);
                }
                j++;
            }
            mp[arr[i]]++;
            
            
        }
        res.push_back(mp.size());
        return res;
    }
};