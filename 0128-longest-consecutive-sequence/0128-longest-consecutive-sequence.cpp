class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       unordered_set<int>m(nums.begin(),nums.end());
       if(nums.size()==0)return 0;
       
       int maxi=INT_MIN;
       for(int x:m){
        if(!m.contains(x-1)){
            int count=1;
            int currentNum=x;
            while(m.contains(currentNum+1)){
                count++;
                currentNum++;
                
            }
            maxi=max(count,maxi);
        }
       }
       return maxi;

    }
};