class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
         vector<int>prefix(n,INT_MAX);      
         vector<int>suffix(n,INT_MAX);   
         int minileft=INT_MAX;   
         int left=0;
         int currSum=0;
         for(int right=0; right<n; right++){
            currSum += arr[right];
            while(currSum>target && left<=right){
                currSum -= arr[left];
                left++;
            }
            if(currSum==target){
                int len=right-left+1;
                 minileft=min(minileft,len);
            }
            prefix[right]=minileft;
         }
         int rightPtr=n-1;
          currSum=0;
         int miniright=INT_MAX;
         for(int leftPtr=n-1; leftPtr>=0; leftPtr--){
          currSum += arr[leftPtr];
            while(currSum>target && rightPtr>=leftPtr ){
                currSum -= arr[rightPtr];
                rightPtr--;
            }
            if(currSum==target){
                int len=rightPtr-leftPtr+1;
                 miniright=min(miniright,len);
            }
            suffix[leftPtr]=miniright;
         }
         int ans=INT_MAX;
         for(int i=0; i<n-1; i++){
    if(prefix[i]!=INT_MAX && suffix[i+1]!=INT_MAX){
    ans=min(ans,prefix[i]+suffix[i+1]);
    }
         }
return (ans >= INT_MAX) ? -1 : ans;    }
};