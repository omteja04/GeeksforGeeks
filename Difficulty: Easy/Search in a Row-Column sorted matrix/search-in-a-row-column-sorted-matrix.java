//{ Driver Code Starts
import java.io.*;
import java.lang.*;
import java.util.*;

class gfg {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();
            int m = sc.nextInt();

            int mat[][] = new int[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) mat[i][j] = sc.nextInt();
            }

            int x = sc.nextInt();

            if (new Solution().matSearch(mat, x))
                System.out.println("true");
            else
                System.out.println("false");

            System.out.println("~");
        }
    }
}
// } Driver Code Ends


class Solution {
    public static boolean matSearch(int matrix[][], int target) {
        // your code here
        if(matrix == null || matrix.length < 1 || matrix[0].length <1) {
            return false;
        }
        int low = 0;
        int high = matrix[0].length - 1;
        while(low <= matrix.length - 1 && high  >= 0) {
            if(matrix[low][high] == target)  return true;
            else if(matrix[low][high] > target) {
                high--;
            } else {
                low++;
            }
        }
        return false;
    }
}