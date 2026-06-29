class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        vector<int> result;
        int n=nums.size();

        for(int i=0;i<n;i++){
            if(m.find(target-nums[i])!=m.end()){
                result.push_back(m[target-nums[i]]);
                result.push_back(i);
            }
            m[nums[i]]=i;
        }
        return result;
        
    }
};
