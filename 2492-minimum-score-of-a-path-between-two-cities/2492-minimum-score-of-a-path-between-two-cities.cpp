class Solution {
public:
    void dfs(int src,int n,vector<vector<int>>& roads,vector<vector<pair<int,int>>>&adj,vector<bool>&vis,int &ans){
        
        vis[src]=true;
        for(auto& neighbour:adj[src]){
            int v=neighbour.first;
            int weight=neighbour.second;
             ans=min(ans,weight);
            if(!vis[v]){
               dfs(v,n,roads,adj,vis,ans);
            }
        }
       
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto& road:roads){
            adj[road[0]].push_back({road[1],road[2]}); //adj[1]<->v=2,dist=9
            adj[road[1]].push_back({road[0],road[2]}); //adj[2]<->v=2,dist=9
        }
         int ans=INT_MAX;
        vector<bool>vis(n+1,false);
        dfs(1,n,roads,adj,vis,ans);
        return ans;
    }
};