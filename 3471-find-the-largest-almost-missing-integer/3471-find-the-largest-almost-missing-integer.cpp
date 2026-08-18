class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int maxi=-1;
        unordered_map<int,int>m;
        for(int num:nums){
            m[num]++;
        }
    if(k==nums.size()){
     for(int i=0; i<nums.size(); i++){
         maxi=max(maxi,nums[i]);
     }
     return maxi;
    }
    if(k==1){
         for(int i=0; i<nums.size(); i++){
          if(m[nums[i]]==1){
             maxi=max(maxi,nums[i]);
          }

         }
         return maxi;
    }
    //check first elemnt
    if(m[nums[0]]==1){
    maxi=max(maxi,nums[0]);
    
    }
    if(m[nums[nums.size()-1]]==1){
   maxi=max(maxi,nums[nums.size()-1]);
    }
 return maxi;

        
    }
};