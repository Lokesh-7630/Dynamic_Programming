class Solution {
public:
    vector<string> createGrid(int m, int n) {
      vector<string>grid(m,string(n,'#'));
      for(int j=0; j<n; j++){
        grid[0][j]='.';
      }
       for(int j=0; j<m; j++){
        grid[j][n-1]='.';
      }
      return grid;
    }
};