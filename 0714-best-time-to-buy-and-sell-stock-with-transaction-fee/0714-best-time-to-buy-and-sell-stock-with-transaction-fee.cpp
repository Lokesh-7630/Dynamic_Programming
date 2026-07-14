class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
     
        vector<int>prev(2,0);
        vector<int>curr(2,0);
        for(int i=n-1; i>=0; i--){
            for(int buy=0; buy<=1; buy++){
                if(buy==1){
                     curr[buy]=max(-prices[i]+prev[0],prev[1]);
                }else{
                     curr[buy]=max(prices[i]-fee +prev[1],prev[0]);
                }
            }
            swap(prev,curr);
        }
        return prev[1];
    }
};