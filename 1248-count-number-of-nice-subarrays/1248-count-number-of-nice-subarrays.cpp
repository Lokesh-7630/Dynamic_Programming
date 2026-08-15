class Solution {
public:
int helper(vector<int>& nums, int k){
    for(int i=0; i<nums.size(); i++){
            if(nums[i]%2!=0){
                nums[i]=1;
            }else{
                nums[i]=0;
            }
        }
         int right=0,left=0,sum=0;
    
       int count=0;
       while(right<nums.size()){
        sum+=nums[right];
        
        while(sum>k){
            sum-=nums[left];
            left++;
            
        }
        count=(right-left+1)+count;
        right++;
       } 
       return count;
}
    int numberOfSubarrays(vector<int>& nums, int k) {
        return helper(nums,k)-helper(nums,k-1);
    }
};