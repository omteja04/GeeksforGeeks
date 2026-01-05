class Solution {
  public:
    int maxSubarraySum(vector<int>& Arr, int K) {
        // code here
        int N = Arr.size();
        long currsum=0,maxsum=INT_MIN;
        int i=0,j=0;
        while(j!=K){
            currsum+=Arr[j];
            j++;
        }
        maxsum=currsum;
        while(j!=N){
            currsum+=Arr[j];
            currsum-=Arr[i];
            j++;
            i++;
            maxsum=max(currsum,maxsum);
            
        }
        return maxsum;
    }
};