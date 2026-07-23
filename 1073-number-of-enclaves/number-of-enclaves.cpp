class Solution {
public:
const int dx4[4] = {-1, 1, 0, 0};
const int dy4[4] = {0, 0, -1, 1};
bool isvalid(int x, int y, int r, int c) { return x >= 0 && x < r && y >= 0 && y < c; }
void bfs(int i,int j,vector<vector<int>>&g){
    if(g[i][j]==1){
        g[i][j]=0;
       for(int k=0;k<4;k++){
        int x=i+dx4[k];
        int y=j+dy4[k];
        if(isvalid(x,y,g.size(),g[0].size())){
            bfs(x,y,g);
        }

       }
       return;
    }
    return;
}
    int numEnclaves(vector<vector<int>>& g) {
        int cnt=0;
        int n=g.size();
        int m=g[0].size();
        for(int i=0;i<n;i++){
           if(g[i][0]==1){
          
            bfs(i,0,g);
           }
        }
        for(int i=0;i<n;i++){
             if(g[i][m-1]==1){
            
            bfs(i,m-1,g);
           }
        }
        for(int i=0;i<m;i++){
           if(g[0][i]==1){
          
            bfs(0,i,g);
           }
        }
        for(int i=0;i<m;i++){
             if(g[n-1][i]==1){
           
            bfs(n-1,i,g);
           }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j]==1)cnt++;
               
            }
        }
        return cnt;
    }
};