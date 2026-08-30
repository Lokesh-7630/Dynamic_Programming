class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int set=1<<nums.size();
        vector<vector<int>>power;
        
       for(int mask=0; mask<set; mask++){
        vector<int>list;
        for(int i=0; i<nums.size(); i++){
            if(mask&(1<<i)){
                list.push_back(nums[i]);
            }
        }
        power.push_back(list);
        
       }
       

        return power;
    }
};