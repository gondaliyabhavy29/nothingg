class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int cnt=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               if(grid[i][j]==1){
                if(i+1>=m)cnt++;
                else if(grid[i+1][j]==0)cnt++;
                if(j+1>=n)cnt++;
                else if(grid[i][j+1]==0)cnt++;
                if(i-1<0)cnt++;
                else if(grid[i-1][j]==0)cnt++;
                if(j-1<0)cnt++;
                else if(grid[i][j-1]==0)cnt++;

               }
            }
        }
        return cnt;

    }
};