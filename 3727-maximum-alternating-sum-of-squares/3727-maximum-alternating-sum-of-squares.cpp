class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long sum=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<0){
                nums[i]=-nums[i];
            }
        }
        int n=nums.size();
        
         sort(nums.begin(),nums.end());
       for(int i=0; i<n; i++){
         long long square = 1LL * nums[i] * nums[i];
         if(i<n/2){
            sum-=square;
         }else{
            sum+=square;
         }

       }
       
        
        
        return sum;
    }
};