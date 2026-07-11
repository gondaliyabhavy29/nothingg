class Solution {
public:
void dfs(int i,vector<vector<int>>&adj,int& v,int& e,vector<bool>& vis){
    v++;
    e+=adj[i].size();
    vis[i]=true;
    for(auto& s:adj[i]){
        if(!vis[s]){
            dfs(s,adj,v,e,vis);
        }
    }
}
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto e:edges){
            int v=e[0],u=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
       vector<bool>vis(n,false);
        int res=0;
        for(int i=0;i<n;i++){
            bool ok = vis[i];
            if(!ok){
                int v=0,e=0;
                dfs(i,adj,v,e,vis);
                res+= (e==v*(v-1));
            }
        }
        return res;
    }
};