class Solution {
public:
    
    int minimumTotal(vector<vector<int>>& triangle) {
       int n=triangle.size();
       vector<int>front(n,0);
       for(int j=0; j<n; j++){
        front[j]=triangle[n-1][j];
       }
       for(int i=n-2; i>=0; i--){
        vector<int>curr(n,0);
        for(int j=i; j>=0; j--){
            int down =front[j]+triangle[i][j];
            int diagonalDown =front[j+1]+triangle[i][j];
            curr[j]=min(down,diagonalDown);
        }
        front=curr;
       }
       return front[0];
    }
};