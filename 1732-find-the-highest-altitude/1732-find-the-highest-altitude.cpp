class Solution {
public:
 int largestAltitude(vector<int>& gain) {
    int maxi=INT_MIN;
    int ans=0;
 for(int i=0; i<gain.size(); i++ ){
    
  ans+=gain[i];
  maxi=max(ans,maxi);  
 }
    if(maxi<0){
        return 0;
    }else{
return maxi;
    }
    }
};
