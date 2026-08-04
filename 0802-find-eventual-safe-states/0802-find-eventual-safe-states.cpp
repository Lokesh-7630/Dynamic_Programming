class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
       vector<int>adjRev[V];
       vector<int>safeNodes;
       vector<int> indegree(V, 0);
       for(int i=0; i<V; i++){
        //i-->v
        //v-->i
         for(auto& v:graph[i]){
            adjRev[v].push_back(i);
           
         }
         indegree[i] = graph[i].size();
       }
       queue<int>q;
       for(int i=0; i<V; i++){
        if(indegree[i]==0){
            q.push(i);
        }
       }
       while(!q.empty()){
        int curr=q.front();
        safeNodes.push_back(curr);
        q.pop();
        for(auto& neighbour:adjRev[curr]){
            indegree[neighbour]--;
            if(indegree[neighbour]==0){
                q.push(neighbour);
            }
        }

               }
               sort(safeNodes.begin(),safeNodes.end());
               return safeNodes;
    }
};