class Solution {
public:
const int dx4[4] = {-1, 1, 0, 0};
const int dy4[4] = {0, 0, -1, 1};
bool isvalid(int x, int y, int r, int c) { return x >= 0 && x < r && y >= 0 && y < c; }
void bfs(int i,int j,vector<vector<char>>&b){
    if(b[i][j]=='O'){
        b[i][j]='0';
       for(int k=0;k<4;k++){
        int x=i+dx4[k];
        int y=j+dy4[k];
        if(isvalid(x,y,b.size(),b[0].size())){
            bfs(x,y,b);
        }

       }
       return;
    }
    return;
}
    void solve(vector<vector<char>>& b) {
        int n=b.size();
        int m=b[0].size();
        for(int i=0;i<n;i++){
           if(b[i][0]=='O'){
          
            bfs(i,0,b);
           }
        }
        for(int i=0;i<n;i++){
             if(b[i][m-1]=='O'){
            
            bfs(i,m-1,b);
           }
        }
        for(int i=0;i<m;i++){
           if(b[0][i]=='O'){
          
            bfs(0,i,b);
           }
        }
        for(int i=0;i<m;i++){
             if(b[n-1][i]=='O'){
           
            bfs(n-1,i,b);
           }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(b[i][j]=='0')b[i][j]='O';
                else b[i][j]='X';
            }
        }
    }
};