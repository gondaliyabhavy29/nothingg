class Solution {
public:

typedef pair<int,pair<int,int>> P;
vector<vector<int>>dire{{-1,0},{1,0},{0,1},{0,-1}};
    int minimumEffortPath(vector<vector<int>>& h) {
        int m=h.size();
        int n=h[0].size();
        priority_queue<P,vector<P>,greater<P>>pq;
        vector<vector<int>>res(m,vector<int>(n,INT_MAX));

        auto issafe = [&](int r,int c){
            return (r>=0&&r<m&&c>=0&&c<n);
        };
        res[0][0]=0;
        pq.push({0,{0,0}});

        while(!pq.empty()){
            int diff=pq.top().first;
            auto cell=pq.top().second;
            pq.pop();
            int r=cell.first;
            int c=cell.second;
            if(r==m-1&&c==n-1){
                return diff;
            }
            for(auto d:dire){
                int i=r+d[0];
                int j=c+d[1];

                if(issafe(i,j)){
                    int abd=abs(h[r][c]-h[i][j]);
                    int ma=max(diff,abd);
                    if(res[i][j]>ma){
                        res[i][j]=ma;
                        pq.push({ma,{i,j}});
                    }
                }
            }
        }
        return res[m-1][n-1];
    }
};