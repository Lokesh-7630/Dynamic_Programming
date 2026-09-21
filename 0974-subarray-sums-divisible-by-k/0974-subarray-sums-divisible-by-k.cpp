class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int count=0;
        vector<int>prefixRem(k,0);
        prefixRem[0]=1;
        int runningPrefix=0;
        // k=prefix[r]-prefix[l-1];
      for(int num:nums){
        runningPrefix+=num;
        int rem=((runningPrefix%k)+k)%k;
        count+=prefixRem[rem];
        prefixRem[rem]++;

      }
        
        return count;

    }
};