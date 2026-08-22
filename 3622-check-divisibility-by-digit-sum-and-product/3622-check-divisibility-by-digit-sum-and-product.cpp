class Solution {
public:
    bool checkDivisibility(int n) {
        int original=n;
        int val1=0;
        int val2=1;
       while(n>0){
        int dig=n%10;
        val1+=dig;
        val2*=dig;
        n/=10;
       }
       if(original%(val1+val2)==0){
        return true;
       }
       return false;
    }
};