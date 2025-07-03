class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int i= 0;
        int  n =  s.length();
        int j = 0;
        int maxi = 0; int cur = 0;
        unordered_set<char>st;
        vector<int> freq(26, 0);
        while(j  < n) {
            freq[s[j] - 'a']++;
            st.insert(s[j]);
            while(st.size() > k) {
                freq[s[i] - 'a']--;
                if(freq[s[i] - 'a'] == 0) st.erase(s[i]);
                i++;
            }
            if(st.size() == k) {
                maxi = max(maxi, j - i + 1);
            }
            j++;
        }
        
        return maxi == 0 ? -1 : maxi;
    }
};