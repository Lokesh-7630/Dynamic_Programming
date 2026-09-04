class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int start =nums[0];
        int j=0;
        
        int maxi=start;
        while(j<nums.size()){
        
        maxi=max(maxi,nums[j]);
        int mini=INT_MAX;
        for(int k=j; k<nums.size(); k++){
         mini=min(mini,nums[k]);
        }
        int stabality=maxi-mini;
        if(stabality<=k){
            return j;
        }
        j++;
        }
        return -1;
    
        
    }
};