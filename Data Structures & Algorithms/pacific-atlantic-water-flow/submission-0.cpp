class Solution {
public:
    vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};

    void bfs(queue<pair<int,int>>& q, vector<vector<bool>>& visited, vector<vector<int>>& heights, int m, int n){
        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();
            for(auto& d : dirs){
                int nr = r + d[0];
                int nc = c + d[1];
                if(nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc] 
                   && heights[nr][nc] >= heights[r][c]){   // reverse-flow rule
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        queue<pair<int,int>> pq, aq;

        for(int c = 0; c < n; c++){ pacific[0][c] = true; pq.push({0, c}); }
        for(int r = 0; r < m; r++){ pacific[r][0] = true; pq.push({r, 0}); }

        for(int c = 0; c < n; c++){ atlantic[m-1][c] = true; aq.push({m-1, c}); }
        for(int r = 0; r < m; r++){ atlantic[r][n-1] = true; aq.push({r, n-1}); }

        bfs(pq, pacific, heights, m, n);
        bfs(aq, atlantic, heights, m, n);

        vector<vector<int>> result;
        for(int r = 0; r < m; r++){
            for(int c = 0; c < n; c++){
                if(pacific[r][c] && atlantic[r][c]){
                    result.push_back({r, c});
                }
            }
        }

        return result;
    }
};
