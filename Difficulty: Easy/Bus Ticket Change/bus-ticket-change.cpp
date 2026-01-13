class Solution {
  public:
    bool canServe(vector<int> &arr) {
        // code here
        int fives = 0, tens = 0;
        for(int &coin : arr) {
            if(coin == 5) fives++;
            else if(coin == 10) {
                if(fives >= 1) {
                    fives--;
                    tens++;
                } else {
                    return false;
                }
            } else {
                if(tens >= 1) {
                    tens--;
                    if(fives >= 1) {
                        fives--;
                    } else {
                        return false;
                    }
                } else {
                    if(fives >= 3) {
                        fives -= 3;
                    } else {
                        return false;
                    }
                }
            }
        }
        return true;
        
    }
};