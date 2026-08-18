class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i=0;
        //nums=[1,2,0]=>  1->0,  2->1,  3->2
        while(i<nums.size()){
            if(nums[i]>0 && nums[i]<=nums.size() && nums[i]!=nums[nums[i]-1]){
                swap(nums[i],nums[nums[i]-1]);

            }else{
                i++;

            }
        } 
        for(int i=0; i<nums.size(); i++){
            if(nums[i]!=i+1){
                return i+1;
            }
        }
        return nums.size()+1;
    }
};