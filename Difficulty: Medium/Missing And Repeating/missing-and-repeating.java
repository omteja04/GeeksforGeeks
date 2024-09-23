//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    // Driver code
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine().trim());
            String[] str = br.readLine().split(" ");

            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = Integer.parseInt(str[i]);
            }

            int[] ans = new Solve().findTwoElement(a);
            System.out.println(ans[0] + " " + ans[1]);
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solve {
    int[] findTwoElement(int arr[]) {
        // code here
        int[] result = new int[2]; 
        Map<Integer, Integer> count = new HashMap<>();

        
        for (int i : arr) {
            count.put(i, count.getOrDefault(i, 0) + 1);
        }

       
        for (int i = 1; i <= arr.length; i++) {
            if (!count.containsKey(i)) {
                result[1] = i;  
            } else if (count.get(i) == 2) {
                result[0] = i; 
            }
        }
        
        return result;
    }
}