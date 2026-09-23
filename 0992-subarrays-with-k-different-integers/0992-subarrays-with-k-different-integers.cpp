class Solution {
public:
    int helper(vector<int>& nums,int k){
        
        int left=0;
        int right=0;
        int distinctEntry=0;
        int subarray=0;
        unordered_map<int,int>m;
       while(right<nums.size()){
        if(m[nums[right]]==0){
        distinctEntry++;
        }
        m[nums[right]]++;
        while(distinctEntry>k){
            m[nums[left]]--;
            if(m[nums[left]]==0){
               distinctEntry--;
            }
            left++;
            
        }
         subarray+=right-left+1;
         right++;
        
       }
       return subarray;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums,k)-helper(nums,k-1);
    }
};