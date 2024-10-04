//{ Driver Code Starts
// An efficient C++ program to compute 
// sum of bitwise OR of all pairs
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
    public:
    // Returns sum of bitwise OR
    // of all pairs
    long long int sumXOR(int arr[], int n)
    {
    	//Complete the function
    	vector<int> v(32,0);
    	for (int i=0; i<n; i++){
    	    for (int j=0; j<32; j++){
    	        if (1&(arr[i]>>j)) v[j]++;
    	    }
    	}
    	long long res = 0;
    	for (int i=0; i<32; i++){
    	    int a = v[i];
    	    int b = n-v[i];
    	    res += 1LL*a*b*(1<<i);
    	}
    	return res;
    }
};

//{ Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	 int n ;
	 cin>>n;
	 int arr[n+1];
	 for( int i=0;i<n;i++)
	    cin>>arr[i];
	 Solution ob;
	 cout<<ob.sumXOR(arr, n)<<endl;
	}	
	return 0;
}

// } Driver Code Ends