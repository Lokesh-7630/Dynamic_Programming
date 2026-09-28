class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 || (x%10 == 0 && x!= 0)){
            return false;
        }
        int reverseNo=0;
        while(x>reverseNo){
            reverseNo=reverseNo*10+x%10;
            x/=10;
        }
        return x==reverseNo||x==reverseNo/10;
    }
};