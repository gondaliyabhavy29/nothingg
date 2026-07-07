class Solution {
public:
void dfs(int r,int c,int m,int n, vector<vector<bool>>&vis,vector<vector<char>>&b){
    if(r>=m||c>=n)return;
    if(b[r][c]=='.')return;
    vis[r][c]=true;
    dfs(r,c+1,m,n,vis,b);
    dfs(r+1,c,m,n,vis,b);

}
    int countBattleships(vector<vector<char>>&b){
        int m=b.size();
        int n=b[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j]&&b[i][j]=='X'){
                    dfs(i,j,m,n,vis,b);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};