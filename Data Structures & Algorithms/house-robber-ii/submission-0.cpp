class Solution {
public:
    int robLine(vector<int>& nums, int start, int end){
        int n = end - start + 1;
        if(n <= 0) return 0;

        vector<int> dp(n, 0);  

        for(int i = n - 1; i >= 0; i--){
            int pick = nums[start + i];
            if(i + 2 < n) pick += dp[i + 2];   // bounds check 

            int notPick = (i + 1 < n) ? dp[i + 1] : 0;

            dp[i] = max(pick, notPick);
        }

        return dp[0];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];   

        
        int caseA = robLine(nums, 0, n - 2);

       
        int caseB = robLine(nums, 1, n - 1);

        return max(caseA, caseB);
    }
};
