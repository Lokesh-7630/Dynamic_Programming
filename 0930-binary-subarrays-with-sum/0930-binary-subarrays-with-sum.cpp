class Solution {
public:
int numSubarraysWithSumhelper(vector<int>& nums,int goal){
    int right=0,left=0,sum=0;
    if (goal < 0) return 0;
       int count=0;
       while(right<nums.size()){
        sum+=nums[right];
        
        while(sum>goal){
            sum-=nums[left];
            left++;
            
        }
        count=(right-left+1)+count;
        right++;
       } 
       return count;
}
    int numSubarraysWithSum(vector<int>& nums, int goal) {
      
       return numSubarraysWithSumhelper(nums,goal)-numSubarraysWithSumhelper(nums,goal-1);
    }
};