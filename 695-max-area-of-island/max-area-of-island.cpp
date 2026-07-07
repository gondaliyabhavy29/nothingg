class Solution {
public:
int man=0;
void dfs(vector<vector<int>>& grid,int m,int n,int r,int c){
    if(r<0||c<0||r>=m||c>=n||grid[r][c]==0)return;
    man++;
    grid[r][c]=0;
     dfs(grid,m,n,r+1,c);
      dfs(grid,m,n,r-1,c);
       dfs(grid,m,n,r,c+1);
        dfs(grid,m,n,r,c-1);
}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int cnt=0;
       int m=grid.size();
       int n=grid[0].size();
       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1){
                dfs(grid,m,n,i,j);
                cnt=max(cnt,man);
                man=0;
            }
        }
       }
       return cnt;
    }
};