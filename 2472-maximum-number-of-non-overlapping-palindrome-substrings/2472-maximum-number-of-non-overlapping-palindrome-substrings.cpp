class Solution {
public:
    int maxPalindromes(string s, int k) {
       //mark all palindrome substrings of s[i...j]
       int n=s.size();
       if (n < k) return 0;
       vector<vector<bool>>isPal(n,vector<bool>(n,false));

       //only one char 
       for(int i=0; i<n; i++){
        isPal[i][i]=true;
       }
       for(int i=0; i<n-1; i++){
        if(s[i]==s[i+1]){
         isPal[i][i+1]=true;
        }
       }
       for(int len=3; len<=n; len++){
        for(int i=0; i<=n-len; i++){
            int j=i+len-1;
            if(s[i]==s[j] && isPal[i+1][j-1]){
             isPal[i][j]=true;
            }
        }
       }
       vector<int>dp(n+1,0);
       for(int i=1; i<=n; i++){
        //option 1
        dp[i]=dp[i-1];

        //option2
        if(i>=k && isPal[i-k][i-1]){
            dp[i]=max(dp[i],dp[i-k]+1);
        }
        if(i>=k+1 && isPal[i-k-1][i-1]){
            dp[i]=max(dp[i],dp[i-k-1]+1);
        }
       }
       return dp[n];

    }
};