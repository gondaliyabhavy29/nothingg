class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>time=grid;
        queue<pair<int,int>>q;
        int co=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(time[i][j]==2){
                    q.push({i,j});
                }
                else if(time[i][j]==1){
                     co++;
                }
            }
        }
        if(co==0)return 0;
        if(q.empty())return -1;
        int mi=-1;
        vector<pair<int, int>> dirs = {{1, 0},{-1, 0},{0, -1},{0, 1}};
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto [x,y]=q.front();
                q.pop();
                for(auto [dx,dy]:dirs){
                    int i=x+dx;
                    int j=y+dy;
                    if(i>=0&&j>=0&&i<n&&j<m&&time[i][j]==1){
                        co--;
                        time[i][j]=2;
                        q.push({i,j});
                    }
                }
            }
            mi++;
        }
        if(co==0)return mi;
        return -1;
    }
};