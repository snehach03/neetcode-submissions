class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int> freq;

        for(int i=0;i<n;i++){
            freq[nums[i]]++;      
        }

    vector<std::pair<int, int>> vec(freq.begin(), freq.end());

    // Step 3: Sort by frequency (second of pair) in descending order
    std::sort(vec.begin(), vec.end(), [](auto& a, auto& b) {
        return a.second > b.second;
    });

    // Step 4: Pick top k elements
    vector<int> result;
    for (int i = 0; i < k && i < vec.size(); ++i) {
        result.push_back(vec[i].first);
    }

    return result;
}
};
