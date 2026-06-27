class Solution {
public:
    int climbStairs(int n) {
      vector<int>df(n+1,-1);
      df[0]=1;
      df[1]=1;
      for(int i=2; i<=n; i++){
        df[i]=df[i-1]+df[i-2];
        
      }
      return df[n];
    }
};