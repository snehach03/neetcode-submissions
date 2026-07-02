class Solution {
public:
int make(vector<int> & nums , int i,vector<int>&dp){
    if(i>=nums.size()){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }

    return dp[i]=max((nums[i]+make(nums,i+2 , dp)),make(nums , i+1 ,dp));
}
    int rob(vector<int>& nums) {
vector<int> dp(nums.size(),-1);
        int a=make(nums , 0 , dp);

        return a;  
    }
};
