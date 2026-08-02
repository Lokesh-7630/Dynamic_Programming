class Solution {
public:
vector<int>drow={-1,0,1,0};
vector<int>dcol={0,1,0,-1};
void dfs(int row,int col,int m,int n,vector<vector<int>>& image,vector<vector<bool>>&vis,int color,int oldColor){
vis[row][col]=true;
image[row][col]=color;

for(int i=0; i<4; i++){
    int nrow=row+drow[i];
    int ncol=col+dcol[i];
   if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
    if(!vis[nrow][ncol] && image[nrow][ncol]==oldColor){
        dfs(nrow,ncol,m,n,image,vis,color,oldColor);
    }
   }



}
// if(row-1>=0 && !vis[row-1][col]&&image[row-1][col] == oldColor ){
//     dfs(row-1,col,m,n,image,vis,color,oldColor);
// }
//  if(row+1<n && !vis[row+1][col]&&image[row+1][col] == oldColor){
//        dfs(row+1,col,m,n,image,vis,color,oldColor);
// }
// if(col + 1 < m && !vis[row][col+1] && image[row][col+1] == oldColor){
//             dfs(row, col+1, m, n, image, vis, color, oldColor);
//         }
//         // Left
//         if(col - 1 >= 0 && !vis[row][col-1] && image[row][col-1] == oldColor){
//             dfs(row, col-1, m, n, image, vis, color, oldColor);
//         }
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image[0].size();
        int n=image.size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        dfs(sr,sc,m,n,image,vis,color,image[sr][sc]);
        return image;
    }
};