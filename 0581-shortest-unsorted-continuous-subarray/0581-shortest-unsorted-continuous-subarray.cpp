class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>snums(nums.begin(),nums.end());
        sort(snums.begin(),snums.end());
        int start=snums.size();
        int end=0;
        for(int i=0; i<snums.size(); i++){
            if(snums[i]!=nums[i]){
                start=min(start,i);
                end=max(end,i);
            }
        }
       
        return end-start>=0?end-start+1:0;
    }
};