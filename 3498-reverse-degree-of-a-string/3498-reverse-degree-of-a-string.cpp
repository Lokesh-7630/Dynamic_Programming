class Solution {
public:
    int reverseDegree(string s) {
    //     s[i]-'a'==>0
    //    mod( a-'a')=0-26
    //     b-'a'=1-26
    //     c-'a'=2-26
    //     .
    //     .
    //     z-'a'=25-26
    int total=0;
   for(int i=0; i<s.size(); i++){
    int index=26-(s[i]-'a');
    int pos=i+1;
    total+=pos*index;
   }
   return total;
    }
};