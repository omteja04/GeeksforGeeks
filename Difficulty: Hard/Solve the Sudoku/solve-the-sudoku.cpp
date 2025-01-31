//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find a solved Sudoku.
    bool isValid(vector<vector<int>>& board, int row, int col, int ch) {
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == ch)
                return 0;
            if (board[row][i] == ch)
                return 0;
            if (board[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == ch)
                return 0;
        }
        return true;
    }
    bool rec(vector<vector<int>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == 0) {
                    for (int ch = 1; ch <= 9; ch++) {
                        if (isValid(board, i, j, ch)) {
                            board[i][j] = ch;
                            if (rec(board))
                                return true;
                            board[i][j] = 0;
                        }
                    }
                    return 0;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<int>> &mat) {
        // code here
        rec(mat);
    }
};

//{ Driver Code Starts.

vector<int> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    int num;
    vector<int> res;
    while (ss >> num) {
        res.push_back(num);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<vector<int>> grid;
        for (int i = 0; i < 9; i++) {
            vector<int> v = inputLine();
            grid.push_back(v);
        }

        Solution ob;

        ob.solveSudoku(grid);

        for (auto v : grid) {
            for (auto elem : v) {
                cout << elem << " ";
            }
            cout << endl;
        }

        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends