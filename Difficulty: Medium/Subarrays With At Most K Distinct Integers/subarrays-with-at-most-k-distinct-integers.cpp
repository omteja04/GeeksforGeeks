class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        // code here
        int left = 0;
        int ans = 0;
        unordered_map<int, int> mp;
        for(int right = 0; right < arr.size(); right++) {
            mp[arr[right]]++;
            while(mp.size() > k) {
                mp[arr[left]]--;
                if(mp[arr[left]] == 0) {
                    mp.erase(arr[left]);
                }
                left++;
            }
            ans += (right - left + 1);
        }
        return ans;
    }
};