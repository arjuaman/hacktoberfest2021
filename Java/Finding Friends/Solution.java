import java.util.*;

public class Solution {
    static int cnt=0;
    public static void main(String[] args) {
        int[][] friends = { { 1, 1, 0 }, { 1, 1, 0 }, { 0, 0, 1 } };
        int rows = 3;
        int cols = 3;
        System.out.print("Friend groups are: "+helper(friends, rows, cols));
    }

    private static int helper(int[][] friends, int rows, int cols) {
        boolean[][] visited = new boolean[rows][cols];
        // int cnt=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(friends[i][j]==1 && visited[i][j]==false){
                    cnt++;
                    helper_util(friends,i, j, rows, cols, visited);
                }
            }
        }
        
        return cnt;
    }

    private static void helper_util(int[][] friends, int i, int j, int rows, int cols, boolean[][] visited) {
        if(i<0 || j<0 || i>=rows || j>=cols || visited[i][j]==true || friends[i][j]==0)
            return;
        
        visited[i][j]=true;
        // cnt++;
        helper_util(friends,i+1, j, rows, cols, visited);
        helper_util(friends,i-1, j, rows, cols, visited);
        helper_util(friends,i, j+1, rows, cols, visited);
        helper_util(friends,i, j-1, rows, cols, visited);

        // visited[i][j]=false;
    }
}