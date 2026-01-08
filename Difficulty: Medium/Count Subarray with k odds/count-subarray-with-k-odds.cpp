class Solution {
  public:
    int atMax(vector<int>& arr, int k) {
        int oddCnt = 0;
        int left = 0;
        int n = arr.size();
        int ans = 0;
        for(int right = 0; right < n; right++) {
            if(arr[right] % 2 != 0) {
                oddCnt++;
            }
            while(oddCnt > k) {
                if(arr[left] % 2 != 0) {
                    oddCnt--;
                }
                left++;
            }
            ans += (right - left + 1);
        }
        return ans;
    }
    int countSubarrays(vector<int>& arr, int k) {
        // code here
        return atMax(arr, k) - atMax(arr, k - 1);
        
    }
};