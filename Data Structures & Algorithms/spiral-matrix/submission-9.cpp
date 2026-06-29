class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        int srow=0;
        int erow=n;
        int scol=0;
        int ecol=m;
        vector<int> r;

        while(srow<erow && scol<ecol){
            for(int i=scol;i<ecol;i++){
                r.push_back(matrix[srow][i]);
            }
            srow++;
            for(int i=srow;i<erow;i++){
                r.push_back(matrix[i][ecol-1]);
            }
            ecol--;
            if(erow>srow){
            for(int i=ecol-1;i>=scol;i--){
                r.push_back(matrix[erow-1][i]);
            }
            }
            erow--;
            if(scol<ecol){
            for(int i=erow-1;i>=srow;i--){
                r.push_back(matrix[i][scol]);
            }
            scol++;
            }
        }
        return r;
        
    }
};
