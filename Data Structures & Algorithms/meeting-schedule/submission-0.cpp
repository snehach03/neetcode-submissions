/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        int n=intervals.size();
        vector<vector<int>> gp (n,vector<int>(2));
        for(int i=0;i<n;i++){
            gp[i][0]=intervals[i].start;
            gp[i][1]=intervals[i].end;
        }

        sort(gp.begin(), gp.end(), [](vector<int> & a , vector<int> & b){
            return a[0]<b[0];
        });

        int i=1;
        int end=gp[0][1];

        while(i<n){
            if(gp[i][0]<end){
                return false;
            }
            else{
                end=gp[i][1];
            }
            i++;
        }
        return true;
        
    }
};
