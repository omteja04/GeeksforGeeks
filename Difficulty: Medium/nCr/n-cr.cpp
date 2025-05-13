//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    const int MOD = 1e9+7;
    const int MAX = 1001;
    vector<long long> fact;
    vector<long long> invFact;
  public:
    Solution() {
        fact.resize(MAX, 1);
        invFact.resize(MAX, 1);
        init();
    }
    
    long long power(long long base, long long exp, long long mod) {
        long long res = 1;
        while(exp > 0) {
            if(exp & 1) {
               res = (res * base) % mod;
            }
            base = (base * base) % mod;
            exp >>= 1;
        }
        return res;
    }
    void init() {
        for(int i = 2; i < MAX; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }
        invFact[1000] = power(fact[1000], MOD - 2, MOD);
        for(int i = 999; i >= 1; i--) {
            invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
        }
    }
    int nCr(int n, int r) {
        if(n < r) return 0;
        return (fact[n] * invFact[r] % MOD * invFact[n - r] % MOD) % MOD;    
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, r;
        cin >> n >> r;

        Solution ob;
        cout << ob.nCr(n, r) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends