class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
      sort(nums.begin(),nums.end());
      int n=nums.size();
      vector<int>ans;

      for(int i=1; i<n; i++){
        if(nums[i]!=1+nums[i-1]){
            for(int j=1+nums[i-1]; j<nums[i]; j++)
         ans.push_back(j);

        }
      }
      return ans;
    }
};