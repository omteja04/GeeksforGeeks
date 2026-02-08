class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        // code here
        int minProd = arr[0];
        int maxProd = arr[0];
        int ans = arr[0];
        for(int i = 1; i < arr.size(); i++) {
            int tempMax = max({arr[i], minProd * arr[i], maxProd * arr[i]});
            int tempMin = min({arr[i], minProd * arr[i], maxProd * arr[i]});
            minProd = tempMin;
            maxProd = tempMax;
            ans = max(ans, maxProd);
        }
        return ans;
    }
};