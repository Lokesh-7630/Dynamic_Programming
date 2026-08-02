class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        queue<pair<int,int>>q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                if(i==0 || i==n-1 || j==0 || j==m-1){
                    if(grid[i][j]==1){
                    q.push({i,j});
                    vis[i][j]=true;
                }
                }
            }
        }
        vector<int>drow={-1,0,1,0};
        vector<int>dcol={0,1,0,-1};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];

            if(nrow>=0 && nrow+1<n && ncol>=0 && ncol+1<m && grid[nrow][ncol] ==1 && !vis[nrow][ncol]){
                   q.push({nrow,ncol});
                   vis[nrow][ncol]=true;
            }


            }
            
        }
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    ans++;
                }
            }
        }
        return ans;
    }
};