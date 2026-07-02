class Solution {
public:
void make(vector<int> & visited, vector<vector<int>> & adj , int i){
   queue<int> q;
   q.push(i);
   visited[i]=1;

   while(!q.empty()){
    int first =q.front();
    q.pop();
    for(auto x : adj[first]){
        if(visited[x]==0){
            q.push(x);
            visited[x]=1;
        }
    }
   } 
}

    int countComponents(int n, vector<vector<int>>& edges) {
        int a=edges.size();
        int b=edges[0].size();
        vector<vector<int>> adj(n);
        for(int i=0;i<a;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> visited(n,0);
       int count=0;

        for(int i=0;i<n;i++){
            if(visited[i]==0){
                 count++;
                make(visited , adj , i);
            }
        }

        return count;
    }
};
