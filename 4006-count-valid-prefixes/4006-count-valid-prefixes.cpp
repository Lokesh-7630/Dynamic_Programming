class Solution {
public:
  
    int countValidPrefixes(string s) {
        int n=s.size();
         int validCount=0;
        int count1=0,count0=0;
        for(int i=0; i<n; i++){
            if(s[i]=='1'){
                count1++;
            }else{
                count0++;
            }
            if(abs(count1-count0)<=1){
           validCount++;
       }
        }
      
        return validCount;
    }
};