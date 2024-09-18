//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        int n=x.size();
        stack<char>par;
        if(x[0]=='}' or x[0]==']' or x[0]==')') return false;
        for(int i=0;i<n;i++){
            if(x[i]=='{' or x[i]=='[' or x[i]=='(') par.push(x[i]);
            else if(!par.empty() and par.top()=='{' and x[i]=='}') par.pop();
            else if(!par.empty() and par.top()=='(' and x[i]==')') par.pop();
            else if(!par.empty() and par.top()=='[' and x[i]==']') par.pop();
            else return false;
        }
        if (par.empty()) return true;
        return false;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends