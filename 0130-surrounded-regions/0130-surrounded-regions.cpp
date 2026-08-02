class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        queue<pair<int,int>>q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==0 || i==n-1 || j==0 || j==m-1){
                if(board[i][j]=='O'){
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
  
          if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && board[nrow][ncol]=='O'){
               vis[nrow][ncol]=true;
               q.push({nrow,ncol});
          }

        }

        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]=='O' && !vis[i][j]){
                  board[i][j]='X';
                }
            }
        }
    }
};