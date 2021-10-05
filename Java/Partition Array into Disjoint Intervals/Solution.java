class Solution {
    public int findmin(int[] nums, int i, int n){
        int ans=Integer.MAX_VALUE;
        for(int j=i;j<=n;j++)
            ans= Math.min(nums[j],ans);
        return ans;
    }
    
    public int partitionDisjoint(int[] nums) {
        int n = nums.length;
        int cmax=nums[0];
        int nowmax=nums[0];
        int ans_index = 0;
        
        for(int i=1;i<n;i++){
            nowmax = Math.max(nowmax, nums[i]);
            if(nums[i]<cmax){
                ans_index = i;
                cmax = nowmax;
            }
        }
        return ans_index+1;
    }
}