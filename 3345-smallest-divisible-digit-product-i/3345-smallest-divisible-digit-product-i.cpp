class Solution {
public:
    int smallestNumber(int n, int t) {
        int curr=n;
        
            while(true){
             int temp=curr;
             int product=1;
             while(temp>0){
           int digit=temp%10;
           product*=digit;
           temp/=10;
        }
        if(product%t==0){
            return curr;
        }
        curr++;
             }
        
      
    }
};