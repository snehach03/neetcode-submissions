class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();//row
        int n=matrix[0].size();//col
        set<int> sc;
        set<int> sr;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    sr.insert(i);
                    sc.insert(j);
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(sr.find(i)!=sr.end()){
                    matrix[i][j]=0;
                }
                if(sc.find(j)!=sc.end()){
                    matrix[i][j]=0;
                }
            }
        }

        
    }
};
