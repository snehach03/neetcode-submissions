class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        int count=0;
        vector<vector<int>> gp (n,vector<int>(2));
        for(int i=0;i<n;i++){
            gp[i][0]=intervals[i][0];
            gp[i][1]=intervals[i][1];
        }

        sort(gp.begin(), gp.end(), [](vector<int> & a , vector<int> & b){
           return a[1]<b[1];
        });

        int i=1;
        int end=gp[0][1];

        while(i<n){
            if(gp[i][0]<end){
                count++;
            }
            else{
                end=gp[i][1];
            }
            i++;
        }
        return count;
    }
};
