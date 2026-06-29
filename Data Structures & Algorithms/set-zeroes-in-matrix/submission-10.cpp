class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> mkd (n+1 , vector<int>(m+1,-1));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0 && mkd[i][j]==-1){
                    for(int k=0;k<n;k++){
                        if(matrix[k][j]!=0){
                            mkd[k][j]=1;
                        }
                        matrix[k][j]=0;
                        
                    }
                    for(int l=0;l<m;l++){
                        if(matrix[i][l]!=0){
                            mkd[i][l]=1;
                        }
                        matrix[i][l]=0;
                    }
                }
            }
        }

        return;
    }
};
