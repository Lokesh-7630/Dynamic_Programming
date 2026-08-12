class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
      int left=0;
      int n=nums.size();
      int  maxLength=0;
      unordered_map<int,int>m;
      for(int right=0; right<n; right++){
        m[nums[right]]++;
        while(m[nums[right]]>k){
          m[nums[left]]--;
          left++;
        }
        
            maxLength=max(maxLength,right-left+1);
        
      }
      return maxLength;
    }
};