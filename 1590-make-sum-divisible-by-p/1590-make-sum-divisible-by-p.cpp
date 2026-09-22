class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long totalSum=0;
        int mini=INT_MAX;
       for(int i=0; i<nums.size(); i++){
        totalSum+=nums[i];

       }
       int target=totalSum%p;
       if(target==0){
        return 0;
       }
       unordered_map<int,int>m;
       m[0]=-1; //rem-->index
       long long currPrefix=0;
       for(int i=0; i<nums.size(); i++){
        currPrefix+=nums[i];
        int currRem=currPrefix%p;
       
       int neededRem=(currRem-target+p)%p;
       
       
       if(m.count(neededRem)){
         mini=min(mini,i-m[neededRem]);
       }
       m[currRem]=i;
       }
       return mini==nums.size()?-1:mini;

    }
};