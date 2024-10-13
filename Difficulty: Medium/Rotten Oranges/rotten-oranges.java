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
            String[] s = br.readLine().trim().split(" ");
            int n = Integer.parseInt(s[0]);
            int m = Integer.parseInt(s[1]);
            int[][] grid = new int[n][m];
            for(int i = 0; i < n; i++){
                String[] S = br.readLine().trim().split(" ");
                for(int j = 0; j < m; j++){
                    grid[i][j] = Integer.parseInt(S[j]);
                }
            }
            Solution obj = new Solution();
            int ans = obj.orangesRotting(grid);
            System.out.println(ans);
        }
    }
}
// } Driver Code Ends


class Info {
    int row;
    int col;
    int time;
    Info(int row, int col, int time) {
        this.row = row;
        this.col = col;
        this.time = time;
    }
}
class Solution {
    public int orangesRotting(int[][] grid) {
        int m  = grid.length;
        int n = grid[0].length;
        Queue<Info> q = new LinkedList<>();
        int[][] vis = new int[m][n];
        int countFresh = 0;
        for(int i = 0 ; i < m; i++) {
            for(int j = 0 ; j < n; j++) {
                if(grid[i][j] == 2) {
                    q.add(new Info(i, j, 0));
                    vis[i][j] = 2;
                } else {
                    vis[i][j] = 0;
                }
                if(grid[i][j] == 1) countFresh++;
            }
        }
        int cnt = 0;
        int[] dx = {0, 0, 1, -1};
        int[] dy = {1, -1, 0, 0};
        int time = 0;
        while(!q.isEmpty()) {
            int r = q.peek().row;
            int c = q.peek().col;
            int t = q.peek().time;
            time = Integer.max(time, t);
            q.remove();
            for(int i = 0; i < 4; i++) {
                int x = r + dx[i];
                int y = c + dy[i];

                if(x >= 0 && x < m && y >= 0 && y < n && vis[x][y] != 2 && grid[x][y] == 1) {
                    q.add(new Info(x, y, t + 1));
                    vis[x][y] = 2;
                    cnt++;
                }
            }
        }
        return cnt == countFresh ? time : -1;

    }
}