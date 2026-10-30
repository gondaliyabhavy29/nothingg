class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string la, int k) {
        vector<vector<pair<int,int>>>g(n);
        for(auto e:edges){
            g[e[0]].push_back({e[1],e[2]});
        }
         const long long INF = 4e18;
        int s=k+1;
        auto id=[&](int node,int cnt){
            return node*s+cnt;
        };
        long long ans=INF;
        vector<long long>dist(1LL*n*s,INF);
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        dist[id(0,1)]=0;
        pq.push({0,id(0,1)});
        while(!pq.empty()){
            auto [d,sta]=pq.top();
            pq.pop();
            if(d!=dist[sta])continue;
            int u=sta/s;
            int cnt=sta%s;
            for(auto [v,w]:g[u]){
                int nc=0;
                if(la[u]==la[v]){
                    nc=cnt+1;
                }
                else{
                    nc=1;
                }
                if(nc>k)continue;
                int nxt=id(v,nc);
                long long nd=d+w;
                if(nd<dist[nxt]){
                    dist[nxt]=nd;
                    pq.push({nd,nxt});
                }
                
            }
           for(int i=1;i<=k;i++){
            ans=min(ans,dist[id(n-1,cnt)]);
           }
        }
         
        
       
        if(ans==INF)return -1;
        return ans;
    }
};