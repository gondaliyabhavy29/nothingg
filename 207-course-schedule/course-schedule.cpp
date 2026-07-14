class Solution {
public:
bool dfs(int node,const vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& path){
    vis[node]=true;
    path[node]=true;
    for(int ne:adj[node]){
        if(!vis[ne]){
            if(dfs(ne,adj,vis,path))return true;

        }
        else if(path[ne]){
            return true;
        }
    }
    path[node]=false;
    return false;
}
    bool canFinish(int n, vector<vector<int>>& pre){
        vector<vector<int>>adj(n);
        for(auto p:pre){
            adj[p[1]].push_back(p[0]);
        }
         vector<bool>vis(n,false);
        vector<bool>path(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,path))return false;
            }
        }
        return true;
    }
};