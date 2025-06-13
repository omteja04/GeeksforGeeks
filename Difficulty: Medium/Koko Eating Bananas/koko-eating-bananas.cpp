class Solution {
  public:
  int can_koko(vector<int>& piles,int mid){
        
        int hours=0;
        for(int i:piles){
                hours+=ceil((double)i/(double)mid);
                
         
        }
        return hours;
        
    }
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        int maxi = INT_MIN;
        
        for (auto &it: arr){
            if (it>maxi){
                maxi = it;
            }
        }
        int low=1;
        int high=maxi;
        int hours,ans=-1;
        while(low<=high){
            
            int mid=low+(high-low)/2;
            hours=can_koko(arr,mid);
            if(hours<=k){ 
                // ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
                
            }
            
            
        }
        return low;
    }
};