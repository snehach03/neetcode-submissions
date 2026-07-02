class Solution {
public:
bool iscycle(vector<vector<int>>&adj , vector<int>&visited , int i){
    queue<pair<int,int>> q;
    q.push({0,-1});
    visited[0]=1;

    while(!q.empty()){
        auto x=q.front();
        q.pop();
        for(auto a :adj[x.first]){
            if(visited[a]==1 && a!=x.second){
                return false;
            }
            else if(visited[a]==0){
                q.push({a,x.first});
                visited[a]=1;
            }
        }   
    }

    return true;
}
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> visited(n);

        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }


        if(edges.size()!=n-1){
            return false;
        }

        bool a=iscycle(adj , visited , 0);

        if(a==false){
            return false;
        }

            \
    for(int i = 0; i < n; i++){
        if(visited[i] == 0) return false;   // for disconnected part yeh chcek krta hai 
        
    }

        return true;
    }
};
