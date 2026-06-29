class Solution {
public:
    vector<int> countBits(int n) {
        int a=0;
        vector<int> ans;

        for(int i =0;i<=n;i++){
            a=i^0;
            int digit=0;

            while(a!=0){
            digit=digit+(a&1);
                a>>=1;
            }
            ans.push_back(digit);
        }
        return ans;
    }
};
