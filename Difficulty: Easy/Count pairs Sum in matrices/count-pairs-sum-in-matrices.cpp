class Solution {
  public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
        // code here
        int n = mat1.size();
        int pairsCount=0;
	    int rows1=0;
	    int cols1=0;
	    int rows2=n-1;
	    int cols2=n-1;
	    while(rows1<n && cols1<n && rows2>=0&& cols2>=0){
	        if(mat1[rows1][cols1] + mat2[rows2][cols2] == x){
	            pairsCount++;
	            cols1++;
	            cols2--;
	            if(cols1>=n){
	                cols1=0;
	                rows1++;
	            }
	            if(cols2<0){
	                cols2=n-1;
	                rows2--;
	            }
	        }
	        else if(mat1[rows1][cols1] + mat2[rows2][cols2] > x){
	            cols2--;
	            if(cols2<0){
	                cols2=n-1;
	                rows2--;
	            }
	        }
	        else{
	            cols1++;
	            if(cols1>=n){
	                cols1=0;
	                rows1++;
	            }
	        }
	    }
	    return pairsCount;
        
    }
};