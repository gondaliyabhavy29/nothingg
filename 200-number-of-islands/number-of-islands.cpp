class Solution {
public:
void dfs(int m,int n,int r,int c,vector<vector<char>>& grid){
    if(r>=m||c>=n||r<0||c<0||grid[r][c]=='0'){
        return;
    }
    grid[r][c]='0';
    dfs(m,n,r+1,c,grid);
    dfs(m,n,r,c+1,grid);
    dfs(m,n,r-1,c,grid);
    dfs(m,n,r,c-1,grid);
   return;
}
    int numIslands(vector<vector<char>>& grid) {
        int cnt=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    dfs(m,n,i,j,grid);
                }
            }
        }
        return cnt;
    }
};