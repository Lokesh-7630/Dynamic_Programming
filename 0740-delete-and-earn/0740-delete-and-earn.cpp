class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int,int>points;
        set<int>arr;
        for(int num:nums){
            points[num]+=num;
            arr.insert(num);
        }
        int prev1=0,prev2=0;
        int curr=-1;
        for(int earning:arr){
            int currPoints=points[earning];
            if(earning==curr+1){
                //adjacent
                int ans=max(prev1,prev2+currPoints);
                prev2=prev1;
                prev1=ans;
            }else{
                //not adjacent
                int ans=currPoints+prev1;
                 prev2=prev1;
                prev1=ans;
            }
            curr=earning;
        }
       
return prev1;
    }
};