class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count=0;
        int num=start^goal;
       for(int i=0; i<32; i++){
        count+=(num&1);
        num=num>>1;
       }
       return count;
    }
};