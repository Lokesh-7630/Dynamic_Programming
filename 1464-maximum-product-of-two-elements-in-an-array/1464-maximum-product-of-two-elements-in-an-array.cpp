class Solution {
public:
    int maxi=INT_MIN;
    int maxi2=INT_MIN;
    int maxProduct(vector<int>& nums) {
     for(int x:nums){
        if(x>maxi){
            maxi2=maxi;
            maxi=x;
        }else if (x > maxi2) {
        maxi2 = x;
    }
     }
             return (maxi - 1) * (maxi2 - 1);
    }
};