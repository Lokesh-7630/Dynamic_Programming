class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
       vector<vector<pair<int,int>>>adj(n+1);
       for(auto& edge:times){
        int u=edge[0];
        int v=edge[1];
        int w=edge[2];
        adj[u].push_back({v,w});
       }
       queue<pair<int,int>>q;//dist,u
       vector<int>time(n+1,INT_MAX);
       time[k]=0;
       q.push({0,k});
       while(!q.empty()){
        int u=q.front().second;
        
        q.pop();
        for(auto& it:adj[u]){
            int wt=it.second;
            int v=it.first;
            if(time[v] > time[u]+wt){
                time[v]=time[u]+wt;
                q.push({time[v],v});
            }
        }

       }
       int ans=INT_MIN;
       for(int i=1; i<=n; i++){
        if(time[i]==INT_MAX){
            return -1;
        }
        ans=max(ans,time[i]);
       }
       return ans;
       

    }
};