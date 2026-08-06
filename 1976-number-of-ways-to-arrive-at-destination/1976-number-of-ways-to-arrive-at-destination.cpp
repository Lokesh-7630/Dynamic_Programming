class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
       vector<vector<pair<int,int>>>adj(n);
       for(auto& edge:roads){
        adj[edge[0]].push_back({edge[1],edge[2]});
        adj[edge[1]].push_back({edge[0],edge[2]});
       }
       vector<long long >dist(n,LLONG_MAX);
       vector<long long >ways(n);
       priority_queue<
       pair<long long,int>,
       vector<pair<long long,int>>,
       greater<pair<long long,int>>>pq;
       pq.push({0,0}); //dist,src
       dist[0]=0;
       ways[0]=1;
       long long mod=(int)(1e9+7);
       while(!pq.empty()){
        
        long long d=pq.top().first;
        int node=pq.top().second;
         pq.pop();
       
         for(auto& it:adj[node]){
        int adjNode=it.first;
        long long w=it.second;
        if(dist[adjNode]>d+w){
           dist[adjNode]=d+w;
           ways[adjNode]=ways[node];
           pq.push({d+w,adjNode});
        }else if(dist[adjNode]==d+w){
           ways[adjNode]=(ways[node]+ways[adjNode])%mod;
        }
         }
       }
       return ways[n-1]%mod;

    }
};