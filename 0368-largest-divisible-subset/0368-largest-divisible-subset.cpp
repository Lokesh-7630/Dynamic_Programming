class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n,1);
        vector<int>parent(n,-1);
        int maxsize=1,maxIdx=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i]%nums[j]==0){
                if(dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                    parent[i]=j;
                   }
                }
            }
            if(dp[i]>maxsize){
                maxsize=dp[i];
                maxIdx=i;
            }
        }
        vector<int>result;
        int curr=maxIdx;
        while(curr!=-1){
          result.push_back(nums[curr]);
          curr=parent[curr];
        }
        reverse(result.begin(),result.end());
        return result;
    }
};