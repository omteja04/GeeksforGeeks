class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        // code here
        int left = 0;
        int zeros = 0;
        int len = 0;
        for(int r = 0; r < arr.size(); r++) {
            if(arr[r] == 0) zeros++;
            while(zeros > k) {
                if(arr[left] == 0) {
                    zeros--;
                }
                left++;
            }
            len = max(len, r - left + 1);
        }
        return len;
    }
};
