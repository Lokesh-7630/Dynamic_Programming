class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int prev_max=0;
        int curr_max=0;
        for(int money:nums){
            int new_max=max(curr_max,prev_max+money);
            prev_max=curr_max;
            curr_max=new_max;
        }
    return curr_max;
    }
};