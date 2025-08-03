class Solution {
  public:
    vector<vector<int>> applyDiff2D(vector<vector<int>>& mat,
                                    vector<vector<int>>& opr) {
        // code here
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> diff (m, vector<int>(n, 0));
        for(int i = 0 ; i < opr.size(); i++) {
            int val = opr[i][0];
            int l1 = opr[i][1];
            int r1 = opr[i][2];
            int l2 = opr[i][3];
            int r2 = opr[i][4];
            for(int j = l1; j <= l2; j++) {
                diff[j][r1] += val;
                if(r2 + 1 < n) {
                    diff[j][r2 + 1] -= val;
                }
            }
        }
        for(int i = 0; i < m; i++) {
            int cost = 0;
            for(int j = 0; j < n; j++) {
                cost += diff[i][j];
                mat[i][j] += cost;
            }
        }
        return mat;
    }
};