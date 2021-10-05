class Solution {
    public int minDistance(String s, String sub) {
        if(s.equals(sub)==true)
            return 0;
        int m = s.length();
        int n = sub.length();
        
        if(m==0) return n;
        if(n==0) return m;
        
        int[][] dp = new int[m+1][n+1];
        
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0)
                    dp[i][j] = j;
                else if(j==0)
                    dp[i][j] = i;
                else if(s.charAt(i-1)==sub.charAt(j-1)){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 1 + Math.min(dp[i-1][j-1],Math.min(dp[i-1][j],dp[i][j-1]));
                }
            }
        }
        
        return dp[m][n];
    }
}