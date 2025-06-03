class Solution {
  public:
    long long int strcnt(string &s,int k){
        if(k==0) return 0;
        int ans=0,left=0,dist=0;
        
        vector<int>m(26,0);
        
        for(int i=0;i<s.size();i++){
            m[s[i]-'a']++;
            if(m[s[i]-'a']==1) dist++;
            while(dist>k){
                
                
                m[s[left]-'a']--;
                if(m[s[left]-'a']==0){
                    dist--;
                }
                left++;
                
            }
            ans+=(i-left+1);
        }
        return ans;
    }
    int countSubstr(string& s, int k) {
        // code here.
            	return strcnt(s,k)-strcnt(s,k-1);

    }
};