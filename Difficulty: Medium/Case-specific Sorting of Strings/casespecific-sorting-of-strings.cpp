class Solution {
  public:
    string caseSort(string& s) {
        // code here
        string upper, lower;
        for(auto ch : s) if(isupper(ch)) upper += ch; else lower+=ch;
        sort(upper.begin(), upper.end());
        sort(lower.begin(), lower.end());
        int i = 0, j = 0;
        for(auto &ch : s) {
            if(isupper(ch)) ch = upper[i++];
            else ch = lower[j++];
        }
        return s;
        
    }
};