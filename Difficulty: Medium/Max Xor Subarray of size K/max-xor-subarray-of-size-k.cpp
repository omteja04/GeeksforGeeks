class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        // code here
        int ans = 0;
        int maxXor = 0;
        int i = 0;
        for(int j = 0; j < arr.size(); j++) {
            if(j >= k) {
                ans = max(ans, maxXor);
                maxXor ^= arr[i++];
            }
            maxXor ^= arr[j];
            
        }
        ans = max(ans, maxXor);
        return ans;
    }
};