//{ Driver Code Starts
import java.util.*;
import java.lang.*;
import java.io.*;
class GFG
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while(T-->0)
        {
            String[] S1 = br.readLine().trim().split(" ");
            int n = Integer.parseInt(S1[0]);
            int m = Integer.parseInt(S1[1]);
            int[][] image =  new int[n][m];
            for(int i = 0; i < n; i++){
                String[] S2 = br.readLine().trim().split(" ");
                for(int j = 0; j < m; j++)
                    image[i][j] = Integer.parseInt(S2[j]);
            }
            String[] S3 = br.readLine().trim().split(" ");
            int sr = Integer.parseInt(S3[0]);
            int sc = Integer.parseInt(S3[1]);
            int newColor = Integer.parseInt(S3[2]);
            Solution obj = new Solution();
            int[][] ans = obj.floodFill(image, sr, sc, newColor);
            for(int i = 0; i < ans.length; i++){
                for(int j = 0; j < ans[i].length; j++)
                    System.out.print(ans[i][j] + " ");
                System.out.println();
            }
        }
    }
}

// } Driver Code Ends

class Solution {
    
    public static void dfs(int sr, int sc,int initialColor, int newColor, int[][] res, int[] dx, int[] dy, int[][] image) {
        int m = image.length;
        int n = image[0].length;
        res[sr][sc] = newColor;
        for(int i = 0; i < 4; i++) {
            int x = sr + dx[i];
            int y = sc + dy[i];
            if(x >= 0 && x < m && y >= 0 && y < n && image[x][y] == initialColor && res[x][y] != newColor) {
                dfs(x, y, initialColor, newColor, res, dx, dy, image);
            }
        }
    }
    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        // Code here 
        int initialColor = image[sr][sc];
        if (initialColor == newColor) {
            return image;
        }
        int[] dx = {-1, 0, 1, 0};
        int[] dy = {0, 1, 0, -1};
        int m = image.length;
        int n = image[0].length;
        
        Stack<int[]> st = new Stack<>();
        st.add(new int[]{sr, sc});
        
        while(!st.isEmpty()) {
            int[] pos = st.pop();
            int x = pos[0];
            int y = pos[1];
            image[x][y] = newColor;
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx >= 0 && nx < m && ny >= 0 && ny < n && image[nx][ny] == initialColor) {
                    st.push(new int[]{nx, ny});
                }
            }
        }
        
        return image;
    }
}



