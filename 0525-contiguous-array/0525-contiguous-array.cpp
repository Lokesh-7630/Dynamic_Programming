class Solution {
public:
    int findMaxLength(vector<int>& nums) {
     
        for(int i=0; i<nums.size(); i++){
            
            if(nums[i]==0){
                nums[i]=-1;
            }else{
                nums[i]=1;
            }
        }

        unordered_map<int,int>m;
        m[0]=-1;
        int runningSum=0;
        int maxi=0;
        for(int i=0; i<nums.size(); i++){
            runningSum+=nums[i];
            if(m.count(runningSum)){
                
                maxi=max(maxi,i-m[runningSum]);
            }else{
                m[runningSum]=i;
            }
        }
        return maxi;
    }
};