class disjoint{
   vector<int>rank,par;
   public:
   disjoint(int n){
    rank.resize(n,0);
    par.resize(n);

    for(int i=0; i<n; i++){
        par[i]=i;
    }
   }
   int findPar(int node){
    if(par[node]==node){
        return node;
    }else{
        return par[node]=findPar(par[node]);
    }
   }
   void unionByRank(int u,int v){
    int ultParU=findPar(u);
    int ultParV=findPar(v);
    if(rank[ultParU]>rank[ultParV]){
        par[ultParV]=ultParU;
    }else if(rank[ultParU]<rank[ultParV]){
         par[ultParU]=ultParV;

    }else{
        par[ultParV]=ultParU;
        rank[ultParU]++;

    }
   }


};
   
   
   
   
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<pair<int,pair<int,int>>>adj;
        if(connections.size()<n-1) return -1;
    
     disjoint ds(n);
     for(auto& edge:connections){
        ds.unionByRank(edge[0],edge[1]);
     }
     unordered_set<int>s;
     for(int i=0; i<n; i++){
        s.insert(ds.findPar(i));
     }
     return s.size() - 1;
    }
};