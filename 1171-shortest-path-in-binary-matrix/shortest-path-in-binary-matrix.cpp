class Solution {
public:
 bool correct(vector<vector<int>>& grid, vector<vector<bool>>& vis, int row, int col){
        int rows = grid.size();
        int cols = grid[0].size();

        if(row<0 || col < 0 || row>=rows || col>= cols || grid[row][col] == 1 || vis[row][col]) return false;
        return true;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(grid[0][0]==1)return -1;
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        vector<vector<int>> dis(n, vector<int>(m, -1));
        queue<pair<int,int>>q;
        q.push({0,0});
        vis[0][0]=true;
        dis[0][0]=1;
         vector<pair<int,int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {-1, -1}, {1, 1},{-1, 1}, {1, -1}};

        while(!q.empty()){
            auto [a,b]=q.front();
            q.pop();
            for(auto [i,j]:dirs){
                int nr=a+i;
                int nc=b+j;
                if(correct(grid,vis,nr,nc)){
                    vis[nr][nc]=true;
                    dis[nr][nc]=dis[a][b]+1;
                    q.push({nr,nc});
                }
            }
        }
        return dis[n-1][m-1];
    }
};